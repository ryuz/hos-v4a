/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scidrv.c
 * @brief %jp{SCI用デバイスドライバ}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "scidrv.h"


static void SciDrv_IsrRecvErr(VPARAM Param);		/* 受信エラー割り込み */
static void SciDrv_IsrRecv(VPARAM Param);			/* 受信割り込み */
static void SciDrv_IsrSend(VPARAM Param);			/* 送信エンプティー */
static void SciDrv_IsrSendEnd(VPARAM Param);		/* 送信終了 */


/** コンストラクタ */
void SciDrv_Create(C_SCIDRV *self, void *pRegAddr, int iIntNum, long lSysClock, int iBufSize)
{
	void *pMem;

	self->iOpenCount = 0;

	/* SciHal 初期化 */
	SciHal_Create(&self->SciHal, pRegAddr, lSysClock);

	/* バッファ確保 */
	pMem = SysMem_Alloc(iBufSize);
	StreamBuf_Create(&self->StmBuf, iBufSize, pMem);

	/* イベント生成 */
	self->hEvtRecv = SysEvt_Create();
	self->hEvtSend = SysEvt_Create();

	/* ミューテックス生成 */
	self->hMtxSend = SysMtx_Create();
	self->hMtxRecv = SysMtx_Create();

	/* 割り込み処理登録 */
	SysIsr_Create(iIntNum + 0, SciDrv_IsrRecvErr, (VPARAM)self);
	SysIsr_Create(iIntNum + 1, SciDrv_IsrRecv,    (VPARAM)self);
	SysIsr_Create(iIntNum + 2, SciDrv_IsrSend,    (VPARAM)self);
	SysIsr_Create(iIntNum + 3, SciDrv_IsrSendEnd, (VPARAM)self);
}


/** デストラクタ */
void SciDrv_Delete(C_SCIDRV *self)
{
	void *pMem;

	/* 同期オブジェクト削除 */
	SysEvt_Delete(self->hEvtRecv);
	SysEvt_Delete(self->hEvtSend);
	SysMtx_Delete(self->hMtxRecv);
	SysMtx_Delete(self->hMtxSend);

	/* バッファ削除 */
	pMem = StreamBuf_RefBufAddr(&self->StmBuf);
	StreamBuf_Delete(&self->StmBuf);
	SysMem_Free(pMem);
}


/** オープン */
void SciDrv_Open(C_SCIDRV *self)
{
	if ( self->iOpenCount++ == 0 )
	{
		SciHal_Setup(&self->SciHal, 38400);
		SciHal_EnableInterrupt(&self->SciHal, SCIHAL_INT_RIE);
	}
}

/** クローズ */
void SciDrv_Close(C_SCIDRV *self)
{
	if ( --self->iOpenCount == 0 )
	{
		SciHal_EnableInterrupt(&self->SciHal, 0);
		SciHal_Stop(&self->SciHal);
		StreamBuf_ClearBuf(&self->StmBuf);
	}
}

/** %jp{受信} */
int SciDrv_Read(C_SCIDRV *self, void *pRecvBuf, int iSize)
{
	unsigned char *pubBuf;
	int c;
	int i;

	pubBuf = (unsigned char *)pRecvBuf;

	SysMtx_Lock(self->hMtxRecv);

	for ( i = 0; i < iSize; i++ )
	{
		while ( (c = StreamBuf_RecvChar(&self->StmBuf)) < 0 )
		{
			/* 受信イベントを待つ */
			SysEvt_Wait(self->hEvtRecv);
			SysEvt_Clear(self->hEvtRecv);
		}
		*pubBuf++ = (unsigned char)c;
	}

	SysMtx_Unlock(self->hMtxRecv);

	return iSize;
}


/** %jp{送信} */
int SciDrv_Write(C_SCIDRV *self, const void *pData, int iSize)
{
	const unsigned char *pubBuf;
	int c;
	int i;

	pubBuf = (const unsigned char *)pData;

	SysMtx_Lock(self->hMtxSend);

	for ( i = 0; i < iSize; i++ )
	{
		c = *pubBuf++;
		while ( SciHal_SendChar(&self->SciHal, c) < 0 )
		{
			/* 送信割り込みを待つ */
			SciHal_EnableInterrupt(&self->SciHal, SCIHAL_INT_TIE | SCIHAL_INT_RIE);
			SysEvt_Wait(self->hEvtSend);
			SysEvt_Clear(self->hEvtSend);
		}
	}

	SysMtx_Unlock(self->hMtxSend);

	return iSize;
}


/* 受信エラー割り込み */
void SciDrv_IsrRecvErr(VPARAM Param)
{
	C_SCIDRV *self;
	int c;
	
	self = (C_SCIDRV *)Param;
	
	while ( (c = SciHal_RecvChar(&self->SciHal)) >= 0 )
	{
		StreamBuf_SendChar(&self->StmBuf, c);
	}
	SysEvt_Set(self->hEvtRecv);
}

/* 受信割り込み */
void SciDrv_IsrRecv(VPARAM Param)
{
	C_SCIDRV *self;
	int c;
	
	self = (C_SCIDRV *)Param;
	
	while ( (c = SciHal_RecvChar(&self->SciHal)) >= 0 )
	{
		StreamBuf_SendChar(&self->StmBuf, c);
	}
	SysEvt_Set(self->hEvtRecv);
}


/* 送信エンプティー */
void SciDrv_IsrSend(VPARAM Param)
{
	C_SCIDRV *self;

	self = (C_SCIDRV *)Param;
	
	SciHal_EnableInterrupt(&self->SciHal, SCIHAL_INT_RIE);
	SysEvt_Set(self->hEvtSend);
}


/* 送信終了 */
void SciDrv_IsrSendEnd(VPARAM Param)
{
	C_SCIDRV *self;

	self = (C_SCIDRV *)Param;
	
	SysEvt_Set(self->hEvtSend);
}


/* end of file */

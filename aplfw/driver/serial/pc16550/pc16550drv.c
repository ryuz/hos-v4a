/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scidrv.c
 * @brief %jp{PC16550用デバイスドライバ}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "pc16550drv.h"


/** コンストラクタ */
void Pc16550Drv_Create(C_PC16550DRV *self, void *pRegAddr,  unsigned int uiRegStep, int iIntNum, long lSysClock, int iBufSize)
{
	void *pMem;
	
	self->iOpenCount = 0;
	
	/* Pc16550Hal 初期化 */
	Pc16550Hal_Create(&self->Pc16550Hal, pRegAddr, uiRegStep, lSysClock);

	/* バッファ確保 */
	pMem = SysMem_Alloc(iBufSize);
	StreamBuf_Create(&self->StmBufRecv, iBufSize, pMem);

	/* イベント生成 */
	self->hEvtRecv = SysEvt_Create();
	self->hEvtSend = SysEvt_Create();

	/* ミューテックス生成 */
	self->hMtxSend = SysMtx_Create();
	self->hMtxRecv = SysMtx_Create();

	/* 割込み処理登録 */
	self->iIntNum = iIntNum;
	SysIsr_Create(iIntNum, Pc16550Drv_Isr, (VPARAM)self);
}


/** デストラクタ */
void Pc16550Drv_Delete(C_PC16550DRV *self)
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
void Pc16550Drv_Open(C_PC16550DRV *self)
{
	if ( self->iOpenCount++ == 0 )
	{
		Pc16550Hal_Setup(&self->Pc16550Hal);
		Pc16550Hal_SetSpeed(&self->Pc16550Hal, 38400);
		Pc16550Hal_EnableInterrupt(&self->Pc16550Hal, PC16550HAL_IER_ERBFI);
		SysInt_Enable(self->iIntNum);
	}
}

/** クローズ */
void Pc16550Drv_Close(C_PC16550DRV *self)
{
	if ( --self->iOpenCount == 0 )
	{
		SysInt_Disable(self->iIntNum);
		Pc16550Hal_EnableInterrupt(&self->Pc16550Hal, 0);
		Pc16550Hal_Stop(&self->Pc16550Hal);
		StreamBuf_ClearBuf(&self->StmBuf);
	}
}

/** %jp{受信} */
int Pc16550Drv_Read(C_PC16550DRV *self, void *pRecvBuf, int iSize)
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
int Pc16550Drv_Write(C_PC16550DRV *self, const void *pData, int iSize)
{
	const unsigned char *pubBuf;
	int c;
	int i;

	pubBuf = (const unsigned char *)pData;

	SysMtx_Lock(self->hMtxSend);

	for ( i = 0; i < iSize; i++ )
	{
		c = *pubBuf++;
		while ( Pc16550Hal_SendChar(&self->Pc16550Hal, c) < 0 )
		{
			/* 送信割り込みを待つ */
			Pc16550Hal_EnableInterrupt(&self->Pc16550Hal, PC16550HAL_IER_ERBFI | PC16550HAL_IER_ETBEI);
			SysEvt_Wait(self->hEvtSend);
			SysEvt_Clear(self->hEvtSend);
		}
	}

	SysMtx_Unlock(self->hMtxSend);

	return iSize;
}



/* 受信割り込み */
void Pc16550Drv_Isr(VPARAM Param)
{
	C_PC16550DRV *self;
	int c;
	
	self = (C_PC16550DRV *)Param;
	
	/* 受信 */
	while ( (c = Pc16550Hal_RecvChar(&self->Pc16550Hal)) >= 0 )
	{
		StreamBuf_SendChar(&self->StmBuf, c);
		SysEvt_Set(self->hEvtRecv);
	}

	/* 送信 */
	if ( Pc16550Hal_GetStatus(&self->Pc16550Hal) & PC16550HAL_LSR_THRE )
	{
		Pc16550Hal_EnableInterrupt(&self->Pc16550Hal, PC16550HAL_IER_ERBFI);
		SysEvt_Set(self->hEvtSend);
	}

#if 0
	int iIntStatus;

	/* 割込み状態の取得 */
	iIntStatus = Pc16550Hal_GetInterruptStatus(&self->Pc16550Hal);
	switch ( iIntStatus )
	{
	case PC16550HAL_IIR_RDA:
	case PC16550HAL_IIR_CTI:
		while ( (c = Pc16550Hal_RecvChar(&self->Pc16550Hal)) >= 0 )
		{
			StreamBuf_SendChar(&self->StmBuf, c);
		}
		SysEvt_Set(self->hEvtRecv);
		break;

	case PC16550HAL_IIR_THRE:
		Pc16550Hal_EnableInterrupt(&self->Pc16550Hal, PC16550HAL_IER_ERBFI);
		SysEvt_Set(self->hEvtSend);
	}
#endif
	
	SysInt_Clear(self->iIntNum);
}


/* end of file */

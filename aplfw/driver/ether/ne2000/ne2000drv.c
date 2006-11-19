/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  ne2000drv.c
 * @brief %jp{NE2000互換Ether用デバイスドライバ}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "ne2000drv.h"


static void Ne2000Drv_Isr(VPARAM Param);		/* 割り込み処理 */


/** コンストラクタ */
void Ne2000Drv_Create(C_NE2000DRV *self, void *pRegAddr, int iIntNum)
{
	/* オープンカウンタクリア */
	self->iOpenCount = 0;

	/* Ne2000Hal 初期化 */
	Ne2000Hal_Create(&self->Ne2000Hal, pRegAddr);

	/* イベント生成 */
	self->hEvtRecv = SysEvt_Create();
	self->hEvtSend = SysEvt_Create();

	/* ミューテックス生成 */
	self->hMtx = SysMtx_Create();

	/* 割り込み処理登録 */
	SysIsr_Create(iIntNum, Ne2000Drv_Isr, (VPARAM)self);
}


/** デストラクタ */
void Ne2000Drv_Delete(C_NE2000DRV *self)
{
	SysEvt_Delete(self->hEvtRecv);
	SysEvt_Delete(self->hEvtSend);
	SysMtx_Delete(self->hMtx);
}


/** オープン */
void Ne2000Drv_Open(C_NE2000DRV *self)
{
	System_Lock();
	if ( self->iOpenCount++ == 0 )
	{
		Ne2000Hal_Setup(&self->Ne2000Hal);
	}
	System_Unlock();
}


/** クローズ */
void Ne2000Drv_Close(C_NE2000DRV *self)
{
	System_Lock();
	if ( --self->iOpenCount == 0 )
	{
		Ne2000Hal_Stop(&self->Ne2000Hal);
	}
	System_Unlock();
}


/** %jp{受信} */
int Ne2000Drv_Read(C_NE2000DRV *self, void *pRecvBuf, int iSize)
{
	unsigned char *pubBuf;
	int iRecvSize = 0;

	pubBuf = (unsigned char *)pRecvBuf;

	for ( ; ; )
	{
		SysMtx_Lock(self->hMtx);
		iRecvSize = Ne2000Hal_Recv(&self->Ne2000Hal, pRecvBuf, iSize);
		SysMtx_Unlock(self->hMtx);

		if ( iRecvSize > 0 )
		{
			break;
		}

		/* 受信イベントを待つ */
		SysEvt_Wait(self->hEvtRecv);
		SysEvt_Clear(self->hEvtRecv);
	}
	
	return iRecvSize;
}


/** %jp{送信} */
int Ne2000Drv_Write(C_NE2000DRV *self, const void *pData, int iSize)
{
	SysMtx_Lock(self->hMtx);
	iSize = Ne2000Hal_Send(&self->Ne2000Hal, pData, iSize);
	SysMtx_Unlock(self->hMtx);
	
	return iSize;
}


/* 割り込み処理 */
void Ne2000Drv_Isr(VPARAM Param)
{
	C_NE2000DRV *self;

	self = (C_NE2000DRV *)Param;
}


/* end of file */

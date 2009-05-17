/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scidrv.c
 * @brief %jp{SCI用デバイスドライバ}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "scidrv_local.h"



/* 受信エラー割込み */
void SciDrv_IsrRecvErr(VPARAM Param)
{
	SciDrv_IsrRecv(Param);
}


/* 受信割込み */
void SciDrv_IsrRecv(VPARAM Param)
{
	C_SCIDRV *self;
	int c;
	
	self = (C_SCIDRV *)Param;
	
	while ( (c = SciHal_RecvChar(&self->SciHal)) >= 0 )
	{
		StreamBuf_SendChar(&self->StmBufRecv, c);
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

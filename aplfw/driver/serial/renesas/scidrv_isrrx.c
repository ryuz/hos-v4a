/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scidrv.c
 * @brief %jp{Renesas H8/SH用 SCIデバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "scidrv_local.h"



/* 受信割込み */
void SciDrv_IsrRx(VPARAM Param)
{
	C_SCIDRV *self;
	int c;
	
	self = (C_SCIDRV *)Param;
	
	/* 受信 */
	while ( (c = SciHal_RecvChar(&self->SciHal)) >= 0 )
	{
		StreamBuf_SendChar(&self->StmBufRecv, c);
	}
	
	/* 読込みシグナルを発生 */
	SyncDrv_SendSignal(&self->SyncDrv, SYNCDRV_FACTOR_READ);
}


/* end of file */

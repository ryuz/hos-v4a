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



/* 送信エンプティー */
void SciDrv_IsrTx(VPARAM Param)
{
	C_SCIDRV *self;
	
	self = (C_SCIDRV *)Param;
	
	/* 送信割込み禁止 */
	SciHal_EnableInterrupt(&self->SciHal, SCIHAL_INT_RIE);
	
	/* 書込みシグナルを発生 */
	SyncDrv_SendSignal(&self->SyncDrv, SYNCDRV_FACTOR_WRITE);
}


/* end of file */

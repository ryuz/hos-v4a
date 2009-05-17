/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  mn103scdrv_isr.c
 * @brief %jp{MN103シリーズ シリアルインターフェース用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "mn103scdrv_local.h"


/* 送信割込み */
void Mn103ScDrv_IsrTx(VPARAM Param)
{
	C_MN103SCDRV	*self;
	
	self = (C_MN103SCDRV *)Param;
	
	/* 割込み要因クリア */
	SysInt_Clear(self->iIntNumTx);
	
	/* 送信割込みを禁止 */
	SysInt_Disable(self->iIntNumTx);

	/* 書込みシグナルを発生 */
	SyncDrv_SendSignal(&self->SyncDrv, SYNCDRV_FACTOR_WRITE);	
}


/* end of file */

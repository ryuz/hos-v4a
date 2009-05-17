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


/* 受信割込み */
void Mn103ScDrv_IsrRx(VPARAM Param)
{
	C_MN103SCDRV	*self;
	int				c;
	
	self = (C_MN103SCDRV *)Param;
	
	/* 割込み要因クリア */
	SysInt_Clear(self->iIntNumRx);


	/* 受信文字があれば */
	if ( (MN103SC_READ_STR(self) & 0x10) )
	{
		/* 読み出し */	
		do
		{
			c = MN103SC_READ_RB(self);
			StreamBuf_SendChar(&self->StmBufRecv, c);
		} while ( (MN103SC_READ_STR(self) & 0x10) );
		
		/* 読込みシグナルを発生 */
		SyncDrv_SendSignal(&self->SyncDrv, SYNCDRV_FACTOR_READ);
	}
}


/* end of file */

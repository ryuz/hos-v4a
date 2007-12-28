/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  winsockdrv.h
 * @brief %jp{WinSockでシリアルを擬似するドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "winsockdrv_local.h"



/** 割込みサービスルーチン */
void WinSockDrv_Isr(VPARAM Param)
{
	C_WINSOCKDRV		*self;

	self = (C_WINSOCKDRV *)Param;

	SyncDrv_SendSignal(&self->SyncDrv, SYNCDRV_FACTOR_WRITE);
	SyncDrv_SendSignal(&self->SyncDrv, SYNCDRV_FACTOR_READ);
}


/* end of file */

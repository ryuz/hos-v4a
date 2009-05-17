/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  lan9118drv_isr.c
 * @brief %jp{SMSC LAN9118シリーズ用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "lan9118drv_local.h"


/* 割込み */
void Lan9118Drv_Isr(VPARAM Param)
{
	C_LAN9118DRV	*self;
	
	self = (C_LAN9118DRV *)Param;
	
	
	SysInt_Clear(self->iIntNum);
}


/* end of file */

/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scidrv.c
 * @brief %jp{LAN9000用デバイスドライバ}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "lan9000drv_local.h"


/* 受信割り込み */
void Lan9000Drv_Isr(VPARAM Param)
{
	C_LAN9000DRV	*self;
	unsigned short	uhStatus;

	self = (C_LAN9000DRV *)Param;
	
	/* 状態取得 */
	uhStatus = Lan9000Hal_GetInterruptStatus(&self->Lan9000Hal);
	
	/* 受信していたら */
	if ( uhStatus & LAN9000HAL_ISTATUS_RCVINT )
	{
		SysEvt_Set(self->hEvtRecv);
		uhStatus &= ~LAN9000HAL_IMASK_RCVINT;
	}

	/* 送信可能なら */
	if ( uhStatus & LAN9000HAL_ISTATUS_ALLOCINT )
	{
		SysEvt_Set(self->hEvtSend);
		uhStatus &= ~LAN9000HAL_IMASK_ALLOCINT;
	}
	
	/* 割込みマスク更新 */
	Lan9000Hal_SetInterruptMask(&self->Lan9000Hal, uhStatus);	
	
	/* 割込みクリア */
	SysInt_Clear(self->iIntNum);
}


/* end of file */

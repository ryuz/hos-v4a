/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scidrv.c
 * @brief %jp{PC16550用デバイスドライバ}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "pc16550drv_local.h"


/* 受信割り込み */
void Pc16550Drv_Isr(VPARAM Param)
{
	C_PC16550DRV	*self;
	int				iIntStatus;
	int				c;

	self = (C_PC16550DRV *)Param;

	/* 割込み状態の取得 */
	iIntStatus = Pc16550Hal_GetInterruptStatus(&self->Pc16550Hal);
	switch ( iIntStatus )
	{
	case PC16550HAL_IIR_RDA:
	case PC16550HAL_IIR_CTI:
		while ( (c = Pc16550Hal_RecvChar(&self->Pc16550Hal)) >= 0 )
		{
			StreamBuf_SendChar(&self->StmBufRecv, c);
		}
		SysEvt_Set(self->hEvtRecv);
		break;

	case PC16550HAL_IIR_THRE:
		Pc16550Hal_EnableInterrupt(&self->Pc16550Hal, PC16550HAL_IER_ERBFI);
		SysEvt_Set(self->hEvtSend);
	}
	
	SysInt_Clear(self->iIntNum);
}


/* end of file */

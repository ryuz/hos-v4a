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


/* 割込みサービスルーチン */
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
		/* 文字読み出しのみISR内で行う */
		while ( (c = Pc16550Hal_RecvChar(&self->Pc16550Hal)) >= 0 )
		{
			StreamBuf_SendChar(&self->StmBufRecv, c);
		}
		
		/* 読込みシグナルを発生 */
		SyncDrv_SendSignal(&self->SyncDrv, SYNCDRV_FACTOR_READ);
		break;

	case PC16550HAL_IIR_THRE:
		/* 送信割込み停止 */
		Pc16550Hal_EnableInterrupt(&self->Pc16550Hal, PC16550HAL_IER_ERBFI);
		
		/* 書込みシグナルを発生 */
		SyncDrv_SendSignal(&self->SyncDrv, SYNCDRV_FACTOR_WRITE);
	}
	
	SysInt_Clear(self->iIntNum);
}


/* end of file */

/** 
 * Hyper Operating System  Application Framework
 *
 * @file  xilinxuartdrv_isr.c
 * @brief %jp{XILINX UART driver 割込みサービスルーチン}%en{XILINX UART driver  interrupt service routine}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "xilinxuartdrv_local.h"


/* 割込み処理 */
void XilinxUartDrv_Isr(VPARAM Param)
{
	C_XILINXUARTDRV	*self;
	int			c;
	
	self = (C_XILINXUARTDRV *)Param;
	
	/* 受信 */	
	if ( XILINXUARTDRV_REG_READ(self, XILINXUARTDRV_REG_STAT) & 0x01 )
	{
		/* 受信バッファ読み出し */	
		do
		{
			/* 受信バッファ読み出し処理 */
			c = XILINXUARTDRV_REG_READ(self, XILINXUARTDRV_REG_RX);			
			StreamBuf_SendChar(&self->StmBufRecv, c);
		} while ( XILINXUARTDRV_REG_READ(self, XILINXUARTDRV_REG_STAT) & 0x01 );
		
		/* 読込みシグナルを発生 */
		SyncDrv_SendSignal(&self->SyncDrv, SYNCDRV_FACTOR_READ);
	}
	
	/* 送信 */
	if ( XILINXUARTDRV_REG_READ(self, XILINXUARTDRV_REG_STAT) & 0x04 )	/* TX-FIFO empty */
	{
		/* 書込みシグナルを発生 */
		SyncDrv_SendSignal(&self->SyncDrv, SYNCDRV_FACTOR_WRITE);
	}
	
	/* 割込み要因クリア */
	SysInt_Clear(self->iIntNum);
}


/* end of file */

/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  at91uartdrv_isr.c
 * @brief %jp{ATMEL AT91シリーズUART用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "at91uartdrv_local.h"


/* 受信割り込み */
void At91UartDrv_Isr(VPARAM Param)
{
	C_AT91UARTDRV	*self;
	unsigned long	uwCsr;
	int				c;

	self = (C_AT91UARTDRV *)Param;

	uwCsr = AT91UART_REG_READ(self, AT91UART_US_CSR);
	
	/* 受信 */	
	if ( uwCsr & 0x00000001 )
	{
		do
		{
			c = AT91UART_REG_READ(self, AT91UART_US_RHR);
			StreamBuf_SendChar(&self->StmBufRecv, c);
			uwCsr = AT91UART_REG_READ(self, AT91UART_US_CSR);
		} while ( uwCsr & 0x00000001 );
		
		SysEvt_Set(self->hEvtRecv);
	}
	
	/* 送信チェック */	
	if ( uwCsr & 0x00000002 )
	{
		AT91UART_REG_WRITE(self, AT91UART_US_IDR, 0x00000002);	/* 送信割り込み禁止 */		
		SysEvt_Set(self->hEvtSend);
	}
}


/* end of file */

/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  at91usartdrv_isr.c
 * @brief %jp{ATMEL AT91シリーズUSART用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "at91usartdrv_local.h"


/* 受信割込み */
void At91UsartDrv_Isr(VPARAM Param)
{
	C_AT91USARTDRV	*self;
	unsigned long	uwCsr;
	int				c;
	
	self = (C_AT91USARTDRV *)Param;
	
	uwCsr = AT91USART_REG_READ(self, AT91USART_US_CSR);
	
	/* 受信 */	
	if ( uwCsr & 0x00000001 )
	{
		/* 読み出し */	
		do
		{
			c = AT91USART_REG_READ(self, AT91USART_US_RHR);
			StreamBuf_SendChar(&self->StmBufRecv, c);
			uwCsr = AT91USART_REG_READ(self, AT91USART_US_CSR);
		} while ( uwCsr & 0x00000001 );
		
		/* 読込みシグナルを発生 */
		SyncDrv_SendSignal(&self->SyncDrv, SYNCDRV_FACTOR_READ);
	}
	
	/* 送信 */	
	if ( uwCsr & 0x00000002 )
	{
		/* 送信割込み禁止 */
		AT91USART_REG_WRITE(self, AT91USART_US_IDR, 0x00000002);
		
		/* 書込みシグナルを発生 */
		SyncDrv_SendSignal(&self->SyncDrv, SYNCDRV_FACTOR_WRITE);
	}
	
	SysInt_Clear(self->iIntNum);
}


/* end of file */

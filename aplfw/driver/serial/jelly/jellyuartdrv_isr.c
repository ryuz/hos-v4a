/** 
 * Hyper Operating System  Application Framework
 *
 * @file  jellyuartdrv_isr.c
 * @brief %jp{JellyUart 割込みサービスルーチン}%en{JellyUart  interrupt service routine}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "jellyuartdrv_local.h"


/* 割込み処理 */
void JellyUartDrv_IsrRx(VPARAM Param)
{
	C_JELLYUARTDRV	*self;
	int			c;
	
	self = (C_JELLYUARTDRV *)Param;
		
	/* 受信 */	
	if ( (JELLYUART_REG_READ(self, JELLYUART_STATUS) & 0x01) )
	{
		/* 受信バッファ読み出し */	
		do
		{
			/* 受信バッファ読み出し処理 */
			c = (int)JELLYUART_REG_READ(self, JELLYUART_DATA);
			StreamBuf_SendChar(&self->StmBufRecv, c);
		} while ( (JELLYUART_REG_READ(self, JELLYUART_STATUS) & 0x01) );
		
		/* 読込みシグナルを発生 */
		SyncDrv_SendSignal(&self->SyncDrv, SYNCDRV_FACTOR_READ);
	}
	
	/* 割込み要因クリア */
	SysInt_Clear(self->iIntNumRx);
}



/* 割込み処理 */
void JellyUartDrv_IsrTx(VPARAM Param)
{
	C_JELLYUARTDRV	*self;
	
	self = (C_JELLYUARTDRV *)Param;
	
	/* 送信 */	
	if ( (JELLYUART_REG_READ(self, JELLYUART_STATUS) & 0x02) )
	{
		/* 送信割込み禁止 */
		SysInt_Disable(self->iIntNumTx);
		
		/* 書込みシグナルを発生 */
		SyncDrv_SendSignal(&self->SyncDrv, SYNCDRV_FACTOR_WRITE);
	}
	
	/* 割込み要因クリア */
	SysInt_Clear(self->iIntNumTx);
}


/* end of file */

/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  mx1uartdrv_isr.c
 * @brief %jp{Freescale MX1 UART用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "system/system/system.h"
#include "mx1uartdrv_local.h"


void Mx1UartDrv_IsrTx(VPARAM Param)
{
	C_MX1UARTDRV	*self;
	int				c;

	self = (C_MX1UARTDRV *)Param;
}


static void Mx1UartDrv_RecvProc(VPARAM Param);


/* 受信割り込み */
void Mx1UartDrv_IsrRx(VPARAM Param)
{
	C_MX1UARTDRV	*self;
	int				c;

	self = (C_MX1UARTDRV *)Param;
	
	if ( MX1UART_REG_READ(self, MX1UART_USR2) & 0x0001 )
	{
		do
		{
			c = MX1UART_REG_READ(self, MX1UART_URXD(0));
			StreamBuf_SendChar(&self->StmBufRecv, c);
		} while ( MX1UART_REG_READ(self, MX1UART_USR2) & 0x0001 );

		System_RequestProc(Mx1UartDrv_RecvProc, (VPARAM)self);
/*		SysEvt_Set(self->hEvtRecv);
		ChrDrv_SetReadSignal(&self->ChrDrv);	*/
	}
}


void Mx1UartDrv_RecvProc(VPARAM Param)
{
	C_MX1UARTDRV	*self;

	self = (C_MX1UARTDRV *)Param;

	SysEvt_Set(self->hEvtRecv);
	ChrDrv_SetReadSignal(&self->ChrDrv);
}


/* end of file */

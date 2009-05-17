/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  mx1uartdrv_open.c
 * @brief %jp{Freescale MX1 UART用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "mx1uartdrv_local.h"


/** オープン */
HANDLE Mx1UartDrv_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode)
{
	C_MX1UARTDRV	*self;
	HANDLE			hFile;
	
	/* upper cast */
	self = (C_MX1UARTDRV *)pDrvObj;

	/* create file descriptor */
	if ( (hFile = SyncFile_Create(&self->SyncDrv, iMode)) == HANDLE_NULL)
	{
		return HANDLE_NULL;
	}
	
	/* オープン処理 */
	if ( self->iOpenCount++ == 0 )
	{
		MX1UART_REG_WRITE(self, MX1UART_UFCR, 0x00004290);

		MX1UART_REG_WRITE(self, MX1UART_UCR1, 0x00000205);
		MX1UART_REG_WRITE(self, MX1UART_UCR2, 0x00005027);
		MX1UART_REG_WRITE(self, MX1UART_UCR3, 0x00001800);
		MX1UART_REG_WRITE(self, MX1UART_UCR4, 0x00004007);

		MX1UART_REG_WRITE(self, MX1UART_UBIR, 1152-1);
		MX1UART_REG_WRITE(self, MX1UART_UBMR, 10000-1);
		
		/* 受信割込み許可 */
		SysInt_Enable(self->iIntNum + 5);
	}

	return hFile;
}


/* end of file */

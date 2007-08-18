/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  at91uartdrv_open.c
 * @brief %jp{ATMEL AT91シリーズUART用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "at91uartdrv_local.h"


/** オープン */
HANDLE At91UartDrv_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode)
{
	C_AT91UARTDRV	*self;
	C_CHRFILE		*pChrFile;
	
	/* upper cast */
	self = (C_AT91UARTDRV *)pDrvObj;

	/* create file descriptor */
	if ( (pChrFile = SysMem_Alloc(sizeof(*pChrFile))) == NULL )
	{
		return HANDLE_NULL;
	}
	ChrFile_Create(pChrFile, pDrvObj, NULL);

	
	/* オープン処理 */
	if ( self->iOpenCount++ == 0 )
	{
		AT91UART_REG_WRITE(self, AT91UART_US_MR,   0x000008c0);	/* 8bit, non-paroty */
		AT91UART_REG_WRITE(self, AT91UART_US_CR,   0x00000050);	/* enable */
		AT91UART_REG_WRITE(self, AT91UART_US_BRGR, 0x00000034);

		SysInt_Enable(self->iIntNum);
	}

	return (HANDLE)pChrFile;
}


/* end of file */

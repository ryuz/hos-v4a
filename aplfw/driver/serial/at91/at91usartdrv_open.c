/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  at91usartdrv_open.c
 * @brief %jp{ATMEL AT91シリーズUSART用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "at91usartdrv_local.h"


/** オープン */
HANDLE At91UsartDrv_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode)
{
	C_AT91USARTDRV	*self;
	C_CHRFILE		*pChrFile;
	
	/* upper cast */
	self = (C_AT91USARTDRV *)pDrvObj;

	/* create file descriptor */
	if ( (pChrFile = SysMem_Alloc(sizeof(*pChrFile))) == NULL )
	{
		return HANDLE_NULL;
	}
	ChrFile_Create(pChrFile, pDrvObj, NULL);

	
	/* オープン処理 */
	if ( self->iOpenCount++ == 0 )
	{
		AT91USART_REG_WRITE(self, AT91USART_US_CR,   0x0000010c);	/* reset */

		AT91USART_REG_WRITE(self, AT91USART_US_BRGR, 0x00000034);
		AT91USART_REG_WRITE(self, AT91USART_US_MR,   0x000008c0);	/* 8bit, non-paroty */
		AT91USART_REG_WRITE(self, AT91USART_US_CR,   0x00000050);	/* enable */
		AT91USART_REG_WRITE(self, AT91USART_US_IER,  0x00000001);	/* 受信割り込み許可 */		
		
		SysInt_Enable(self->iIntNum);
	}
	
	return (HANDLE)pChrFile;
}


/* end of file */

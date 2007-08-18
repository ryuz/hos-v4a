/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  at91uartdrv_iocontrol.c
 * @brief %jp{ATMEL AT91シリーズUART用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "at91uartdrv_local.h"


FILE_ERR  At91UartDrv_IoControl(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize)
{
	C_AT91UARTDRV	*self;
	C_CHRFILE		*pChrFile;
	
	/* upper cast */
	self     = (C_AT91UARTDRV *)pDrvObj;
	pChrFile = (C_CHRFILE *)pFileObj;

	return FILE_ERR_NG;
}


/* end of file */

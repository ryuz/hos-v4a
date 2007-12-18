/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  mx1uartdrv_flush.c
 * @brief %jp{Freescale MX1 UART用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "mx1uartdrv_local.h"


FILE_ERR Mx1UartDrv_Flush(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj)
{
	C_MX1UARTDRV	*self;
	C_SYNCFILE		*pFile;
	
	/* upper cast */
	self  = (C_MX1UARTDRV *)pDrvObj;
	pFile = (C_SYNCFILE *)pFileObj;

	return FILE_ERR_OK;
}


/* end of file */

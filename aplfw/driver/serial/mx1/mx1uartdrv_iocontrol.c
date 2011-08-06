/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  mx1uartdrv_iocontrol.c
 * @brief %jp{Freescale MX1 UART用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "mx1uartdrv_local.h"


FILE_ERR Mx1UartDrv_IoControl(C_FILEOBJ *pFileObj, C_FILEPTR *pFilePtr, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize)
{
	C_MX1UARTDRV	*self;
	C_SYNCFILE		*pFile;
	
	/* upper cast */
	self  = (C_MX1UARTDRV *)pFileObj;
	pFile = (C_SYNCFILE *)pFilePtr;

	return FILE_ERR_NG;
}


/* end of file */

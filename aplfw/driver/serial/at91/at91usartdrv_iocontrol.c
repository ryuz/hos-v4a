/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  at91usartdrv_iocontrol.c
 * @brief %jp{ATMEL AT91シリーズUSART用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "at91usartdrv_local.h"


FILE_ERR At91UsartDrv_IoControl(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize)
{
	return SyncDrv_IoControl(pDrvObj, pFileObj, iFunc, pInBuf, InSize, pOutBuf, OutSize);
}


/* end of file */

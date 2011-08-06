/** 
 * Hyper Operating System  Application Framework
 *
 * @file  jellyuartdrv_iocontrol.c
 * @brief %jp{JellyUart I/O制御}%en{JellyUart  I/O control}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "jellyuartdrv_local.h"


FILE_ERR JellyUartDrv_IoControl(C_FILEOBJ *pFileObj, C_FILEPTR *pFilePtr, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize)
{
	return SyncDrv_IoControl(pFileObj, pFilePtr, iFunc, pInBuf, InSize, pOutBuf, OutSize);
}


/* end of file */

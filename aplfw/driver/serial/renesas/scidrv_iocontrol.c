/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scidrv.c
 * @brief %jp{SCI用デバイスドライバ}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "scidrv_local.h"


FILE_ERR  SciDrv_IoControl(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize)
{
	C_SCIDRV	*self;
	C_SYNCFILE	*pFile;
	
	/* upper cast */
	self  = (C_SCIDRV *)pDrvObj;
	pFile = (C_SYNCFILE *)pFileObj;

	return FILE_ERR_NG;
}


/* end of file */

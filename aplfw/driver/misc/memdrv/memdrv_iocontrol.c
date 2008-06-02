/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  memdrv.h
 * @brief %jp{メモリマップドファイル用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "memdrv_local.h"



FILE_ERR  MemDrv_IoControl(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize)
{
	C_MEMDRV	*self;
	C_MEMFILE	*pFile;
	
	/* upper cast */
	self  = (C_MEMDRV *)pDrvObj;
	pFile = (C_MEMFILE *)pFileObj;

	return FILE_ERR_NG;
}


/* end of file */

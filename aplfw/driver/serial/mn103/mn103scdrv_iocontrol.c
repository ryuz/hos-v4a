/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  mn103scdrv_iocontrol.c
 * @brief %jp{MN103シリーズ シリアルインターフェース用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "mn103scdrv_local.h"


FILE_ERR  Mn103ScDrv_IoControl(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize)
{
	C_MN103SCDRV	*self;
	C_SYNCFILE		*pFile;
	
	/* upper cast */
	self  = (C_MN103SCDRV *)pDrvObj;
	pFile = (C_SYNCFILE *)pFileObj;

	return SyncDrv_IoControl(pDrvObj, pFileObj, iFunc, pInBuf, InSize, pOutBuf, OutSize);
}


/* end of file */

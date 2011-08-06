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


FILE_ERR  Mn103ScDrv_IoControl(C_FILEOBJ *pFileObj, C_FILEPTR *pFilePtr, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize)
{
	C_MN103SCDRV	*self;
	C_SYNCFILE		*pFile;
	
	/* upper cast */
	self  = (C_MN103SCDRV *)pFileObj;
	pFile = (C_SYNCFILE *)pFilePtr;

	return SyncDrv_IoControl(pFileObj, pFilePtr, iFunc, pInBuf, InSize, pOutBuf, OutSize);
}


/* end of file */

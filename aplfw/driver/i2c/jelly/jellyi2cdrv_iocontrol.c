/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  jellyi2cdrv_iocontrol.c
 * @brief %jp{Jelly I2Cデバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "jellyi2cdrv_local.h"


FILE_ERR JellyI2cDrv_IoControl(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize)
{
	C_JELLYI2CDRV	*self;

	self = (C_JELLYI2CDRV *)pDrvObj;

	switch ( iFunc )
	{
	case I2CDRV_IOCTL_ACCESS:
		return JellyI2cDrv_Access(self, (T_I2CDRV_ACCESS *)pOutBuf);
	}
	
	return SyncDrv_IoControl(pDrvObj, pFileObj, iFunc, pInBuf, InSize, pOutBuf, OutSize);
}


/* end of file */

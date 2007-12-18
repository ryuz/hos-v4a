/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scidrv.c
 * @brief %jp{LAN9000用デバイスドライバ}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "lan9000drv_local.h"


FILE_ERR Lan9000Drv_IoControl(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize)
{
	C_LAN9000DRV	*self;
	C_SYNCFILE		*pFile;
	
	/* upper cast */
	self  = (C_LAN9000DRV *)pDrvObj;
	pFile = (C_SYNCFILE *)pFileObj;

	switch ( iFunc )
	{
	case FILE_IOCTL_ETHER_GETPHA:
		if ( InSize >= 6 )
		{
			Lan9000Hal_GetPhysicalAddr(&self->Lan9000Hal, (unsigned char *)pInBuf);
			return FILE_ERR_OK;
		}
		break;
	
	default:
		break;
/*		return SyncDrv_IoControl(pDrvObj, pFileObj, pInBuf, InSize, pOutBuf, OutSize);	*/
	}

	return FILE_ERR_NG;
}


/* end of file */

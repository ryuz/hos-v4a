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


FILE_ERR  Lan9000Drv_IoControl(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize)
{
	C_LAN9000DRV	*self;
	C_CHRFILE		*pChrFile;
	
	/* upper cast */
	self     = (C_LAN9000DRV *)pDrvObj;
	pChrFile = (C_CHRFILE *)pFileObj;

	return FILE_ERR_NG;
}


/* end of file */

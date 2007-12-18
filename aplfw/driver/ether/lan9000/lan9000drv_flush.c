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


FILE_ERR Lan9000Drv_Flush(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj)
{
	C_LAN9000DRV	*self;
	C_SYNCFILE		*pFile;
	
	/* upper cast */
	self  = (C_LAN9000DRV *)pDrvObj;
	pFile = (C_SYNCFILE *)pFileObj;

	return FILE_ERR_OK;
}


/* end of file */

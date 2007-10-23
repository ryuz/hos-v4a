/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scidrv.c
 * @brief %jp{PC16550用デバイスドライバ}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "pc16550drv_local.h"


FILE_POS Pc16550Drv_Seek(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, FILE_POS Offset, int iOrign)
{
	C_PC16550DRV	*self;
	C_CHRFILE		*pFile;
	
	/* upper cast */
	self  = (C_PC16550DRV *)pDrvObj;
	pFile = (C_CHRFILE *)pFileObj;

	return FILE_ERR_NG;
}


/* end of file */

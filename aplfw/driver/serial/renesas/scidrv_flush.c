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


FILE_ERR SciDrv_Flush(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj)
{
	C_SCIDRV	*self;
	C_CHRFILE	*pFile;
	
	/* upper cast */
	self  = (C_SCIDRV *)pDrvObj;
	pFile = (C_CHRFILE *)pFileObj;

	return FILE_ERR_OK;
}


/* end of file */

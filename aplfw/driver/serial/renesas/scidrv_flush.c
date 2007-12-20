/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scidrv.c
 * @brief %jp{Renesas H8/SH用 SCIデバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "scidrv_local.h"


FILE_ERR SciDrv_Flush(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj)
{
	C_SCIDRV	*self;
	C_SYNCFILE	*pFile;
	
	/* upper cast */
	self  = (C_SCIDRV *)pDrvObj;
	pFile = (C_SYNCFILE *)pFileObj;

	return FILE_ERR_OK;
}


/* end of file */

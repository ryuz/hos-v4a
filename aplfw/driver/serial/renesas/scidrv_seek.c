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


FILE_POS SciDrv_Seek(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, FILE_POS Offset, int iOrign)
{
	C_SCIDRV	*self;
	C_SYNCFILE	*pFile;
	
	/* upper cast */
	self  = (C_SCIDRV *)pDrvObj;
	pFile = (C_SYNCFILE *)pFileObj;

	return FILE_ERR_NG;
}


/* end of file */

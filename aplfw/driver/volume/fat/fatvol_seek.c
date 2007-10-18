/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  fatvol.c
 * @brief %jp{FATボリューム用デバイスドライバ}
 *
 * Copyright (C) 2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "fatvol_local.h"


FILE_POS FatVol_Seek(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, FILE_POS Offset, int iOrign)
{
	C_FATVOL	*self;
	C_FATFILE	*pFile;
	
	/* upper cast */
	self  = (C_FATVOL *)pDrvObj;
	pFile = (C_FATFILE *)pFileObj;

	return FILE_ERR_NG;
}


/* end of file */

/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  fatvol.c
 * @brief %jp{FATボリューム用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "fatvol_local.h"


FILE_ERR FatVol_Remove(C_VOLUMEOBJ *pVolObj, const char *pszPath)
{
	C_FATVOL	*self;
	
	/* upper cast */
	self  = (C_FATVOL *)pVolObj;

	return FILE_ERR_OK;
}


/* end of file */

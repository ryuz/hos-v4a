/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  vt100drv_open.c
 * @brief %jp{VT100 ターミナルドライバ}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "vt100drv_local.h"
#include "system/sysapi/sysapi.h"



HANDLE Vt100Drv_Open(C_FILEOBJ *pFileObj, const char *pszPath, int iMode)
{
	C_VT100DRV	*self;
	HANDLE		*hFile;
	
	/* upper cast */
	self = (C_VT100DRV *)pFileObj;
	
	/* create file descriptor */
	if ( (hFile = FilePtr_Create(&self->FileObj, iMode)) == HANDLE_NULL )
	{
		return HANDLE_NULL;
	}
	
	return hFile;
}


/* end of file */

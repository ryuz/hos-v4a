/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  file_driveropen.c
 * @brief %jp{ファイルシステム}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include "file_local.h"
#include "drvobj_local.h"



/* ドライバから直接名無しファイルとしてオープン */
HANDLE File_DriverOpen(HANDLE hDriver, const char *pszPath, int iMode)
{
	C_DRVOBJ *self;
	
	self = (C_DRVOBJ *)hDriver;
	
	if ( DrvObj_GetMethods(self)->pfncOpen == NULL )
	{
		return HANDLE_NULL;
	}
	
	return DrvObj_GetMethods(self)->pfncOpen(self, pszPath, iMode);
}


/* end of file */

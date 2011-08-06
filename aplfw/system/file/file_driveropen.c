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
#include "file_local.h"



/* ドライバから直接名無しファイルとしてオープン */
HANDLE File_DriverOpen(HANDLE hDriver, const char *pszPath, int iMode)
{
	C_FILEOBJ *self;
	
	self = (C_FILEOBJ *)hDriver;
	
	if ( FileObj_GetMethods(self)->pfncOpen == NULL )
	{
		return HANDLE_NULL;
	}
	
	return FileObj_GetMethods(self)->pfncOpen(self, pszPath, iMode);
}


/* end of file */

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



/* デバイスドライバ情報取得 */
FILE_ERR  File_GetDriverInformation(HANDLE hDriver, char *pszInformation, int iLen)
{
	C_FILEOBJ *self;
	
	self = (C_FILEOBJ *)hDriver;
	
	if ( FileObj_GetMethods(self)->pfncGetInformation == NULL )
	{
		return FILE_ERR_NG;
	}
	
	return FileObj_GetMethods(self)->pfncGetInformation(self, pszInformation, iLen);
}


/* end of file */

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



/* デバイスドライバ情報取得 */
FILE_ERR  File_GetDriverInformation(HANDLE hDriver, char *pszInformation, int iLen)
{
	C_DRVOBJ *self;
	
	self = (C_DRVOBJ *)hDriver;
	
	if ( DrvObj_GetMethods(self)->pfncGetInformation == NULL )
	{
		return FILE_ERR_NG;
	}
	
	return DrvObj_GetMethods(self)->pfncGetInformation(self, pszInformation, iLen);
}


/* end of file */

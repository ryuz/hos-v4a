/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  file.c
 * @brief %jp{ファイルシステム}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "file_local.h"
#include "volume/dev/devvol.h"


/* デバイスファイルの追加 */
FILE_ERR File_AddDevice(const char *pszName, C_DRVOBJ *pDrvObj)
{
	C_FILE *self;
	
	self = &g_File; 
	
	return DevVol_AddDevice(self->hDevVol, pszName, pDrvObj);
}


/* end of file */

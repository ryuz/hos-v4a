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


/* ボリュームデバイスの取得 */
HANDLE File_GetVolume(const char *pszName)
{
	C_FILE *self;

	self = &g_File;

	return SysVol_GetDevice(self->hRootVol, pszName);
}


/* endof file */

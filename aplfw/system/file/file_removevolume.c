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


/* ボリュームデバイスの削除 */
FILE_ERR File_RemoveVolume(const char *pszName)
{
	C_FILE *self;

	self = &g_File;

	/* ルートディレクトリの下にボリュームを登録 */
	return SysVol_RemoveDevice(self->hRootVol, pszName);
}


/* endof file */

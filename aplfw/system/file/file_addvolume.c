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


/* ボリュームデバイスの追加 */
FILE_ERR File_AddVolume(const char *pszName, struct c_drvobj *pVolObj)
{
	C_FILE *self;

	self = &g_File;

	/* ルートディレクトリの下にボリュームを登録 */
	SysVol_AddDevice(&self->RootVol, pszName, (C_DRVOBJ *)pVolObj, FILE_ATTR_DIR);
	
	return FILE_ERR_OK;
}


/* endof file */

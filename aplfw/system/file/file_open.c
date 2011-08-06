/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  file.c
 * @brief %jp{ファイルシステム}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include <stdio.h>
#include <string.h>
#include "hosaplfw.h"
#include "file_local.h"


/* ファイルのオープン */
HANDLE File_Open(const char *pszPath, int iMode)
{
	C_FILE		*self;
	C_FILEOBJ	*pFileObj;
	char		szBuf[FILE_MAX_PATH];
	
	self = &g_File;
	
	/* 絶対パスに変換 */
	if ( File_RelPathToAbsPath(szBuf, pszPath, sizeof(szBuf)) != FILE_ERR_OK )
	{
		return HANDLE_NULL;
	}
	
	/* ルートオブジェクト取得 */
	pFileObj = (C_FILEOBJ *)g_File.hRootVol;
	
	/* ルートディレクトリからオープンを掛ける */
	return FileObj_GetMethods(pFileObj)->pfncOpen(pFileObj, &pszPath[1], iMode);
}


/* end of file */

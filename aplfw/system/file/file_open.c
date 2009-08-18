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
	FILE_ERR	ErrCode;
	char		szBuf[FILE_MAX_PATH];
	
	self = &g_File;
	
	/* 絶対パスに変換 */
	ErrCode = File_RelPathToAbsPath(szBuf, pszPath, sizeof(szBuf));
	if ( ErrCode != FILE_ERR_OK )
	{
		return HANDLE_NULL;
	}
	
	/* ルートディレクトリからオープンを掛ける */
	return DrvObj_vOpen((C_DRVOBJ *)self->hRootVol, &szBuf[1], iMode);
}


/* end of file */

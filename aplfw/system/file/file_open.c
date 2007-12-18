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
	C_FILE	*self;
	char	szBuf[FILE_MAX_PATH];
	int		iLen;
	
	self = &g_File;
	
	/* パス生成 */
	if ( *pszPath == '/' )
	{
		/* 絶対パス */
		strncpy(szBuf, pszPath+1, FILE_MAX_PATH);		
	}
	else
	{
		/* 相対パス */
		iLen = Process_GetCurrentDir(szBuf, sizeof(szBuf));
		if ( szBuf[0] != '\0' )
		{
			strncat(szBuf, "/", FILE_MAX_PATH - iLen);
			iLen++;
		}
		strncat(szBuf, pszPath, FILE_MAX_PATH - iLen);
	}
	szBuf[FILE_MAX_PATH-1] = '\0';
	
	/* 相対パス解決 */
	/* 割愛 */
	
	
	/* 末尾の '/' の削除 */
	iLen = strlen(szBuf);
	while ( iLen > 0 && szBuf[iLen-1] == '/' )
	{
		szBuf[iLen-1] = '\0';
		iLen--;
	}
	
	/* ルートディレクトリからオープンを掛ける */
	return DrvObj_vOpen((C_DRVOBJ *)self->hRootVol, szBuf, iMode);
}


/* end of file */

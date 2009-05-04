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
	int			iLen;
	int			i, j, k;
	
	self = &g_File;

#if 0
	/* パス生成 */
	if ( *pszPath == '/' )
	{
		/* 絶対パス */
		strncpy(szBuf, pszPath+1, FILE_MAX_PATH);		
	}
	else
	{
		/* 相対パス */
		strcpy(szBuf, Process_GetCurrentDir(HANDLE_NULL));
		iLen = strlen(szBuf);
		if ( szBuf[0] != '\0' )
		{
			strncat(szBuf, "/", FILE_MAX_PATH - iLen);
			iLen++;
		}
		strncat(szBuf, pszPath, FILE_MAX_PATH - iLen);
	}
	szBuf[FILE_MAX_PATH-1] = '\0';
	
	/* 相対パス解決 */
	for ( i = 0; szBuf[i] == '\0'; i++ )
	{
		j = i;
		if ( szBuf[i] == '/' )
		{
			if ( szBuf[i+1] == '/' )
			{
				j = i + 1;
			}
			else if ( szBuf[i+1] == '.' && (szBuf[i+2] == '/' || szBuf[i+2] == '\0') )
			{
				j = i + 2;
			}
			else if ( szBuf[i+1] == '.' && szBuf[i+2] == '.' && (szBuf[i+3] == '/' || szBuf[i+3] == '\0') )
			{
				j = i + 3;
				while ( i > 0 )
				{
					if ( szBuf[--i] == '/' )
					{
						break;
					}
				}
			}
			if ( i != j )
			{
				for ( k = 0; szBuf[j+k] != '\0'; k++ )
				{
					szBuf[i + k] = szBuf[j + k];
				}
				szBuf[i + k] = '\0';
			}
		}
	}
	
	/* 末尾の '/' の削除 */
	iLen = strlen(szBuf);
	while ( iLen > 0 && szBuf[iLen-1] == '/' )
	{
		szBuf[iLen-1] = '\0';
		iLen--;
	}
#endif
	
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

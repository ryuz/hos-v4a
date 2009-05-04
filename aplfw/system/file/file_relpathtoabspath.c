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


/* 相対パスを絶対パスに変換 */
FILE_ERR File_RelPathToAbsPath(char *pszDstPath, const char *pszSrcPath, int iMaxLen)
{
	int	iLen;
	int	i, j, k;
	
	/* パス生成 */
	if ( pszSrcPath[0] == '/' )
	{
		/* 絶対パス */
		strncpy(pszDstPath, pszSrcPath, iMaxLen);
	}
	else
	{
		/* 相対パス */
		strcpy(pszDstPath, Process_GetCurrentDir(HANDLE_NULL));
		iLen = strlen(pszDstPath);
		if ( pszDstPath[0] != '\0' )
		{
			strncat(pszDstPath, "/", iMaxLen - iLen);
			iLen++;
		}
		strncat(pszDstPath, pszSrcPath, iMaxLen - iLen);
	}
	pszDstPath[iMaxLen-1] = '\0';
	
	/* パス正規化 */
	for ( i = 0; pszDstPath[i] != '\0'; i++ )
	{
		j = i;
		if ( pszDstPath[i] == '/' )
		{
			if ( pszDstPath[i+1] == '/' )
			{
				j = i + 1;
			}
			else if ( pszDstPath[i+1] == '.' && (pszDstPath[i+2] == '/' || pszDstPath[i+2] == '\0') )
			{
				j = i + 2;
			}
			else if ( pszDstPath[i+1] == '.' && pszDstPath[i+2] == '.' && (pszDstPath[i+3] == '/' || pszDstPath[i+3] == '\0') )
			{
				j = i + 3;
				while ( i > 0 )
				{
					if ( pszDstPath[--i] == '/' )
					{
						break;
					}
				}
			}
			if ( i != j )
			{
				if ( pszDstPath[j] == '\0' )
				{
					k = 1;
				}
				else
				{
					for ( k = 1; pszDstPath[j + k] != '\0'; k++ )
					{
						pszDstPath[i + k] = pszDstPath[j + k];
					}
				}
				pszDstPath[i + k] = '\0';
			}
		}
	}
	
	/* 末尾の '/' の削除 */
	iLen = strlen(pszDstPath);
	while ( iLen > 1 && pszDstPath[iLen-1] == '/' )
	{
		pszDstPath[iLen-1] = '\0';
		iLen--;
	}
	
	return FILE_ERR_OK;
}


/* end of file */

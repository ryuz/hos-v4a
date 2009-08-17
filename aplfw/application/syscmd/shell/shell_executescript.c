/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  shell_main.c
 * @brief %jp{シェル}
 *
 * Copyright (C) 2006-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "shell_local.h"



/* スクリプト実行 */
int Shell_ExecuteScript(C_SHELL *self, const char *pszFileName)
{
	HANDLE	hFile;
	int		iLen;
	
	/* ファイルオープン */
	if ( (hFile = File_Open(pszFileName, FILE_OPEN_READ | FILE_OPEN_EXIST | FILE_OPEN_TEXT)) == HANDLE_NULL )
	{
		StdIo_PrintFormat("open error : %s\n", pszFileName);
		return 1;
	}
	
	/* ファイルを実行 */
	while ( (iLen = File_GetString(hFile, self->pszCommanBuf, self->iCommandBufSize)) > 0 )
	{
		/* 末尾の改行削除 */
		if ( self->pszCommanBuf[iLen-1] == '\n' )
		{
			self->pszCommanBuf[iLen-1] = '\0';
		}
		
		/* 実行 */
		if ( self->pszCommanBuf[0] != '\0' && self->pszCommanBuf[0] != '#' )
		{
			Shell_ExecuteCommand(self, self->pszCommanBuf);
		}
	}
	
	/* ファイルクローズ */
	File_Close(hFile);
	
	return 0;
}



/* end of file */

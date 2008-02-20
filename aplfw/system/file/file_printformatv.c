/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  file.c
 * @brief %jp{ファイルシステム}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include <string.h>
#include "file_local.h"
#include "system/sysapi/sysapi.h"
#include "library/algorithm/stringformat/stringformat.h"



static int File_OutputPrintFormat(int c, void *Param);		/* 書式ライブラリ用コールバック関数 */



/* 書式付出力(リスト渡し) */
int File_PrintFormatV(HANDLE hFile, const char *pszFormat, va_list argptr)
{
	return StringFormat_FormatV(File_OutputPrintFormat, (void *)hFile, pszFormat, argptr);
}


/* 書式ライブラリ用コールバック関数 */
int File_OutputPrintFormat(int c, void *Param)
{
	HANDLE hFile;
	
	hFile = (HANDLE)Param;
	
	/* 結果をファイルシステムへリダイレクト */
	if ( File_PutChar(hFile, c) == FILE_EOF )
	{
		return 0;
	}
	
	return 1;
}


/* end of file */

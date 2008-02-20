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


/* 書式付出力 */
int File_PrintFormat(HANDLE hFile, const char *pszFormat, ...)
{
	va_list argptr;
	int iRet;
	
	va_start(argptr, pszFormat);
	iRet = File_PrintFormatV(hFile, pszFormat, argptr);
	va_end(argptr);
	
	return iRet;
}


/* end of file */

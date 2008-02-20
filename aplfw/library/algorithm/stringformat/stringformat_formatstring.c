/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  stringformat.c
 * @brief %jp{文字列フォーマット生成ライブラリ}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "stringformat_local.h"



/* sprintfもどき */	
int StringFormat_FormatString(char *pszBuf, int iBufSize, const char *pszFormat, ...)
{
	va_list	argptr;
	int		iRet;

	va_start(argptr, pszFormat);
	iRet = StringFormat_FormatStringV(pszBuf, iBufSize, pszFormat, argptr);
	va_end(argptr);
	
	return iRet;
}


/* end of file */

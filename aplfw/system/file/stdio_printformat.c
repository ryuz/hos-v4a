/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  file.h
 * @brief %jp{ファイルシステム}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "stdfile.h"


int StdIo_PrintFormat(const char *pszFormat, ...)
{
	va_list argptr;
	int iRet;

	va_start(argptr, pszFormat);
	iRet = File_PrintFormatV(Process_GetStdOut(HANDLE_NULL), pszFormat, argptr);
	va_end(argptr);

	return iRet;
}


/* end of file */

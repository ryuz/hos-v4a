#include "stdfile.h"

int StdIo_PrintFormat(const char *pszFormat, ...)
{
	va_list argptr;
	int iRet;

	va_start(argptr, pszFormat);
	iRet = File_PrintFormatVL(Process_GetStdOut(HANDLE_NULL), pszFormat, argptr);
	va_end(argptr);

	return iRet;
}



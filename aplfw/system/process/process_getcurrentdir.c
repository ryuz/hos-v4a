/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  process.c
 * @brief %jp{プロセスオブジェクト}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include <string.h>
#include "process_local.h"



int Process_GetCurrentDir(HANDLE hProcess, char *pszBuf, int iBufSize)
{
	C_PROCESS *self;

	self = (C_PROCESS *)Process_GetCurrentHandle();

	strncpy(pszBuf, self->szCurrentDir, iBufSize);
	pszBuf[iBufSize-1] = '\0';

	return strlen(pszBuf);
}



/* end of file */

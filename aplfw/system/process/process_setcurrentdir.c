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



int Process_SetCurrentDir(HANDLE hProcess, const char *pszPath)
{
	C_PROCESS *self;
	
	if ( hProcess == HANDLE_NULL )
	{
		hProcess = Process_GetCurrentHandle();
	}
	
	self = (C_PROCESS *)Process_GetCurrentHandle();
	
	strncpy(self->szCurrentDir, pszPath, FILE_MAX_PATH);
	self->szCurrentDir[FILE_MAX_PATH-1] = '\0';
	
	return strlen(self->szCurrentDir);
}



/* end of file */

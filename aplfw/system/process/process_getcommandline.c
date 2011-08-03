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


const char *Process_GetCommandLine(HANDLE hProcess)
{
	C_PROCESSOBJ *self;
	
	/* ハンドルからオブジェクト本体を取得 */
	self = Process_GetCurrentProcessObj();
	
	return self->pszCommandLine;
}


/* end of file */

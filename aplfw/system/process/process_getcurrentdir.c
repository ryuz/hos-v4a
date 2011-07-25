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


const char *Process_GetCurrentDir(HANDLE hProcess)
{
	C_PROCESS *self;

	/* ハンドルからオブジェクト本体を取得 */
	self = ProcessHandle_GetProcess(hProcess);
	
	/* ハンドルをキャスト */
	self = (C_PROCESS *)hProcess;

	return self->pszCurrentDir;
}



/* end of file */

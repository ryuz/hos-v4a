/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  processhandle_create.c
 * @brief %jp{プロセスハンドル生成}
 *
 * Copyright (C) 2006-2011 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "process_local.h"
#include "processhandle.h"


/* プロセス取得 */
C_PROCESS *ProcessHandle_GetProcess(HANDLE Handle)
{
	if ( Handle == HANDLE_NULL )
	{
		/* 指定が無ければ現在のプロセスとする */
		return Process_GetCurrentProcess();
	}
	else
	{
		/* ハンドルをキャスト */
		return ((C_PROCESSHANDLE *)Handle)->pProcess;
	}
}


/* end of file */

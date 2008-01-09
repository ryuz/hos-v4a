/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  process.c
 * @brief %jp{プロセスオブジェクト}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include <string.h>
#include "process_local.h"


/** プロセス終了コードの取得 */
int Process_GetExitCode(HANDLE hProcess)
{
	C_PROCESS *self;
	
	/* 指定が無ければエラー */
	if ( hProcess == HANDLE_NULL )
	{
		return -1;
	}
	
	/* ハンドルをキャスト */
	self = (C_PROCESS *)hProcess;

	return self->iExitCode;
}



/* end of file */

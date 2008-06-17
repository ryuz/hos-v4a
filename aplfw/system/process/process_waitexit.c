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



/** プロセスの終了を待つ */
PROCESS_ERR Process_WaitExit(HANDLE hProcess)
{
	C_PROCESS *self;
	
	if ( hProcess == HANDLE_NULL || hProcess == Process_GetCurrentHandle() )
	{
		return PROCESS_ERR_NG;
	}

	self = (C_PROCESS *)hProcess;
	
	/* 終了を待つ */
	while ( !self->Exit )
	{
		SysEvt_Wait(self->hEvt);
		SysEvt_Clear(self->hEvt);
	}
	
	return PROCESS_ERR_OK;
}


/** プロセスの終了を確認 */
int Process_IsExit(HANDLE hProcess)
{
	C_PROCESS *self;
	
	if ( hProcess == HANDLE_NULL )
	{
		return 0;
	}

	self = (C_PROCESS *)hProcess;

	return self->Exit;
}


/* end of file */

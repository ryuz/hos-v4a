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
	C_PROCESSOBJ *self;
	
	if ( hProcess == HANDLE_NULL )
	{
		return PROCESS_ERR_NG;
	}

	/* ハンドルからオブジェクト本体を取得 */
	self = ProcessPtr_GetProcessObj(hProcess);
	
	/* 自オブジェクトの指定禁止 */
	if ( self == Process_GetCurrentProcessObj() )
	{
		return PROCESS_ERR_NG;
	}

	/* 終了を待つ */
	while ( !self->Exit )
	{
		SysEvt_Wait(self->hEvt);
		SysEvt_Clear(self->hEvt);
	}
	
	return PROCESS_ERR_OK;
}


/* end of file */

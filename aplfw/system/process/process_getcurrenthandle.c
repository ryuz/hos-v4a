/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  process.h
 * @brief %jp{プロセスオブジェクト}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include "process_local.h"
#include "system/system/system_local.h"



/* 現在のプロセスハンドル取得 */
HANDLE Process_GetCurrentHandle(void)
{
	C_PROCESS		*self;
	
	/* ハンドルからオブジェクト本体を取得 */
	self = Process_GetCurrentProcess();
	
	/* ハンドルを返す */
	return self->hProcess;
}


/* end of file */

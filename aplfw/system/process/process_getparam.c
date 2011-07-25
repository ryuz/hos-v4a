/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  process.c
 * @brief %jp{プロセスオブジェクト}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "process_local.h"



/** プロセス固有情報の取得 */
VPARAM Process_GetParam(HANDLE hProcess)
{
	C_PROCESS *self;
	
	/* ハンドルからオブジェクト本体を取得 */
	self = ProcessHandle_GetProcess(hProcess);
	
	/* パラメータを返す */
	return self->Param;
}



/* end of file */

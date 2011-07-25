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



/** プロセス固有情報の設定 */
void Process_SetParam(HANDLE hProcess, VPARAM Param)
{
	C_PROCESS *self;
	
	/* ハンドルからオブジェクト本体を取得 */
	self = ProcessHandle_GetProcess(hProcess);
	
	/* パラメータを設定 */
	self->Param = Param;
}



/* end of file */

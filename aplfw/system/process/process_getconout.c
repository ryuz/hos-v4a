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



/** プロセスの標準コンソール取得 */
HANDLE Process_GetConOut(HANDLE hProcess)
{
	C_PROCESS *self;
	
	/* ハンドルからオブジェクト本体を取得 */
	self = ProcessHandle_GetProcess(hProcess);
	
	/* ハンドルを返す */
	return self->hConOut;
}



/* end of file */

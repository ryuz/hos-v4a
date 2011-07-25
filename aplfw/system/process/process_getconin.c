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
HANDLE Process_GetConsole(void)
{
	C_PROCESS *self;
	
	/* 現在のプロセス取得 */
	self = Process_GetCurrentHandle();
	
	/* ハンドルを返す */
	return self->hConsole;
}



/* end of file */

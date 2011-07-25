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



/** プロセスの標準エラー出力取得 */
HANDLE Process_GetStdErr(void)
{
	C_PROCESS *self;
	
	/* 現在のプロセス取得 */
	self = Process_GetCurrentHandle();
	
	/* ハンドルを返す */
	return self->hStdErr;
}



/* end of file */

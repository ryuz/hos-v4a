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



/** プロセスの標準出力取得 */
HANDLE Process_GetStdOut(void)
{
	C_PROCESSOBJ *self;
	
	/* 現在のプロセス取得 */
	self = Process_GetCurrentProcessObj();
	
	/* ハンドルを返す */
	return self->hStdOut;
}



/* end of file */

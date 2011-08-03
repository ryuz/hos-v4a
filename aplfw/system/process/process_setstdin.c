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


/** プロセスの標準入力設定 */
void Process_SetStdIn(HANDLE hFile)
{
	C_PROCESSOBJ *self;
	
	/* 現在のプロセス取得 */
	self = Process_GetCurrentProcessObj();

	/* ハンドルを設定 */
	self->hStdIn = hFile;
}


/* end of file */

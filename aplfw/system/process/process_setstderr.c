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


/** プロセスの標準エラー出力設定 */
void Process_SetStdErr(HANDLE hFile)
{
	C_PROCESS *self;
	
	/* 現在のプロセス取得 */
	self = Process_GetCurrentHandle();
	
	/* ハンドルを設定 */
	self->hStdErr = hFile;
}


/* end of file */

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



/** プロセスの標準コンソール設定 */
void Process_SetConsole(HANDLE hFile)
{
	C_PROCESSOBJ *self;
	
	/* 現在のプロセス取得 */
	self = Process_GetCurrentProcessObj();
	
	/* ハンドルを設定 */
	self->hConsole = hFile;
}



/* end of file */

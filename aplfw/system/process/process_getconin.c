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



/** プロセスの標準コンソール入力取得 */
HANDLE Process_GetConIn(HANDLE hProcess)
{
	C_PROCESS *self;
	
	/* 指定が無ければ現在のプロセスとする */
	if ( hProcess == HANDLE_NULL )
	{
		hProcess = Process_GetCurrentHandle();
	}
	
	/* ハンドルをキャスト */
	self = (C_PROCESS *)hProcess;
	
	/* ハンドルを返す */
	return self->hConIn;
}



/* end of file */

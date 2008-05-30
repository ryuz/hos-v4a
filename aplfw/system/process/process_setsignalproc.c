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


/**< プロセスにシグナル受信プロシージャを登録 */
void Process_SetSignalProc(HANDLE hProcess, void (*pfncSignalProc)(int iSignal))
{
	C_PROCESS *self;
	
	/* 指定が無ければ現在のプロセスとする */
	if ( hProcess == HANDLE_NULL )
	{
		hProcess = Process_GetCurrentHandle();
	}
	
	/* ハンドルをキャスト */
	self = (C_PROCESS *)hProcess;
	
	/* ハンドルを設定 */
	self->pfncSignalProc = pfncSignalProc; 
}



/* end of file */

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
void Process_SendSignal(HANDLE hProcess, int iSignal)
{
	C_PROCESS *self;
	
	/* ハンドルからオブジェクト本体を取得 */
	self = ProcessHandle_GetProcess(hProcess);
	
	/* シグナル送信 */
	self->iSignal = iSignal;
	SysPrc_SendSignal(self->hPrc);
}



/* end of file */

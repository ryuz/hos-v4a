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
void Process_SetSignalProc(void (*pfncSignalProc)(int iSignal))
{
	C_PROCESSOBJ *self;

	/* 現在のプロセス取得 */
	self = Process_GetCurrentProcessObj();
	
	/* プロシージャを設定 */
	self->pfncSignalProc = pfncSignalProc; 
}



/* end of file */

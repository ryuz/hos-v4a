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


/** システムモードを出る */
void Process_LeaveSystemMode(void)
{
	C_PROCESS *self;
	
	/* 現在のプロセス取得 */
	self = (C_PROCESS *)Process_GetCurrentHandle();
	
	/* モード設定 */
	self->SysMode--;
}


/* end of file */

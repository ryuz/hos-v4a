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



/** システムモードに入る */
PROCESS_ERR Process_EnterSystemMode(void)
{
	C_PROCESS *self;
	
	/* 現在のプロセス取得 */
	self = (C_PROCESS *)Process_GetCurrentHandle();
	
	/* モード設定 */
	self->SysMode++;
	
	return PROCESS_ERR_OK;
}


/* end of file */

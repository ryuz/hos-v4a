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
	C_PROCESSOBJ *self;
	
	/* 現在のプロセス取得 */
	self = Process_GetCurrentProcessObj();
	
	/* モード設定 */
	if ( --self->SysMode == 0 )
	{
		/* シグナル処理 */
	}
}


/* end of file */

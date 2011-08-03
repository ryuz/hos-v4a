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



/** プロセス固有情報の設定 */
void Process_SetParam(VPARAM Param)
{
	C_PROCESSOBJ *self;
	
	/* 現在のプロセス取得 */
	self = Process_GetCurrentProcessObj();

	/* パラメータを設定 */
	self->Param = Param;
}



/* end of file */

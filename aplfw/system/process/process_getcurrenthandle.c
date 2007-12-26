/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  process.h
 * @brief %jp{プロセスオブジェクト}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include "process_local.h"



/* 現在のプロセスハンドル取得 */
HANDLE Process_GetCurrentHandle(void)
{
	SYSPRC_HANDLE hSysPrc;
	
	/* 現在のプロセスを取得 */
	if ( (hSysPrc = SysPrc_GetCurrentHandle()) == SYSPRC_HANDLE_NULL )
	{
		return HANDLE_NULL;
	}
	
	/* 現在のプロセスを取得 */
	return (HANDLE)SysPrc_GetParam(hSysPrc);
}


/* end of file */

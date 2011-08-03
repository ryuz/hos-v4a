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
#include "system/system/system_local.h"



/* 現在のプロセス取得 */
C_PROCESSOBJ *Process_GetCurrentProcessObj(void)
{
	SYSPRC_HANDLE	hSysPrc;
	
	/* 現在のプロセスを取得 */
	hSysPrc = SysPrc_GetCurrentHandle();
	
	if ( hSysPrc == SYSPRC_HANDLE_NULL )
	{
		/* 未管理プロセスはすべてシステムプロセスとする */
		return System_GetSystemProcessObj();
	}
	else
	{
		/* 現在のプロセスを取得 */
		return (C_PROCESSOBJ *)SysPrc_GetParam(hSysPrc);
	}
}


/* end of file */

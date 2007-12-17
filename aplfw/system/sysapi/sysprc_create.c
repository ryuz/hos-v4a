/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  system.h
 * @brief %jp{システム用API定義}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "sysapi_local.h"


/* プロセス生成 */
SYSPRC_HANDLE SysPrc_Create(void (*pfncEntry)(VPARAM Param), VPARAM Param, MEMSIZE StackSize, int Priority, int iAttr)
{
	T_CTSK ctsk;
	ER_ID  erid;
	
	ctsk.tskatr  = TA_HLNG | TA_ACT;
	ctsk.exinf   = (VP_INT)Param;
	ctsk.task    = (FP)pfncEntry;
	ctsk.itskpri = (PRI)Priority;
	ctsk.stksz   = (SIZE)StackSize;
	ctsk.stk     = NULL;
	erid = acre_tsk(&ctsk);
	if ( erid < 0 )
	{
		return SYSPRC_HANDLE_NULL;
	}

	return (SYSPRC_HANDLE)erid;
}

/* end of file */

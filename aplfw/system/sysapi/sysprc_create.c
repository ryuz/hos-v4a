/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  system.h
 * @brief %jp{システム用API定義}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "sysapi_local.h"



/* プロセス生成 */
SYSPRC_HANDLE SysPrc_Create(void (*pfncEntry)(void), VPARAM Param, void *pStack, MEMSIZE StackSize, int Priority, int iAttr)
{
	T_CTSK ctsk;
	ER_ID  erid;
	
	/* タスク生成 */
	ctsk.tskatr  = TA_HLNG;
	ctsk.exinf   = (VP_INT)0;
	ctsk.task    = (FP)pfncEntry;
	ctsk.itskpri = (PRI)Priority;
	ctsk.stksz   = (SIZE)StackSize;
	ctsk.stk     = pStack;
	erid = acre_tsk(&ctsk);
	if ( erid < 0 )
	{
		return SYSPRC_HANDLE_NULL;
	}
	
	/* 計測カウンタ初期化 */
	SysPrc_InfTbl[erid].Param = Param;
	
	/* 計測カウンタ初期化 */
	SysPrc_SetExecTime((SYSPRC_HANDLE)erid, 0);
		
	return (SYSPRC_HANDLE)erid;
}



/* end of file */

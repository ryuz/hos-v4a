/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  kchg_pri.c
 * @brief %jp{タスク優先度の変更}
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"


/** %jp{タスク優先度の変更} */
void _kernel_chg_pri(_KERNEL_T_TSKHDL tskhdl, PRI tskpri)
{
	_KERNEL_T_TCB_PTR  tcb;
	
	/* %jp{タスクハンドルを取得} */
	tcb = _KERNEL_TSK_TSKHDL2TCB(tskhdl);
	
	/* %jp{新しいタスク優先度を設定} */
	_KERNEL_TSK_SET_TSKPRI(tcb, tskpri);
	
	
	/* %jp{レディーキューを繋ぎ直す} */
	if ( _KERNEL_TSK_SNS_RDY(tcb) )
	{
		_KERNEL_SYS_RMV_RDQ(tskhdl);
		_KERNEL_SYS_ADD_RDQ(tskhdl);
	}
}


/* end of file */

/**
 *  Hyper Operating System V4 Advance
 *
 * @file  add_rdq.c
 * @brief %jp{タスクをレディーキューに追加}%en{Add the task to the ready-queue}
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"


#if _KERNEL_RDQ_ALGORITHM == _KERNEL_RDQ_ALG_ARRAYED_QUE

/** %jp{タスクをレディーキューに追加}%en{Add the task to the ready-queue}
 * @param  rdqcb  %jp{追加するレディーキュー}%en{pointer of ready-queue}
 * @param  tskhdl %jp{追加するタスクのハンドル}%en{handle of task}
 * @return void
 */
void _kernel_add_rdq(_KERNEL_T_RDQCB *rdqcb, _KERNEL_T_TSKHDL tskhdl)
{
	_KERNEL_T_TCB_PTR	tcb;
	PRI					tskpri;

	/* %jp{TCB取得} */
	tcb = _KERNEL_TSK_TSKHDL2TCB(tskhdl);

	/* %jp{タスク優先度を取得} */
	tskpri = _KERNEL_TSK_GET_TSKPRI(tcb);
	
	/* %jp{キューに追加} */
	_KERNEL_ADP_QUE(&rdqcb->que[tskpri-1], tskhdl);
}


#endif	/* _KERNEL_RDQ_ALGORITHM */



/* end of file */

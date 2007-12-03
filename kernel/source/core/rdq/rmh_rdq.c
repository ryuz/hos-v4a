/**
 *  Hyper Operating System V4 Advance
 *
 * @file  rmh_rdq.c
 * @brief %jp{レディーキューの先頭タスクの取り外し}%en{Remove the task to the ready-queue}
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"


#if _KERNEL_RDQ_ALGORITHM == _KERNEL_RDQ_ALG_ARRAYED_QUE

/** %jp{レディーキューの先頭タスクの取り外し}%en{Remove the task to the ready-queue}
 * @param  rdqcb  %jp{取り外すレディーキュー}%en{pointer of ready-queue}
 * @return void
 */
_KERNEL_T_TSKHDL _kernel_rmh_rdq(_KERNEL_T_RDQCB *rdqcb)
{
	_KERNEL_T_TSKHDL	tskhdl;
	PRI					tskpri;
	
	for ( tskpri = 0; tskpri < _KERNEL_TSK_TMAX_TPRI; tskpri++ )
	{
		tskhdl = _KERNEL_RMH_QUE(&rdqcb->que[tskpri]);
		if ( tskhdl != _KERNEL_TSKHDL_NULL )
		{
			return tskhdl;
		}
	}
	
	return _KERNEL_TSKHDL_NULL;
}


#endif	/* _KERNEL_RDQ_ALGORITHM */



/* end of file */

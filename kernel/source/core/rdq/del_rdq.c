/**
 *  Hyper Operating System V4 Advance
 *
 * @file  del_rdq.c
 * @brief %jp{レディーキューの削除}%en{delete ready-queue}
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"


#if _KERNEL_RDQ_ALGORITHM == _KERNEL_RDQ_ALG_ARRAYED_QUE

/** %jp{レディーキューの削除}%en{delete ready-queue}
 * @param  rdqcb  %jp{削除するレディーキュー}%en{pointer of ready-queue}
 * @return void
 */
void _kernel_del_rdq(_KERNEL_T_RDQCB *rdqcb)
{
	PRI	tskpri;
	
	for ( tskpri = 0; tskpri < _KERNEL_TSK_TMAX_TPRI; tskpri++ )
	{
		_KERNEL_DEL_QUE(&rdqcb->que[tskpri]);
	}
}


#endif	/* _KERNEL_RDQ_ALGORITHM */



/* end of file */

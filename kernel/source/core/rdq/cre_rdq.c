/**
 *  Hyper Operating System V4 Advance
 *
 * @file  cre_rdq.c
 * @brief %jp{レディーキューの生成}%en{create ready-queue}
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"


#if _KERNEL_RDQ_ALGORITHM == _KERNEL_RDQ_ALG_ARRAYED_QUE

/** %jp{レディーキューの生成}%en{create ready-queue}
 * @param  rdqcb  %jp{生成するレディーキュー}%en{pointer of ready-queue}
 * @return void
 */
void _kernel_cre_rdq(_KERNEL_T_RDQCB *rdqcb)
{
	PRI	tskpri;
	
	for ( tskpri = 0; tskpri < _KERNEL_TSK_TMAX_TPRI; tskpri++ )
	{
		_KERNEL_CRE_QUE(&rdqcb->que[tskpri]);
	}
}


#endif	/* _KERNEL_RDQ_ALGORITHM */



/* end of file */

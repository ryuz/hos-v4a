/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  kadd_mtx.c
 * @brief %jp{ミューテックスをTCBに接続}%en{}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/mtxobj.h"


/**< %jp{タスクからミューテックスを取り外し} */
void _kernel_rmv_mtx(_KERNEL_T_MTXHDL mtxhdl, _KERNEL_T_TSKHDL tskhdl)
{
	_KERNEL_T_MTXCB_PTR		mtxcb;
	_KERNEL_T_TCB_PTR 		tcb;
	_KERNEL_T_MTXHDL		mtxhdl_head;
	_KERNEL_T_MTXHDL		mtxhdl_next;
	_KERNEL_T_MTXHDL		mtxhdl_prev;
	_KERNEL_T_MTXCB_PTR		mtxcb_next;
	_KERNEL_T_MTXCB_PTR		mtxcb_prev;
	
	mtxcb = _KERNEL_MTX_MTXHDL2MTXCB(mtxhdl);
	tcb   = _KERNEL_TSK_TSKHDL2TCB(tskhdl);

	_KERNEL_MTX_SET_TSKHDL(mtxcb, _KERNEL_TSKHDL_NULL);
	
	/* 取り外す */
	mtxhdl_next = _KERNEL_MTX_GET_NEXT(mtxcb);
	if ( mtxhdl_next == mtxhdl )
	{
		/* %jp{最後の１つを取り外し} */
		_KERNEL_TSK_SET_MTXHDL(tcb, _KERNEL_MTXHDL_NULL);
	}
	else
	{
		/* %jp{前後の接続を取得} */
		mtxcb_next  = _KERNEL_MTX_MTXHDL2MTXCB(mtxhdl_next);
		mtxhdl_prev = _KERNEL_MTX_GET_PREV(mtxcb_next);
		mtxcb_prev  = _KERNEL_MTX_MTXHDL2MTXCB(mtxhdl_prev);
		
		/* %jp{接続解除} */
		_KERNEL_MTX_SET_PREV(mtxcb_next, mtxhdl_prev);
		_KERNEL_MTX_SET_NEXT(mtxcb_prev, mtxhdl_next);
		
		/* %jp{先頭ならずらす} */
		mtxhdl_head = _KERNEL_TSK_GET_MTXHDL(tcb);
		if ( mtxhdl_head == mtxhdl )
		{
			_KERNEL_TSK_SET_MTXHDL(tcb, mtxhdl_next);
		}
	}
	
	/* %jp{待ちタスクがあれば起す} */
	tskhdl = _KERNEL_MTX_RMH_QUE(mtxcb);
	if ( tskhdl != _KERNEL_TSKHDL_NULL )
	{
		/* %jp{TCB取得} */
		tcb = _KERNEL_TSK_TSKHDL2TCB(tskhdl);
		
		/* ミューテックを繋ぐ */
		_kernel_add_mtx(mtxhdl, tskhdl);
		
		/* %jp{タスク待ち解除} */
		_KERNEL_TSK_SET_ERCD(tcb, E_OK);			/* %jp{エラーコード設定} */
		_KERNEL_DSP_WUP_TSK(tskhdl);				/* %jp{タスクの待ち解除} */
		_KERNEL_MTX_RMV_TOQ(tskhdl);
	}
}


/* end of file */

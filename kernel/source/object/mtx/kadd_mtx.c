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


/** %jp{タスクにミューテックスを接続} */
void _kernel_add_mtx(_KERNEL_T_MTXHDL mtxhdl, _KERNEL_T_TSKHDL tskhdl)
{
	_KERNEL_T_MTXCB_PTR		mtxcb;
	_KERNEL_T_TCB_PTR 		tcb;
	_KERNEL_T_MTXHDL		mtxhdl_head;
	
	mtxcb = _KERNEL_MTX_MTXHDL2MTXCB(mtxhdl);
	tcb   = _KERNEL_TSK_TSKHDL2TCB(tskhdl);

	_KERNEL_MTX_SET_TSKHDL(mtxcb, tskhdl);
	

	mtxhdl_head = _KERNEL_TSK_GET_MTXHDL(tcb);
	if ( mtxhdl_head == _KERNEL_MTXHDL_NULL )
	{
		/* %jp{最初の１つを接続} */
		_KERNEL_TSK_SET_MTXHDL(tcb, mtxhdl);
		_KERNEL_MTX_SET_NEXT(mtxcb, mtxhdl);
		_KERNEL_MTX_SET_PREV(mtxcb, mtxhdl);
	}
	else
	{
		_KERNEL_T_MTXHDL	mtxhdl_next;
		_KERNEL_T_MTXHDL	mtxhdl_prev;
		_KERNEL_T_MTXCB_PTR	mtxcb_next;
		_KERNEL_T_MTXCB_PTR	mtxcb_prev;
		
		/* %jp{接続の先頭/末尾を取得} */
		mtxhdl_next = mtxhdl_head;
		mtxcb_next  = _KERNEL_MTX_MTXHDL2MTXCB(mtxhdl_next);
		mtxhdl_prev = _KERNEL_MTX_GET_PREV(mtxcb_next);
		mtxcb_prev  = _KERNEL_MTX_MTXHDL2MTXCB(mtxhdl_prev);
		
		/* %jp{末尾に接続} */
		_KERNEL_MTX_SET_PREV(mtxcb_next, mtxhdl);
		_KERNEL_MTX_SET_NEXT(mtxcb_prev, mtxhdl);
		_KERNEL_MTX_SET_NEXT(mtxcb, mtxhdl_next);
		_KERNEL_MTX_SET_PREV(mtxcb, mtxhdl_prev);
	}
}


/* end of file */

/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  rmh_que.h
 * @brief %jp{キュー先頭タスクの取り出し}%en{}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"



#if _KERNEL_CFG_QUE_ALGORITHM == _KERNEL_QUE_ALG_ONEWAYLIST		/* %en{One-way list} %jp{単方向リスト} */


/** %jp{キュー先頭タスクの取り出し}%en{}
 * @param	pk_que  %jp{取り出すキュー}%en{queue}
 * @return	void
 */
_KERNEL_T_TSKHDL _kernel_rmh_que(
		_KERNEL_T_QUE *pk_que)
{
	_KERNEL_T_TSKHDL tskhdl_head;
	_KERNEL_T_TSKHDL tskhdl_tail;
	_KERNEL_T_TCB    *tcb_head;
	_KERNEL_T_TCB    *tcb_tail;

	tskhdl_tail = _KERNEL_QUE_GET_TAIL(pk_que);
	if ( tskhdl_tail == _KERNEL_TSKHDL_NULL )
	{
		return _KERNEL_TSKHDL_NULL;
	}
	
	tcb_tail    = _KERNEL_TSK_TSKHDL2TCB(tskhdl_tail);
	tskhdl_head = _KERNEL_TSK_GET_QUENEXT(tcb_tail);
	tcb_head    = _KERNEL_TSK_TSKHDL2TCB(tskhdl_head);

	if ( tskhdl_head == tskhdl_tail )
	{
		_KERNEL_QUE_SET_TAIL(pk_que, _KERNEL_TSKHDL_NULL);
	}
	else
	{
		_KERNEL_TSK_SET_QUENEXT(tcb_tail, _KERNEL_TSK_GET_QUENEXT(tcb_head));
	}
	
	_KERNEL_TSK_SET_QUE(tcb_head, NULL);

	return tskhdl_head;
}


#elif _KERNEL_CFG_QUE_ALGORITHM == _KERNEL_QUE_ALG_TWOWAYLIST		/* %en{Two-way list} %jp{双方向リスト} */



/** %jp{キュー先頭タスクの取り出し}%en{}
 * @param	pk_que  %jp{取り出すキュー}%en{queue}
 * @return	void
 */
_KERNEL_T_TSKHDL _kernel_rmh_que(
		_KERNEL_T_QUE *pk_que)
{
	_KERNEL_T_TSKHDL tskhdl_head;
	_KERNEL_T_TSKHDL tskhdl_next;
	_KERNEL_T_TSKHDL tskhdl_prev;
	_KERNEL_T_TCB    *tcb_head;

	tskhdl_head = _KERNEL_QUE_GET_HEAD(pk_que);
	if ( tskhdl_head == _KERNEL_TSKHDL_NULL )
	{
		return _KERNEL_TSKHDL_NULL;
	}

	tcb_head    = _KERNEL_TSK_TSKHDL2TCB(tskhdl_head);
	tskhdl_next = _KERNEL_TSK_GET_QUENEXT(tcb_head);
	if ( tskhdl_head == tskhdl_next )
	{
		_KERNEL_QUE_SET_HEAD(pk_que, _KERNEL_TSKHDL_NULL);
	}
	else
	{
		tskhdl_prev = _KERNEL_TSK_GET_QUEPREV(tcb_head);
		_KERNEL_TSK_SET_QUENEXT(_KERNEL_TSK_TSKHDL2TCB(tskhdl_prev), tskhdl_next);
		_KERNEL_TSK_SET_QUEPREV(_KERNEL_TSK_TSKHDL2TCB(tskhdl_next), tskhdl_prev);
		_KERNEL_QUE_SET_HEAD(pk_que, tskhdl_next);
	}

	_KERNEL_TSK_SET_QUE(tcb_head, NULL);

	return tskhdl_head;
}


#endif



/* end of file */

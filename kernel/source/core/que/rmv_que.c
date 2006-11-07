/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  knl_que.h
 * @brief %en{queue object heder file}%jp{キューオブジェクトのヘッダファイル}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"



#if _KERNEL_CFG_QUE_ALGORITHM == _KERNEL_QUE_ALG_ONEWAYLIST		/* %en{One-way list} %jp{単方向リスト} */


/** %en{Remove the task from the queuqe} %jp{タスクをから取り外す}
 * @param	ptr   %en{pointer of task}%jp{取り外すタスク}
 * @return	void
 */
void _kernel_rmv_que(
		_KERNEL_T_QUE    *pk_que,
		_KERNEL_T_TSKHDL tskhdl)
{
	_KERNEL_T_TSKHDL tskhdl_next;
	_KERNEL_T_TSKHDL tskhdl_prev;
	_KERNEL_T_TCB    *tcb;
	_KERNEL_T_TCB    *tcb_next;
	_KERNEL_T_TCB    *tcb_prev;

	/* %jp{TCB取得} */
	tcb = _KERNEL_TSK_TSKHDL2TCB(tskhdl);

	tskhdl_next = _KERNEL_TSK_GET_QUENEXT(tcb);
	if ( tskhdl_next == tskhdl )	/* last one */
	{
		_KERNEL_QUE_SET_TAIL(pk_que, _KERNEL_TSKHDL_NULL);
	}
	else
	{
		tskhdl_prev = _KERNEL_QUE_GET_TAIL(pk_que);
		tcb_prev    = _KERNEL_TSK_TSKHDL2TCB(tskhdl_prev);
		for ( ; ; )
		{
			tskhdl_next = _KERNEL_TSK_GET_QUENEXT(tcb_prev);
			if ( tskhdl_next == tskhdl )
			{
				break;
			}
			tskhdl_prev = tskhdl_next;
			tcb_prev    = _KERNEL_TSK_TSKHDL2TCB(tskhdl_prev);
		}
		tcb_next    = _KERNEL_TSK_TSKHDL2TCB(tskhdl_next);
		tskhdl_next = _KERNEL_TSK_GET_QUENEXT(tcb_next);

		_KERNEL_TSK_SET_QUENEXT(tcb_prev, tskhdl_next);
		if ( tskhdl == _KERNEL_QUE_GET_TAIL(pk_que) )
		{
			_KERNEL_QUE_SET_TAIL(pk_que, tskhdl_prev);
		}
	}
	
	_KERNEL_TSK_SET_QUE(tcb, NULL);
}


#elif _KERNEL_CFG_QUE_ALGORITHM == _KERNEL_QUE_ALG_TWOWAYLIST		/* %en{Two-way list} %jp{双方向リスト} */


/** %en{Remove the task from the queuqe} %jp{タスクをから取り外す}
 * @param	ptr   %en{pointer of task}%jp{取り外すタスク}
 * @return	void
 */
void _kernel_rmv_que(
		_KERNEL_T_QUE    *pk_que,
		_KERNEL_T_TSKHDL tskhdl)
{
	_KERNEL_T_TSKHDL tskhdl_next;
	_KERNEL_T_TSKHDL tskhdl_prev;
	_KERNEL_T_TCB    *tcb;

	/* %jp{TCB取得} */
	tcb = _KERNEL_TSK_TSKHDL2TCB(tskhdl);

	tskhdl_next = _KERNEL_TSK_GET_QUENEXT(tcb);
	if ( tskhdl_next == tskhdl )	/* last one */
	{
		_KERNEL_QUE_SET_HEAD(pk_que, _KERNEL_TSKHDL_NULL);
	}
	else
	{
		tskhdl_prev = _KERNEL_TSK_GET_QUEPREV(tcb);
		
		_KERNEL_TSK_SET_QUENEXT(_KERNEL_TSK_TSKHDL2TCB(tskhdl_prev), tskhdl_next);
		_KERNEL_TSK_SET_QUEPREV(_KERNEL_TSK_TSKHDL2TCB(tskhdl_next), tskhdl_prev);
		if ( tskhdl == _KERNEL_QUE_GET_HEAD(pk_que) )
		{
			_KERNEL_QUE_SET_HEAD(pk_que, tskhdl_next);
		}
	}
	
	_KERNEL_TSK_SET_QUE(tcb, NULL);
}


#endif



/* end of file */

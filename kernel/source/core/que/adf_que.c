/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  adf_que.h
 * @brief %en{Add the task to queue in order of FIFO}%jp{FIFO順でキューにタスクを追加}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"



#if _KERNEL_CFG_QUE_ALGORITHM == _KERNEL_QUE_ALG_ONEWAYLIST		/* %en{One-way list} %jp{単方向リスト} */


/** %en{Add the task to queue in order of FIFO}%jp{FIFO順でキューにタスクを追加}
 * @param	que   %en{pointer of queue}%jp{追加するキュー}
 * @param	ptr   %en{pointer of task}%jp{追加するタスク}
 * @return	void
 */
void _kernel_adf_que(
		_KERNEL_T_QUE    *pk_que,
		_KERNEL_T_TSKHDL tskhdl)
{
	_KERNEL_T_TSKHDL tskhdl_tail;
	_KERNEL_T_TCB    *tcb;
	_KERNEL_T_TCB    *tcb_tail;

	/* %jp{TCB取得} */
	tcb = _KERNEL_TSK_TSKHDL2TCB(tskhdl);

	/* %jp{タスクに所属キューを設定} */
	_KERNEL_TSK_SET_QUE(tcb, pk_que);

	/* %jp{キュー末尾のタスクを取得} */
	tskhdl_tail = _KERNEL_QUE_GET_TAIL(pk_que);

	if ( tskhdl_tail == _KERNEL_TSKHDL_NULL )	/* queue is empty */
	{
		_KERNEL_TSK_SET_QUENEXT(tcb, tskhdl);
	}
	else	/* queue is not empty */
	{
		tcb_tail = _KERNEL_TSK_TSKHDL2TCB(tskhdl_tail);
		_KERNEL_TSK_SET_QUENEXT(tcb, _KERNEL_TSK_GET_QUENEXT(tcb_tail));
		_KERNEL_TSK_SET_QUENEXT(tcb_tail, tskhdl);
	}
	_KERNEL_QUE_SET_TAIL(pk_que, tskhdl);
}


#elif _KERNEL_CFG_QUE_ALGORITHM == _KERNEL_QUE_ALG_TWOWAYLIST		/* %en{Two-way list} %jp{双方向リスト} */


/** %en{Add the task to queue in order of FIFO}%jp{FIFO順でキューにタスクを追加}
 * @param	que   %en{pointer of queue}%jp{追加するキュー}
 * @param	ptr   %en{pointer of task}%jp{追加するタスク}
 * @return	void
 */
void _kernel_adf_que(
		_KERNEL_T_QUE    *pk_que,
		_KERNEL_T_TSKHDL tskhdl)
{
	_KERNEL_T_TSKHDL tskhdl_head;
	_KERNEL_T_TSKHDL tskhdl_tail;
	_KERNEL_T_TCB    *tcb;
	_KERNEL_T_TCB    *tcb_head;
	_KERNEL_T_TCB    *tcb_tail;
	
	/* %jp{TCB取得} */
	tcb = _KERNEL_TSK_TSKHDL2TCB(tskhdl);

	/* %jp{タスクに所属キューを設定} */
	_KERNEL_TSK_SET_QUE(tcb, pk_que);

	/* %jp{キュー先頭のタスクを取得} */
	tskhdl_head = _KERNEL_QUE_GET_HEAD(pk_que);

	if ( tskhdl_head == _KERNEL_TSKHDL_NULL )	/* queue is empty */
	{
		/* %jp{キューにタスクが無ければ先頭に設定} */
		_KERNEL_QUE_SET_HEAD(pk_que, tskhdl);
		_KERNEL_TSK_SET_QUENEXT(tcb, tskhdl);
		_KERNEL_TSK_SET_QUEPREV(tcb, tskhdl);
	}
	else	/* queue is not empty */
	{
		/* %jp{キュー末尾に追加} */
		tcb_head    = _KERNEL_TSK_TSKHDL2TCB(tskhdl_head);
		tskhdl_tail = _KERNEL_TSK_GET_QUEPREV(tcb_head);
		tcb_tail    = _KERNEL_TSK_TSKHDL2TCB(tskhdl_tail);
		_KERNEL_TSK_SET_QUENEXT(tcb, tskhdl_head);
		_KERNEL_TSK_SET_QUEPREV(tcb, tskhdl_tail);
		_KERNEL_TSK_SET_QUENEXT(tcb_tail, tskhdl);
		_KERNEL_TSK_SET_QUEPREV(tcb_head, tskhdl);
	}
}


#endif



/* end of file */

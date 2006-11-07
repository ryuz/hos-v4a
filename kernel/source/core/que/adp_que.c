/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  adp_que.c
 * @brief %en{Add the task to the queue in the order of the task's priority}%jp{タスクを優先度順でキューに追加}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"



#if _KERNEL_CFG_QUE_ALGORITHM == _KERNEL_QUE_ALG_ONEWAYLIST		/* %en{One-way list} %jp{単方向リスト} */


/** %en{Add the task to the queue in the order of the task's priority}%jp{タスクを優先度順でキューに追加}
 * @param	que   %en{pointer of queue}%jp{追加するキュー}
 * @param	ptr   %en{pointer of task}%jp{追加するタスク}
 * @return	void
 */
void _kernel_adp_que(
		_KERNEL_T_QUE    *pk_que,
		_KERNEL_T_TSKHDL tskhdl)
{
	_KERNEL_T_TSKHDL tskhdl_tail;
	_KERNEL_T_TSKHDL tskhdl_next;
	_KERNEL_T_TSKHDL tskhdl_prev;
	_KERNEL_T_TCB    *tcb;
	_KERNEL_T_TCB    *tcb_next;
	_KERNEL_T_TCB    *tcb_prev;
	PRI              tskpri;
	PRI              tskpri_next;

	/* %jp{TCB取得} */
	tcb = _KERNEL_TSK_TSKHDL2TCB(tskhdl);

	/* %jp{タスクに所属キューを設定} */
	_KERNEL_TSK_SET_QUE(tcb, pk_que);

	/* %jp{キュー末尾のタスクを取得} */
	tskhdl_tail = _KERNEL_QUE_GET_TAIL(pk_que);

	if ( tskhdl_tail == _KERNEL_TSKHDL_NULL )		/* %en{the queue is empty}%jp{キューにタスクが無ければ先頭に設定} */
	{
		_KERNEL_TSK_SET_QUENEXT(tcb, tskhdl);
		_KERNEL_QUE_SET_TAIL(pk_que, tskhdl);
	}
	else	/* %en{que is not empty}%jp{キューが空でないなら挿入位置を探索} */
	{
		/* %jp{タスク優先度を取得} */
		tskpri = _KERNEL_TSK_GET_TSKPRI(tcb);

		/* %jp{先頭から探索} */
		tskhdl_prev = tskhdl_tail;
		tcb_prev    = _KERNEL_TSK_TSKHDL2TCB(tskhdl_prev);
		tskhdl_next = _KERNEL_TSK_GET_QUENEXT(tcb_prev);
		tcb_next    = _KERNEL_TSK_TSKHDL2TCB(tskhdl_next);
		
		for ( ; ; )
		{
			/* %jp{優先度取り出し} */
			tskpri_next = _KERNEL_TSK_GET_TSKPRI(tcb_next);
			
			if ( tskpri_next > tskpri )
			{
				break;
			}
			
			/* %jp{次を探す} */
			tskhdl_prev = tskhdl_next;
			tcb_prev    = tcb_next;
			tskhdl_next = _KERNEL_TSK_GET_QUENEXT(tcb_next);
			tcb_next    = _KERNEL_TSK_TSKHDL2TCB(tskhdl_next);
			
			/* %jp{末尾なら抜ける} */
			if ( tskhdl_prev == tskhdl_tail )
			{
				_KERNEL_QUE_SET_TAIL(pk_que, tskhdl);
				break;
			}
		}
		
		/* %jp{挿入} */
		_KERNEL_TSK_SET_QUENEXT(tcb_prev, tskhdl);
		_KERNEL_TSK_SET_QUENEXT(tcb, tskhdl_next);
	}
}


#elif _KERNEL_CFG_QUE_ALGORITHM == _KERNEL_QUE_ALG_TWOWAYLIST		/* %en{Two-way list} %jp{双方向リスト} */


/** %en{Add the task to the queue in the order of the task's priority}%jp{タスクを優先度順でキューに追加}
 * @param	que   %en{pointer of queue}%jp{追加するキュー}
 * @param	ptr   %en{pointer of task}%jp{追加するタスク}
 * @return	void
 */
void _kernel_adp_que(
		_KERNEL_T_QUE    *pk_que,
		_KERNEL_T_TSKHDL tskhdl)
{
	_KERNEL_T_TSKHDL tskhdl_head;
	_KERNEL_T_TSKHDL tskhdl_next;
	_KERNEL_T_TSKHDL tskhdl_prev;
	_KERNEL_T_TCB    *tcb;
	_KERNEL_T_TCB    *tcb_next;
	_KERNEL_T_TCB    *tcb_prev;
	PRI              tskpri;
	PRI              tskpri_next;


	/* %jp{TCB取得} */
	tcb = _KERNEL_TSK_TSKHDL2TCB(tskhdl);

	/* %jp{タスクに所属キューを設定} */
	_KERNEL_TSK_SET_QUE(tcb, pk_que);

	/* %jp{キュー末尾のタスクを取得} */
	tskhdl_head = _KERNEL_QUE_GET_HEAD(pk_que);
	
	if ( tskhdl_head == _KERNEL_TSKHDL_NULL )		/* %en{the queue is empty}%jp{キューにタスクが無ければ先頭に設定} */
	{
		_KERNEL_TSK_SET_QUENEXT(tcb, tskhdl);
		_KERNEL_TSK_SET_QUEPREV(tcb, tskhdl);
		_KERNEL_QUE_SET_HEAD(pk_que, tskhdl);
	}
	else	/* %en{que is not empty}%jp{キューが空でないなら挿入位置を探索} */
	{
		/* %jp{タスク優先度を取得} */
		tskpri = _KERNEL_TSK_GET_TSKPRI(tcb);
		
		/* %jp{先頭から探索} */
		tskhdl_next = tskhdl_head;
		tcb_next    = _KERNEL_TSK_TSKHDL2TCB(tskhdl_next);
		
		do
		{
			/* %jp{優先度取り出し} */
			tskpri_next = _KERNEL_TSK_GET_TSKPRI(tcb_next);
			
			if ( tskpri_next > tskpri )
			{
				if ( tskhdl_next == tskhdl_head )	/* %jp{挿入位置が先頭だった場合} */
				{
					tskhdl_prev = _KERNEL_TSK_GET_QUEPREV(tcb_next);
					tcb_prev    = _KERNEL_TSK_TSKHDL2TCB(tskhdl_prev);
					_KERNEL_QUE_SET_HEAD(pk_que, tskhdl);
				}
				break;
			}
			
			/* %jp{次を探す} */
			tskhdl_prev = tskhdl_next;
			tcb_prev    = tcb_next;
			tskhdl_next = _KERNEL_TSK_GET_QUENEXT(tcb_next);
			tcb_next    = _KERNEL_TSK_TSKHDL2TCB(tskhdl_next);
		} while ( tskhdl_next != tskhdl_head );
		
		/* %jp{挿入} */
		_KERNEL_TSK_SET_QUENEXT(tcb, tskhdl_next);
		_KERNEL_TSK_SET_QUEPREV(tcb, tskhdl_prev);
		_KERNEL_TSK_SET_QUENEXT(tcb_prev, tskhdl);
		_KERNEL_TSK_SET_QUEPREV(tcb_next, tskhdl);
	}
}


#endif



/* end of file */

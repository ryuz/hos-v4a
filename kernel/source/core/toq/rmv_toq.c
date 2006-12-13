/**
 *  Hyper Operating System V4 Advance
 *
 * @file  rmv_toq.c
 * @brief %jp{タスクをタイムアウトキューから削除}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"


#if _KERNEL_SPT_TOQ

/* タイムアウト待ち行列からタスクを取り除く */
void _kernel_rmv_toq(
		_KERNEL_T_TOQCB  *toqcb,
		_KERNEL_T_TSKHDL tskhdl)	/* 待ち行列から削除するタスク */
{
	_KERNEL_T_TSKHDL tskhdl_prev;
	_KERNEL_T_TSKHDL tskhdl_next;
	_KERNEL_T_TCB    *tcb;
	_KERNEL_T_TCB    *tcb_prev;
	_KERNEL_T_TCB    *tcb_next;

	/* %jp{TCB取得} */
	tcb = _KERNEL_TSK_TSKHDL2TCB(tskhdl);

	tskhdl_prev = _KERNEL_TSK_GET_TOQPREV(tcb);

	/* タイムアウトキューに未接続なら無視 */
	if ( tskhdl_prev == _KERNEL_TSKHDL_NULL )
	{
		return;
	}
	
	/* キューの最後の１つタスクなら */
	if ( tskhdl_prev == tskhdl )
	{
		_KERNEL_TOQ_SET_HEAD(toqcb, _KERNEL_TSKHDL_NULL);		/* タイムアウトキューを空にする */
	}
	else
	{
		tskhdl_next = _KERNEL_TSK_GET_TOQNEXT(tcb);
		tcb_next    = _KERNEL_TSK_TSKHDL2TCB(tskhdl_next);
		tskhdl_prev = _KERNEL_TSK_GET_TOQPREV(tcb);
		tcb_prev    = _KERNEL_TSK_TSKHDL2TCB(tskhdl_prev);

		/* 末尾でなければ */
		if ( tskhdl_next != _KERNEL_TOQ_GET_HEAD(toqcb) )
		{
			/* 時間差分を清算 */
			_KERNEL_TSK_SET_TOQDIFTIM(tcb_next, _KERNEL_TSK_GET_TOQDIFTIM(tcb_next) + _KERNEL_TSK_GET_TOQDIFTIM(tcb));
		}
		
		/* 先頭なら */
		if ( tskhdl == _KERNEL_TOQ_GET_HEAD(toqcb) )
		{
			_KERNEL_TOQ_SET_HEAD(toqcb, tskhdl_next);	/* 先頭位置更新 */
		}
		
		/* キューから外す */
		_KERNEL_TSK_SET_TOQNEXT(tcb_prev, tskhdl_next);
		_KERNEL_TSK_SET_TOQPREV(tcb_next, tskhdl_prev);
	}
	
	/* 未接続に設定 */
	_KERNEL_TSK_SET_TOQPREV(tcb, _KERNEL_TSKHDL_NULL);
}

#endif	/* _KERNEL_SPT_TOQ */


/* end of file */

/**
 *  Hyper Operating System V4 Advance
 *
 * @file  add_toq.c
 * @brief %jp{タスクをタイムアウトキューに追加}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"


#if _KERNEL_SPT_TOQ

/** %jp{タイムアウト待ち行列にタスクを追加} */
void _kernel_add_toq(
		_KERNEL_T_TOQCB  *toqcb,
		_KERNEL_T_TSKHDL tskhdl,
		RELTIM           tmout)
{
	_KERNEL_T_TSKHDL tskhdl_head;
	_KERNEL_T_TSKHDL tskhdl_next;
	_KERNEL_T_TSKHDL tskhdl_prev;
	_KERNEL_T_TCB    *tcb;
	_KERNEL_T_TCB    *tcb_next;
	_KERNEL_T_TCB    *tcb_prev;
	RELTIM           tmout_next;

	/* %jp{TCB取得} */
	tcb = _KERNEL_TSK_TSKHDL2TCB(tskhdl);
	
	/* %jp{タイムアウトキューの先頭タスク取得} */
	tskhdl_head = _KERNEL_TOQ_GET_HEAD(toqcb);
	
	if ( tskhdl_head == _KERNEL_TSKHDL_NULL )
	{
		/* %jp{最初の１つをキューに登録} */
		_KERNEL_TSK_SET_TOQNEXT(tcb, tskhdl);
		_KERNEL_TSK_SET_TOQPREV(tcb, tskhdl);
		_KERNEL_TOQ_SET_HEAD(toqcb, tskhdl);

		/* %jp{タイムアウト時刻を設定} */
		_KERNEL_TSK_SET_TOQDIFTIM(tcb, tmout);

		return;
	}
	
	/* %jp{挿入場所を検索} */
	tskhdl_next = tskhdl_head;
	tcb_next    = _KERNEL_TSK_TSKHDL2TCB(tskhdl_next);
	tskhdl_prev = _KERNEL_TSK_GET_TOQPREV(tcb_next);
	tcb_prev    = _KERNEL_TSK_TSKHDL2TCB(tskhdl_prev);
	do
	{
		tmout_next = _KERNEL_TSK_GET_TOQDIFTIM(tcb_next);
		
		/* %jp{時間比較} */
		if ( tmout < tmout_next )
		{
			/* %jp{先頭なら} */
			if ( tskhdl_next == tskhdl_head )
			{
				_KERNEL_TOQ_SET_HEAD(toqcb, tskhdl);	/* %jp{先頭ポインタ更新} */
			}
			
			/* %jp{時間の差分を設定} */
			_KERNEL_TSK_SET_TOQDIFTIM(tcb_next, tmout_next - tmout);
			_KERNEL_TSK_SET_TOQDIFTIM(tcb, tmout);

			/* %jp{リストに挿入} */
			_KERNEL_TSK_SET_TOQNEXT(tcb, tskhdl_next);
			_KERNEL_TSK_SET_TOQPREV(tcb, tskhdl_prev);
			_KERNEL_TSK_SET_TOQNEXT(tcb_prev, tskhdl);
			_KERNEL_TSK_SET_TOQPREV(tcb_next, tskhdl);
			
			return;
		}
		
		tmout -= tmout_next;		/* %jp{差分を減算} */
		
		tskhdl_prev = tskhdl_next;
		tcb_prev    = tcb_next;
		tskhdl_next = _KERNEL_TSK_GET_TOQNEXT(tcb_next);		/* %jp{次のタスクへ進む} */
		tcb_next    = _KERNEL_TSK_TSKHDL2TCB(tskhdl_next);
	} while ( tskhdl_next != tskhdl_head );	/* %jp{リストを一周するまでループ} */

	/* 残った差分を設定 */
	_KERNEL_TSK_SET_TOQDIFTIM(tcb, tmout);

	/* %jp{末尾に追加} */
	_KERNEL_TSK_SET_TOQNEXT(tcb, tskhdl_next);
	_KERNEL_TSK_SET_TOQPREV(tcb, tskhdl_prev);
	_KERNEL_TSK_SET_TOQNEXT(tcb_prev, tskhdl);
	_KERNEL_TSK_SET_TOQPREV(tcb_next, tskhdl);
}

#endif	/* _KERNEL_SPT_TOQ */


/* end of file */

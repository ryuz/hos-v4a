/**
 *  Hyper Operating System V4 Advance
 *
 * @file  sig_toq.c
 * @brief %jp{タスクをタイムアウトキューに追加}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"


#if _KERNEL_SPT_TOQ

/* タイムアウトにタイムティック供給 */
void _kernel_sig_toq(
		_KERNEL_T_TOQCB *toqcb,
		RELTIM          tictim)		/* 追加するタイムティック */
{
	_KERNEL_T_TSKHDL tskhdl_next;
	_KERNEL_T_TSKHDL tskhdl_prev;
	_KERNEL_T_TSKHDL tskhdl;
	_KERNEL_T_TCB    *tcb;
	_KERNEL_T_TCB    *tcb_next;
	_KERNEL_T_TCB    *tcb_prev;
	_KERNEL_TSK_T_RELTIM diftim;

	/* %jp{先頭タスク取得} */
	tskhdl = _KERNEL_TOQ_GET_HEAD(toqcb);

	/* %jp{タイムアウトキューが空ならリターン} */
	if ( tskhdl == _KERNEL_TSKHDL_NULL )
	{
		return;
	}

	/* %jp{タイムアウトキューの処理} */
	for ( ; ; )
	{
		tcb = _KERNEL_TSK_TSKHDL2TCB(tskhdl);

		diftim = _KERNEL_TSK_GET_TOQDIFTIM(tcb);
		
		/* %jp{タイムアウトに達しないなら} */
		if ( diftim > tictim )
		{
			_KERNEL_TSK_SET_TOQDIFTIM(tcb, diftim - tictim);		/* %jp{タイムアウト時間を減算} */
			break;
		}
		
		tictim -= diftim;			/* %jp{タイムティックを減算} */
		
		_KERNEL_TSK_SET_ERCD(tcb, E_TMOUT);
		_KERNEL_DSP_WUP_TSK(tskhdl);

		_KERNEL_DSP_TSK();			/* %jp{遅延ディスパッチ予約を行う} */
		
		/* %jp{キューから外す} */
		tskhdl_next = _KERNEL_TSK_GET_TOQNEXT(tcb);
		tcb_next    = _KERNEL_TSK_TSKHDL2TCB(tskhdl_next);
		tskhdl_prev = _KERNEL_TSK_GET_TOQPREV(tcb);
		tcb_prev    = _KERNEL_TSK_TSKHDL2TCB(tskhdl_prev);
		if ( tskhdl_next == tskhdl )	/* %jp{最後の１つなら} */
		{
			/* %jp{キューを空にする} */
			_KERNEL_TSK_SET_TOQPREV(tcb, _KERNEL_TSKHDL_NULL);
			tskhdl = _KERNEL_TSKHDL_NULL;
			break;
		}
		
		/* %jp{キューから取り外す} */
		_KERNEL_TSK_SET_TOQNEXT(tcb_prev, tskhdl_next);
		_KERNEL_TSK_SET_TOQPREV(tcb_next, tskhdl_prev);
		_KERNEL_TSK_SET_TOQPREV(tcb, _KERNEL_TSKHDL_NULL);
		
		tskhdl = tskhdl_next;
		tcb    = tcb_next;
		
		/* %jp{ここで一度、多重割込みの機会を与えるべき？} */
	}
	
	/* %jp{メモリに書き戻す} */
	_KERNEL_TOQ_SET_HEAD(toqcb, tskhdl);
}

#endif	/* _KERNEL_SPT_TOQ */


/* end of file */

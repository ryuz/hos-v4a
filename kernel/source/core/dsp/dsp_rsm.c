/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  dsp_sta.c
 * @brief %jp{タスクの起床}%en{Wakeup Task}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"


/** %jp{タスクをサスペンド解除する} */
void _kernel_dsp_rsm_tsk(_KERNEL_T_TSKHDL tskhdl)
{
	_KERNEL_T_TCB_PTR     tcb;
	_KERNEL_TSK_T_TSKSTAT tskstat;

	/* %jp{TCBを取得} */
	tcb = _KERNEL_TSK_TSKHDL2TCB(tskhdl);

	/* %jp{現在の状態を取得} */
	tskstat = _KERNEL_TSK_GET_TSKSTAT(tcb);
	
	/* %jp{現在の状態を取得} */
	if ( !(tskstat & _KERNEL_TTS_WAI) )
	{
		/* %jp{レディーキューに接続} */
		_KERNEL_SYS_ADD_RDQ(tskhdl);
	}
	
	/* %jp{強制待ち状態を解除} */
	tskstat &= ~_KERNEL_TTS_SUS;
	_KERNEL_TSK_SET_TSKSTAT(tcb, tskstat);
}



/* end of file */

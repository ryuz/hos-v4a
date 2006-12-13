/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  dsp_sta.c
 * @brief %jp{他タスクを開始する}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"



/** %jp{他タスクを開始する} */
void _kernel_dsp_sta_tsk(_KERNEL_T_TSKHDL tskhdl)
{
	_KERNEL_T_TCB_PTR tcb;

	/* %jp{TCBを取得} */
	tcb = _KERNEL_TSK_TSKHDL2TCB(tskhdl);
	
	/* %jp{実行可能状態に設定} */
	_KERNEL_TSK_SET_TSKSTAT(tcb, _KERNEL_TTS_RDY);

	/* %jp{レディーキューに接続} */
	_KERNEL_SYS_ADD_RDQ(tskhdl);
}



/* end of file */

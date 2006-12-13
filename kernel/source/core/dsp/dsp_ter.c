/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  dsp_ter.c
 * @brief %jp{他タスクを終了する}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"


/** %jp{他タスクを終了する} */
void _kernel_dsp_ter_tsk(_KERNEL_T_TSKHDL tskhdl)
{
	_KERNEL_T_TCB_PTR tcb;

	/* %jp{TCBを取得} */
	tcb = _KERNEL_TSK_TSKHDL2TCB(tskhdl);

	/* %jp{休止状態に設定} */
	_KERNEL_TSK_SET_TSKSTAT(tcb, _KERNEL_TTS_DMT);
	
	/* %jp{レディーキューから取り外す} */
	_KERNEL_SYS_RMV_RDQ(tskhdl);
}



/* end of file */

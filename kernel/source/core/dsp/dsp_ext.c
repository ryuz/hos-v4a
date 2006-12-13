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


/** %jp{自タスクを終了する} */
void _kernel_dsp_ext_tsk(_KERNEL_T_TSKHDL tskhdl)
{
	_KERNEL_T_TCB_PTR tcb;

	/* %jp{TCBを取得} */
	tcb = _KERNEL_TSK_TSKHDL2TCB(tskhdl);

	/* %jp{休止状態に設定} */
	_KERNEL_TSK_SET_TSKSTAT(tcb, _KERNEL_TTS_DMT);
	
#if _KERNEL_RUNTSK_ON_RDQ
	/* %jp{レディーキューから取り外す} */
	_KERNEL_SYS_RMV_RDQ(tskhdl);
#endif
}



/* end of file */

/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  dsp_wup.c
 * @brief %jp{タスクを起こす}%en{Wakeup Task}
 *
 * Copyright (C) 1998-2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"


/** %jp{タスクを起こす}%en{Wakeup Task}
 * @param  tskhdl   %jp{起床対象のタスクハンドル}%en{Handle of the task to be woken up}
 * @retval void
 */
void _kernel_dsp_wup_tsk(_KERNEL_T_TSKHDL tskhdl)
{
	_KERNEL_T_TCB_PTR     tcb;
	_KERNEL_TSK_T_TSKSTAT tskstat;
	
	/* %jp{TCBを取得}%en{get TCB} */
	tcb = _KERNEL_TSK_TSKHDL2TCB(tskhdl);
	
	/* %jp{現在の状態を取得}%en{get current state} */
	tskstat = _KERNEL_TSK_GET_TSKSTAT(tcb);
	
#if _KERNEL_SPT_SUS_TSK	&& (_KERNEL_TMAX_SUSCNT > 0)	/* %jp{サスペンドありのモデルの場合}%en{Supported suspend mode} */
	if ( !(tskstat & _KERNEL_TTS_SUS) )
	{
		/* %jp{レディーキューに接続}%en{add to ready-queue} */
		_KERNEL_SYS_ADD_RDQ(tskhdl);
		tskstat = _KERNEL_TTS_RDY;
	}
	else
	{
		tskstat = _KERNEL_TTS_SUS;
	}
#else
	/* %jp{レディーキューに接続}%en{add to ready-queue} */
	_KERNEL_ADD_RDQ(tskhdl);
	tskstat = _KERNEL_TTS_RDY;
#endif
	
	/* %jp{待ち状態を解除}%en{set new state} */
	_KERNEL_TSK_SET_TSKSTAT(tcb, tskstat);
}



/* end of file */

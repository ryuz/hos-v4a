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
	_KERNEL_T_TCB_PTR		tcb;
	_KERNEL_TSK_T_TSKSTAT	tskstat;

	/* %jp{TCBを取得} */
	tcb = _KERNEL_TSK_TSKHDL2TCB(tskhdl);

	/* %jp{現在の状態を取得} */
	tskstat = _KERNEL_TSK_GET_TSKSTAT(tcb);

	if ( tskstat == _KERNEL_TTS_RDY )
	{
		/* %jp{レディーキューから削除} */
		_KERNEL_SYS_RMV_RDQ(tskhdl);
	}
	else
	{
		/* 待ちキューから取り外す */
		_KERNEL_SYS_RMV_TOQ(tskhdl);
		_KERNEL_TRM_QUE(tskhdl);
	}

	/* %jp{休止状態に設定} */
	_KERNEL_TSK_SET_TSKSTAT(tcb, _KERNEL_TTS_DMT);	
}



/* end of file */

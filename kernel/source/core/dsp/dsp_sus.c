/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  dsp_sus.c
 * @brief %jp{タスクをサスペンドする}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"


/** %jp{タスクをサスペンドする} */
void _kernel_dsp_sus_tsk(_KERNEL_T_TSKHDL tskhdl)
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
#if _KERNEL_RUNTSK_ON_RDQ
		/* %jp{レディーキューから取り外す} */
		_KERNEL_SYS_RMV_RDQ(tskhdl);
#else
		if ( tskhdl != _KERNEL_SYS_GET_RUNTSK() )
		{
			_KERNEL_SYS_RMV_RDQ(tskhdl);
		}
#endif
	}

	/* %jp{強制待ち状態に設定} */
	tskstat |= _KERNEL_TTS_SUS;
	_KERNEL_TSK_SET_TSKSTAT(tcb, tskstat);
}



/* end of file */

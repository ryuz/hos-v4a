/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  dsp_wai.c
 * @brief %jp{自タスクを待ち状態にする}
 *
 * @version $Id: dsp_wai.c,v 1.1 2006-09-03 13:19:31 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"



/** %jp{自タスクを待ち状態にする} */
void _kernel_dsp_wai_tsk(_KERNEL_T_TSKHDL tskhdl)
{
	_KERNEL_T_TCB_PTR tcb;

	/* %jp{TCBを取得} */
	tcb = _KERNEL_TSK_TSKHDL2TCB(tskhdl);

	/* %jp{待ち状態に設定} */
	_KERNEL_TSK_SET_TSKSTAT(tcb, _KERNEL_TTS_WAI);	

#if !_KERNEL_RUNTSK_ON_RDQ
	/* %jp{レディーキューから取り外す} */
	_KERNEL_RMV_RDQ(tskhdl);
#endif
}


/* end of file */

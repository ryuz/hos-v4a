/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  dsp_wup.c
 * @brief %jp{他タスクを待ち解除する}
 *
 * @version $Id: dsp_wup.c,v 1.2 2006-09-03 14:09:04 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"



/** %jp{他タスクを待ち解除する} */
void _kernel_dsp_wup_tsk(_KERNEL_T_TSKHDL tskhdl)
{
	_KERNEL_T_TCB_PTR     tcb;
	_KERNEL_TSK_T_TSKSTAT tskstat;

	/* %jp{TCBを取得} */
	tcb = _KERNEL_TSK_TSKHDL2TCB(tskhdl);

	/* %jp{現在の状態を取得} */
	tskstat = _KERNEL_TSK_GET_TSKSTAT(tcb);

#if _KERNEL_SPT_SUS_TSK	&& (_KERNEL_TMAX_SUSCNT > 0)	/* %jp{サスペンドありのモデルの場合} */
	if ( !(tskstat & _KERNEL_TTS_SUS) )
	{
		/* %jp{レディーキューに接続} */
		_KERNEL_ADD_RDQ(tskhdl);
		tskstat = _KERNEL_TTS_RDY;
	}
	else
	{
		tskstat = _KERNEL_TTS_SUS;
	}
#else
	/* %jp{レディーキューに接続} */
	_KERNEL_ADD_RDQ(tskhdl);
	tskstat = _KERNEL_TTS_RDY;
#endif

	/* %jp{待ち状態を解除} */
	_KERNEL_TSK_SET_TSKSTAT(tcb, tskstat);
}



/* end of file */

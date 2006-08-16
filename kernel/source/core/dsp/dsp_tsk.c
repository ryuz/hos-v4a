/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  dsp_tsk.c
 * @brief %en{Task dispatch}%jp{タスクディスパッチ}
 *
 * @version $Id: dsp_tsk.c,v 1.1 2006-08-16 16:27:03 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"



/** %jp{タスクディスパッチ}%en{Task dispatch}
 * @return void
 */
void _kernel_dsp_tsk(void)
{
	_KERNEL_T_TSKHDL tskhdl_run;
	_KERNEL_T_TSKHDL tskhdl_top;
	_KERNEL_T_CTXCB  *ctxcb_run;
	_KERNEL_T_CTXCB  *ctxcb_top;
	
	/* %jp{タスクディスパッチ不可なら保留して抜ける} */
	if ( _KERNEL_SYS_SNS_DPN() )
	{
		_KERNEL_SYS_SET_DLY();
		return;
	}
	
	/* %jp{タスクハンドルを取得} */
	tskhdl_run = _KERNEL_SYS_GET_RUNTSK();	/* %jp{実行中タスクを取得} */
	tskhdl_top = _KERNEL_REF_RDQ();			/* %jp{レディーキュー先頭タスクを取得} */
	
	
	/* %jp{コンテキスト取得} */
#if _KERNEL_SYSTSK_TCB

	ctxcb_run = _KERNEL_TSK_GET_CTXCB(_KERNEL_TSK_TSKHDL2TCB(tskhdl_run));	/* %jp{実行中タスクのコンテキストを取得} */
	ctxcb_top = _KERNEL_SYS_GET_SYSCTXCB();			/* %jp{レディーキュー先頭タスクのコンテキストを取得} */

#else

	/* %jp{実行中タスクのコンテキストを取得} */
	if ( tskhdl_run != _KERNEL_TSKHDL_NULL )
	{
		ctxcb_run = _KERNEL_TSK_GET_CTXCB(_KERNEL_TSK_TSKHDL2TCB(tskhdl_run));
	}
	else
	{
		ctxcb_run = _KERNEL_SYS_GET_SYSCTXCB();
	}

	/* %jp{レディーキュー先頭タスクのコンテキストを取得} */
	if ( tskhdl_top != _KERNEL_TSKHDL_NULL )
	{
		ctxcb_top = _KERNEL_TSK_GET_CTXCB(_KERNEL_TSK_TSKHDL2TCB(tskhdl_top));
	}
	else
	{
		ctxcb_top = _KERNEL_SYS_GET_SYSCTXCB();
	}

#endif
	
	/* %jp{実行タスクの登録} */
	_KERNEL_SYS_SET_RUNTSK(tskhdl_top);
	
	/* %jp{ディスパッチ実行} */
	_KERNEL_SWI_CTX(ctxcb_run, ctxcb_top);
}


/* end of file */

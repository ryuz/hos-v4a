/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  dsp_tsk.c
 * @brief %en{Task dispatch}%jp{タスクディスパッチ}
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
	_KERNEL_SYS_CLR_DLY();
	
	/* %jp{タスクハンドルを取得} */
	tskhdl_top = _KERNEL_SYS_REF_RDQ();		/* %jp{レディーキュー先頭タスクを取得} */
	tskhdl_run = _KERNEL_SYS_GET_RUNTSK();	/* %jp{実行中タスクを取得} */
	
	if ( tskhdl_top == tskhdl_run )
	{
		return;
	}
	
	/* %jp{コンテキスト取得} */
#if _KERNEL_SYSTSK_TCB

	ctxcb_top = _KERNEL_TSK_GET_CTXCB(_KERNEL_TSK_TSKHDL2TCB(tskhdl_top));	/* %jp{レディーキュー先頭タスクのコンテキストを取得} */
	ctxcb_run = _KERNEL_TSK_GET_CTXCB(_KERNEL_TSK_TSKHDL2TCB(tskhdl_run));	/* %jp{実行中タスクのコンテキストを取得} */

#else

	/* %jp{レディーキュー先頭タスクのコンテキストを取得} */
	if ( tskhdl_top != _KERNEL_TSKHDL_NULL )
	{
		ctxcb_top = _KERNEL_TSK_GET_CTXCB(_KERNEL_TSK_TSKHDL2TCB(tskhdl_top));
	}
	else
	{
		ctxcb_top = _KERNEL_SYS_GET_SYSCTXCB();
	}

	/* %jp{実行中タスクのコンテキストを取得} */
	if ( tskhdl_run != _KERNEL_TSKHDL_NULL )
	{
		ctxcb_run = _KERNEL_TSK_GET_CTXCB(_KERNEL_TSK_TSKHDL2TCB(tskhdl_run));
	}
	else
	{
		ctxcb_run = _KERNEL_SYS_GET_SYSCTXCB();
	}


#endif
	
	/* %jp{実行タスクの登録} */
	_KERNEL_SYS_SET_RUNTSK(tskhdl_top);
	
	/* %jp{タスクスイッチのフック} */
#if _KERNEL_SPT_HOK_TSKSWI
	{
		ID	tskid_old;
		ID	tskid_new;
		tskid_old = (tskhdl_run != _KERNEL_TSKHDL_NULL) ? _KERNEL_TSK_TSKHDL2ID(tskhdl_run) : 0;
		tskid_new = (tskhdl_top != _KERNEL_TSKHDL_NULL) ? _KERNEL_TSK_TSKHDL2ID(tskhdl_top) : 0;
		_kernel_tsk_swi(tskid_old, tskid_new);
	}
#endif
	
	/* %jp{ディスパッチ実行} */
	_KERNEL_SWI_CTX(ctxcb_run, ctxcb_top);
	
	/* %jp{タスク例外処理} */
#if _KERNEL_SPT_TEX
	if ( tskhdl_run != _KERNEL_TSKHDL_NULL )
	{
		_kernel_exe_tex(tskhdl_run);
	}
#endif
}


/* end of file */

/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  ext_tsk.c
 * @brief %jp{自タスクの終了と削除}%en{Terminate and Delete Invoking Task}
 *
 * Copyright (C) 1998-2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/mtxobj.h"



#if _KERNEL_SPT_EXD_TSK


static void _kernel_exd_tsk(VP_INT exinf1, VP_INT exinf2);


/** %jp{自タスクの終了と削除}%en{Terminate and Delete Invoking Task}
 * @return void
 */
void exd_tsk(void)
{
	_KERNEL_T_TSKHDL     tskhdl;
	_KERNEL_T_TCB        *tcb;

	/* %jp{実行中タスクを取得}%en{get current task} */
	tskhdl = _KERNEL_SYS_GET_RUNTSK();
	
	_KERNEL_ENTER_SVC();		/* %jp{サービスコールに入る}%en{enter service-call} */
	
	/* %jp{レディーキューから削除} */
	_KERNEL_DSP_EXT_TSK(tskhdl);
	
	/* %jp{TCB取得}%en{get TCB} */
	tcb    = _KERNEL_TSK_TSKHDL2TCB(tskhdl);
	
	/* %jp{所有ミューテックスがあれば開放} */
#if _KERNEL_SPT_MTX
	{
		_KERNEL_T_MTXHDL mtxhdl;
		while ( (mtxhdl = _KERNEL_TSK_GET_MTXHDL(tcb)) != _KERNEL_MTXHDL_NULL )
		{
			_kernel_rmv_mtx(mtxhdl, tskhdl);
		}
	}
#endif
	
	/* %jp{システムコンテキストの生成} */
	_KERNEL_CRE_CTX(
			_KERNEL_SYS_GET_SYSCTXCB(),
			_KERNEL_SYS_GET_SYSSTKSZ(),
			_KERNEL_SYS_GET_SYSSTK(),
			_KERNEL_SYS_GET_SYSISP(),
			(FP)_kernel_exd_tsk,
			(VP_INT)tskhdl,
			(VP_INT)0
		);
	
	/* %jp{システムコンテキストにスイッチ} */
	_kernel_sta_ctx(_KERNEL_SYS_GET_SYSCTXCB());
}


void _kernel_exd_tsk(VP_INT exinf1, VP_INT exinf2)
{
	_KERNEL_T_TSKHDL	tskhdl;
	_KERNEL_T_TCB_PTR	tcb;
	ID					tskid;
	
	tskhdl = (_KERNEL_T_TSKHDL)exinf1;
	tcb    = _KERNEL_TSK_TSKHDL2TCB(tskhdl);
	tskid  = _KERNEL_TSK_TSKHDL2ID(tskhdl);
	
	/* %jp{オブジェクト削除} */
#if _KERNEL_TCB_ALGORITHM == _KERNEL_TCB_ALG_PTRARRAY
	_KERNEL_SYS_FRE_HEP(tcb);						/* %jp{メモリ開放} */
	_KERNEL_TSK_ID2TCB(tskid) = NULL;
#elif _KERNEL_TCB_ALGORITHM == _KERNEL_TCB_ALG_BLKARRAY
	_KERNEL_TSK_SET_TASK(tcb, 0);
#endif
	
	/* %jp{タスクディスパッチの実行}%en{task dispatch} */
	_KERNEL_DSP_TSK();

	_KERNEL_LEAVE_SVC();		/* %jp{サービスコールから出る}%en{leave service-call} */
	
	
	/* %jp{アイドルループに戻る} */
	_KERNEL_LEAVE_SVC();
	_kernel_idl_lop();
}


#else	/* _KERNEL_SPT_EXD_TSK */


#endif	/* _KERNEL_SPT_EXD_TSK */


/* end of file */

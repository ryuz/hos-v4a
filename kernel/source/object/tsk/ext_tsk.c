/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  ext_tsk.c
 * @brief %jp{タスクの終了}%en{Exit Task}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/mtxobj.h"


/** %jp{タスクの終了}%en{Exit Task}
 * @return void
 */
void ext_tsk(void)
{
	_KERNEL_T_TSKHDL     tskhdl;
	_KERNEL_T_TCB        *tcb;
	_KERNEL_T_TCB_RO     *tcb_ro;
	_KERNEL_TSK_T_ACTCNT actcnt;

	/* %jp{実行中タスクを取得} */
	tskhdl = _KERNEL_SYS_GET_RUNTSK();

	_KERNEL_ENTER_SVC();		/* %jp{enter service-call}%jp{サービスコールに入る} */
	
	/* %jp{レディーキューから削除} */
	_KERNEL_DSP_EXT_TSK(tskhdl);

	/* %jp{TCB取得} */
	tcb    = _KERNEL_TSK_TSKHDL2TCB(tskhdl);
	tcb_ro = _KERNEL_TSK_GET_TCB_RO(_KERNEL_TSK_TSKHDL2ID(tskhdl), tcb);
	
	
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
	
	
	/* %jp{起動要求ネストのチェック} */
	actcnt = _KERNEL_TSK_GET_ACTCNT(tcb);
	if ( actcnt > 0 )	/* %jp{起動要求ネストがあるなら再生成} */
	{
		_KERNEL_TSK_T_TPRI   itskpri;
		
		_KERNEL_TSK_SET_ACTCNT(tcb, actcnt - 1);
		itskpri = _KERNEL_TSK_GET_ITSKPRI(tcb_ro);
		_KERNEL_TSK_SET_TSKPRI(tcb, itskpri);
		_KERNEL_TSK_SET_TSKBPRI(tcb, itskpri);
		
		/* %jp{レディーキュー再接続} */
		_KERNEL_DSP_STA_TSK(tskhdl);						
	}
	else				/* %jp{起動要求ネストがなければ終了} */
	{
		_KERNEL_TSK_SET_TSKSTAT(tcb, _KERNEL_TTS_DMT);
	}
	
	/* %jp{タスクディスパッチの実行}%en{task dispatch} */
	_KERNEL_DSP_TSK();
	
	/* %jp{リスタート} */
	_KERNEL_RST_CTX(
				_KERNEL_TSK_GET_CTXCB(tcb),					/* %jp{コンテキスト制御ブロック} */
				_KERNEL_TSK_GET_STKSZ(tcb_ro),				/* %jp{タスクのスタック領域サイズ} */
				_KERNEL_TSK_GET_STK(tcb_ro),				/* %jp{タスクのスタック領域の先頭番地} */
				_KERNEL_TSK_GET_ISP(tcb_ro),				/* %jp{スタックポインタの初期値} */
				(FP)_kernel_ent_tsk,						/* %jp{コンテキストの開始アドレス} */
				(VP_INT)_KERNEL_TSK_GET_EXINF(tcb_ro),		/* %jp{タスクの拡張情報} */
				(VP_INT)_KERNEL_TSK_GET_TASK(tcb_ro)		/* %jp{タスクの起動番地} */
			);
}


/* end of file */

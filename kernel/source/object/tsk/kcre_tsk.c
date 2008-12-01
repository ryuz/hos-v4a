/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  kcre_tsk.c
 * @brief %en{Activate Task}%jp{タスクの起動}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"



/** %en{Activate Task}%jp{タスクの起動}
 * @param  tskid	%jp{タスクID}%en{ID number of the task to be activated}
 * @param  pk_ctsk	%jp{タスク生成情報}%en{}
 * @retval E_OK
 * @retval E_NOMEM
 */
ER _kernel_cre_tsk(ID tskid, const T_CTSK *pk_ctsk)
{
	_KERNEL_T_TCB    *tcb;
	_KERNEL_T_TCB_RO *tcb_ro;
	VP               stk;
	
	/* %jp{メモリ確保}%en{get memory} */
#if	_KERNEL_TCB_ALGORITHM == _KERNEL_TCB_ALG_BLKARRAY
	{
		/* %jp{TCB領域がブロック配列の場合、スタックのみ確保} */

		/* %jp{スタックの確保} */
		if ( pk_ctsk->stk == NULL )
		{
			stk = _KERNEL_SYS_ALC_HEP(pk_ctsk->stksz);
			if ( stk == NULL )
			{
				return E_NOMEM;
			}
		}
		else
		{
			stk = pk_ctsk->stk;
		}
		
		tcb    = _KERNEL_TSK_ID2TCB(tskid);
		tcb_ro = _KERNEL_TSK_GET_TCB_RO(tskid, tcb);
	}
#elif _KERNEL_TCB_ALGORITHM == _KERNEL_TCB_ALG_PTRARRAY
#if _KERNEL_TCB_SPLIT_RO
	{
		/* %jp{TCB領域がポインタ管理で、ROM/RAM分離の場合} */

		VP   mem;
		SIZE memsz;

		/* %jp{メモリサイズ決定} */
		memsz = _KERNEL_SYS_ALG_HEP(sizeof(_KERNEL_T_TCB))
					+ _KERNEL_SYS_ALG_HEP(sizeof(_KERNEL_T_TCB_RO));
		if ( pk_ctsk->stk == NULL )
		{
			memsz += pk_ctsk->stksz;
		}

		/* %jp{メモリ確保} */
		mem = _KERNEL_SYS_ALC_HEP(memsz);
		if ( mem == NULL )
		{
			return E_NOMEM;
		}

		/* %jp{メモリ割り当て} */
		_KERNEL_TSK_ID2TCB(tskid) = tcb    = (_KERNEL_T_TCB *)mem;
		tcb->tcb_ro               = tcb_ro = (_KERNEL_T_TCB_RO *)((B *)mem + _KERNEL_SYS_ALG_HEP(sizeof(_KERNEL_T_TCB)));
		if ( pk_ctsk->stk == NULL )
		{
			stk = (VP)((B *)mem + _KERNEL_SYS_ALG_HEP(sizeof(_KERNEL_T_TCB)) + _KERNEL_SYS_ALG_HEP(sizeof(_KERNEL_T_TCB_RO)));
		}
		else
		{
			stk = pk_ctsk->stk;
		}
	}
#else
	{
		VP   mem;
		SIZE memsz;
		
		/* %jp{メモリサイズ決定} */
		memsz = _KERNEL_SYS_ALG_HEP(sizeof(_KERNEL_T_TCB));
		if ( pk_ctsk->stk == NULL )
		{
			memsz += pk_ctsk->stksz;
		}

		/* %jp{メモリ確保} */
		mem = _KERNEL_SYS_ALC_HEP(memsz);
		if ( mem == NULL )
		{
			return E_NOMEM;
		}

		/* %jp{メモリ割り当て} */
		_KERNEL_TSK_ID2TCB(tskid) = tcb_ro = tcb = (_KERNEL_T_TCB *)mem;
		if ( pk_ctsk->stk == NULL )
		{
			stk = (VP)((VB *)mem + _KERNEL_SYS_ALG_HEP(sizeof(_KERNEL_T_TCB)));
		}
		else
		{
			stk = pk_ctsk->stk;
		}
	}
#endif
#endif
	
	/* %jp{基本メンバ設定} */
	_KERNEL_TSK_SET_TSKATR(tcb_ro, pk_ctsk->tskatr);			/* %jp{タスク属性} */
	_KERNEL_TSK_SET_EXINF(tcb_ro, pk_ctsk->exinf);				/* %jp{タスクの拡張情報} */
	_KERNEL_TSK_SET_TASK(tcb_ro, pk_ctsk->task);				/* %jp{タスクの起動番地} */
	_KERNEL_TSK_SET_ITSKPRI(tcb_ro, pk_ctsk->itskpri);			/* %jp{タスクの起動時優先度} */
	_KERNEL_TSK_SET_STKSZ(tcb_ro, pk_ctsk->stksz);				/* %jp{スタック領域のサイズ(バイト数)} */
	_KERNEL_TSK_SET_STK(tcb_ro, stk);							/* %jp{スタック領域の先頭番地} */
	_KERNEL_TSK_SET_ISP(tcb_ro, (VB *)stk + pk_ctsk->stksz);	/* %jp{スタックポインタ初期値の先頭番地} */
	_KERNEL_TSK_SET_TSKID(tcb_ro, tskid);
	_KERNEL_TSK_SET_TEXATR(tcb_ro, TA_HLNG);
	_KERNEL_TSK_SET_TEXRTN(tcb_ro, NULL);
	
	_KERNEL_TSK_CRE_TOQOBJ(tcb);
	_KERNEL_TSK_CRE_QUEOBJ(tcb);
	_KERNEL_TSK_SET_TSKSTAT(tcb, _KERNEL_TTS_DMT);
	_KERNEL_TSK_SET_MTXHDL(tcb, _KERNEL_MTXHDL_NULL);
	_KERNEL_TSK_SET_TEXSTAT(tcb, _KERNEL_TXS_DIS);
	_KERNEL_TSK_SET_RASPTN(tcb, 0);

	/* %jp{TA_ACT属性があればタスク実行} */
#if _KERNEL_SPT_TSK_TA_ACT
	if ( pk_ctsk->tskatr & TA_ACT )
	{
		/* %jp{タスク状態初期化} */
		_KERNEL_TSK_SET_TSKSTAT(tcb, _KERNEL_TTS_RDY);
		_KERNEL_TSK_SET_TSKPRI(tcb, pk_ctsk->itskpri);
		_KERNEL_TSK_SET_TSKBPRI(tcb, pk_ctsk->itskpri);
		_KERNEL_TSK_SET_ACTCNT(tcb, 0);
		_KERNEL_TSK_SET_WUPCNT(tcb, 0);
		_KERNEL_TSK_SET_SUSCNT(tcb, 0);
		
		/* %jp{コンテキスト生成} */
		_KERNEL_CRE_CTX(
				_KERNEL_TSK_GET_CTXCB(tcb),			/* %jp{コンテキスト制御ブロック} */
				pk_ctsk->tsksz,						/* %jp{タスクのスタック領域サイズ} */
				stk,								/* %jp{タスクのスタック領域の先頭番地} */
				(VP)((VB *)stk + pk_ctsk->stksz),	/* %jp{スタックポインタの初期値} */
				(FP)_kernel_ent_tsk,				/* %jp{コンテキストの開始アドレス} */
				(VP_INT)pk_ctsk->exinf,				/* %jp{タスクの拡張情報} */
				(VP_INT)pk_ctsk->task				/* %jp{タスクの起動番地} */
			);
		
		/* %jp{タスク実行可能状態に設定} */
		_KERNEL_DSP_STA_TSK(_KERNEL_TSK_GET_TSKHDL(tskid, tcb));
		
		/* %jp{タスクディスパッチの実行}%en{task dispatch} */
		_KERNEL_DSP_TSK();
	}
#endif

	return E_OK;
}


/* end of file */

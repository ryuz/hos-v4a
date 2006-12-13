/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  act_tsk.c
 * @brief %en{Activate Task}%jp{タスクの起動}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"



#if _KERNEL_SPT_IACT_TSK

#if _KERNEL_SPT_DPC

static void _kernel_dpc_act_tsk(void);

/** %en{Activate Task}%jp{タスクの起動}
 * @param  tskid   %en{ID number of the task to be activated}%jp{タスクID}
 * @return void
 */
ER iact_tsk(
		ID tskid)
{
	ER ercd;

	/* %jp{ID のチェック} */
#ifdef _KERNEL_SPT_IACT_TSK_E_ID
	if ( !_KERNEL_TSK_CHECK_TSKID(flgid) )
	{
		return E_ID;		/* %jp{ID不正} */
	}
#endif

#ifdef _KERNEL_SPT_IACT_TSK_E_CTX
	if ( !_KERNEL_SYS_SNS_CTX() )
	{
		return E_CTX;		/* %jp{コンテキスト不正} */
	}
#endif

	_KERNEL_SYS_LOC_DPC();	/* %jp{多重割り込み対策でロックをかける} */

	if (  _KERNEL_SYS_RFR_DPC() >= 2 )
	{
		_KERNEL_SYS_SND_DPC((VP_INT)_kernel_dpc_act_tsk);
		_KERNEL_SYS_SND_DPC((VP_INT)tskid);
		ercd = E_OK;		/* %jp{正常終了}%en{Normal completion} */
	}
	else
	{
		ercd = E_NOMEM;		/* %jp{遅延実行用のキューイングメモリ不足}%en{Insufficient memory to store a service call for delayed execution} */
	}

	_KERNEL_SYS_UNL_DPC();	/* jp{ロック解除} */

	return ercd;
}


/** %jp{iact_tskの遅延実行}%en{service call for delayed executioniact_tsk)} */
void _kernel_dpc_act_tsk(void)		
{
	_KERNEL_T_TSKHDL       tskhdl;
	_KERNEL_T_TCB          *tcb;
	const _KERNEL_T_TCB_RO *tcb_ro;
	ID                     tskid;
	
	/* %jp{パラメータ取り出し} */
	tskid = (ID)_KERNEL_SYS_RCV_DPC();
	
	/* %jp{オブジェクト存在チェック} */
#ifdef _KERNEL_CFG_IACT_TSK_E_NOEXS
	if ( _KERNEL_TSK_CHECK_EXS(tskid) )
	{
		_KERNEL_LEAVE_SVC();		/* %jp{leave service-call}%jp{サービスコールを出る} */
		return E_NOEXS;			/* %jp{オブジェクト未生成} */
	}
#endif

	/* %jp{TCB取得} */
	tcb = _KERNEL_TSK_ID2TCB(tskid);
	
	/* ID番号指定時の変換 */
	tskhdl = _KERNEL_TSK_ID2TSKHDL(tskid);
	

	if ( _KERNEL_TSK_GET_TSKSTAT(tcb) != _KERNEL_TTS_DMT )		/* %jp{オブジェクト状態判定} */
	{
#if _KERNEL_TCB_ACTCNT
		{
			_KERNEL_TSK_T_ACTCNT actcnt;

			/* %jp{既に実行状態なら起動要求をキューイング} */
			actcnt = _KERNEL_TSK_GET_ACTCNT(tcb);
		
			/* %jp{既に実行状態なら起動要求をキューイング} */
		#ifdef _KERNEL_CFG_ACT_TSK_E_QOVR
			if ( actcnt >= _KERNEL_TMAX_ACTCNT )
			{
				return;		/* %jp{キューイングオーバーフロー} */
			}
		#endif

			/* %jp{起動要求をキューイング} */
			_KERNEL_TSK_SET_ACTCNT(tcb, actcnt + 1);
		}
#else
		{
			return;		/* %jp{キューイングオーバーフロー} */
		}
#endif
	}
	else
	{
		/* %jp{タスク状態初期化} */
		tcb_ro = _KERNEL_TSK_GET_TCB_RO(tskid, tcb);
		_KERNEL_TSK_SET_TSKPRI(tcb, _KERNEL_TSK_GET_ITSKPRI(tcb_ro));
		_KERNEL_TSK_SET_TSKBPRI(tcb, _KERNEL_TSK_GET_ITSKPRI(tcb_ro));
		_KERNEL_TSK_SET_TSKSTAT(tcb, _KERNEL_TTS_RDY);
		_KERNEL_TSK_SET_ACTCNT(tcb, 0);
		_KERNEL_TSK_SET_WUPCNT(tcb, 0);
		_KERNEL_TSK_SET_SUSCNT(tcb, 0);
		
		/* %jp{コンテキスト生成} */
		_KERNEL_CRE_CTX(
				_KERNEL_TSK_GET_CTXCB(tcb),					/* %jp{コンテキスト制御ブロック} */
				_KERNEL_TSK_GET_STKSZ(tcb_ro),				/* %jp{タスクのスタック領域サイズ} */
				_KERNEL_TSK_GET_STK(tcb_ro),				/* %jp{タスクのスタック領域の先頭番地} */
				(VP)_KERNEL_TSK_GET_ISP(tcb_ro),			/* %jp{スタックポインタの初期値} */
				(FP)_kernel_ent_tsk,						/* %jp{コンテキストの開始アドレス} */
				(VP_INT)_KERNEL_TSK_GET_EXINF(tcb_ro),		/* %jp{タスクの拡張情報} */
				(VP_INT)_KERNEL_TSK_GET_TASK(tcb_ro)		/* %jp{タスクの起動番地} */
			);
		
		/* %jp{タスク実行可能状態に設定} */
		_KERNEL_DSP_STA_TSK(tskhdl);
		
		/* %jp{ディスパッチ遅延をセット} */
		_KERNEL_SYS_SET_DLY();
	}
		
	return;	/* 成功 */
}

#else	/* _KERNEL_SPT_DPC */

/** %en{Activate Task}%jp{タスクの起動}
 * @param  tskid   %en{ID number of the task to be activated}%jp{タスクID}
 * @return void
 */
ER iact_tsk(
		ID tskid)
{
	return act_tsk(tskid);
}

#endif	/* _KERNEL_SPT_DPC */

#endif	/* _KERNEL_SPT_IACT_TSK */



/* end of file */

/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  act_tsk.c
 * @brief %jp{タスクの起動}%en{Activate Task}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"



#if _KERNEL_SPT_ACT_TSK


/** %jp{タスクの起動}%en{Activate Task}
 * @param  tskid    %jp{起動対象のタスクのID番号}%en{ID number of the task to be activated}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 * @retval E_ID     %jp{不正ID番号(tskidが不正あるいは使用できない)}%en{Invalid ID number(tskid is invalid or unusable)}
 * @retval E_NOEXS  %jp{オブジェクト未生成(対象タスクが未登録)}%en{Non-existant object(specified task is not registerd)}
 * @retval E_QOVR   %jp{キューイングオーバーフロー(起動要求キューイングのオーバーフロー)}%en{Queue overflow(overflow of activate queuing count)}
 */
ER act_tsk(
		ID tskid)
{
	_KERNEL_T_TSKHDL		tskhdl;
	_KERNEL_T_TCB_PTR		tcb;
	_KERNEL_T_TCB_RO_PTR	tcb_ro;

	if ( tskid == TSK_SELF )		/* %jp{自タスク指定時の変換} */
	{
#if _KERNEL_SPT_ACT_TSK_E_ID
		if ( _KERNEL_SYS_SNS_CTX() )
		{
			return E_ID;		/* %jp{不正ID番号} */
		}
#endif	
		/* %jp{実行中タスクを取得} */
		tskhdl = _KERNEL_SYS_GET_RUNTSK();

		_KERNEL_ENTER_SVC();		/* %jp{enter service-call}%jp{サービスコールに入る} */
	}
	else
	{
#if _KERNEL_SPT_ACT_TSK_E_ID
		if ( !_KERNEL_TSK_CHECK_TSKID(tskid) )
		{
			return E_ID;	/* %jp{不正ID番号} */
		}
#endif
		
		_KERNEL_ENTER_SVC();		/* %jp{enter service-call}%jp{サービスコールに入る} */
		
		/* %jp{オブジェクト存在チェック} */
#if _KERNEL_SPT_ACT_TSK_E_NOEXS
		if ( !_KERNEL_TSK_CHECK_EXS(tskid) )
		{
			_KERNEL_LEAVE_SVC();		/* %jp{leave service-call}%jp{サービスコールを出る} */
			return E_NOEXS;			/* %jp{オブジェクト未生成} */
		}
#endif
		/* ID番号指定時の変換 */
		tskhdl = _KERNEL_TSK_ID2TSKHDL(tskid);
	}
	

	/* %jp{TCB取得} */
	tcb = _KERNEL_TSK_TSKHDL2TCB(tskhdl);

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
				_KERNEL_LEAVE_SVC();
				return E_QOVR;		/* %jp{キューイングオーバーフロー} */
			}
		#endif

			/* %jp{起動要求をキューイング} */
			_KERNEL_TSK_SET_ACTCNT(tcb, actcnt + 1);
		}
#else
		{
			_KERNEL_LEAVE_SVC();
			return E_QOVR;		/* %jp{キューイングオーバーフロー} */
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
		
		/* %jp{タスクディスパッチの実行}%en{task dispatch} */
		_KERNEL_DSP_TSK();
	}
	
	_KERNEL_LEAVE_SVC();
	
	return E_OK;	/* 成功 */
}


#else	/* _KERNEL_SPT_ACT_TSK */


/** %en{Activate Task}%jp{タスクの起動}
 * @param  tskid    %jp{起動対象のタスクのID番号}%en{ID number of the task to be activated}
 * @retval E_NOSPT  %jp{未サポート機能}%en{Unsupported function}
 */
ER act_tsk(
		ID tskid)
{
	return E_NOSPT;
}

#endif	/* _KERNEL_SPT_ACT_TSK */


/* end of file */

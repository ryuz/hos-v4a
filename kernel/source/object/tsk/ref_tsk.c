/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  wup_tsk.c
 * @brief %jp{タスクの起床}%en{Wakeup Task}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"



/* タスクの状態参照 */
ER ref_tsk(ID tskid, T_RTSK *p_rtsk)
{
	_KERNEL_T_TSKHDL		tskhdl;
	_KERNEL_T_TCB_PTR		tcb;
	_KERNEL_T_TCB_RO_PTR	tcb_ro;

	if ( tskid == TSK_SELF )		/* %jp{自タスク指定時の変換} */
	{
#if _KERNEL_SPT_REF_TSK_E_ID
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
#if _KERNEL_SPT_REF_TSK_E_ID
		if ( !_KERNEL_TSK_CHECK_TSKID(tskid) )
		{
			return E_ID;	/* %jp{不正ID番号} */
		}
#endif
		
		_KERNEL_ENTER_SVC();			/* %jp{enter service-call}%jp{サービスコールに入る} */
		
		/* %jp{オブジェクト存在チェック} */
#if _KERNEL_SPT_REF_TSK_E_NOEXS
		if ( !_KERNEL_TSK_CHECK_EXS(tskid) )
		{
			_KERNEL_LEAVE_SVC();		/* %jp{leave service-call}%jp{サービスコールを出る} */
			return E_NOEXS;				/* %jp{オブジェクト未生成} */
		}
#endif
		/* ID番号指定時の変換 */
		tskhdl = _KERNEL_TSK_ID2TSKHDL(tskid);
	}

	/* %jp{TCB取得} */
	tcb    = _KERNEL_TSK_TSKHDL2TCB(tskhdl);
	tcb_ro = _KERNEL_TSK_GET_TCB_RO(tskid, tcb);
	
	p_rtsk->tskstat = _KERNEL_DEC_TTS(_KERNEL_TSK_GET_TSKSTAT(tcb));	/* %jp{タスク状態} */
	p_rtsk->tskpri  = _KERNEL_TSK_GET_TSKPRI(tcb);						/* %jp{タスクの現在優先度} */
	p_rtsk->tskbpri = _KERNEL_TSK_GET_TSKBPRI(tcb);						/* %jp{タスクのベース優先度} */
	p_rtsk->tskwait = _KERNEL_DEC_TTW(_KERNEL_TSK_GET_TSKWAIT(tcb));	/* %jp{待ち要因} */
	p_rtsk->wobjid  = _KERNEL_TSK_GET_WOBJID(tcb);						/* %jp{待ち対象のオブジェクトのID番号} */
/*	p_rtsk->lefttmo = _KERNEL_TSK_GET_LEFTTMO(tskhdl);	*/				/* %jp{タイムアウトするまでの時間} */
	p_rtsk->actcnt  = _KERNEL_TSK_GET_ACTCNT(tcb);						/* %jp{起動要求キューイング回数} */
	p_rtsk->wupcnt  = _KERNEL_TSK_GET_WUPCNT(tcb);						/* %jp{起床要求キューイング回数} */
	p_rtsk->suscnt  = _KERNEL_TSK_GET_SUSCNT(tcb);						/* %jp{強制待ち要求ネスト回数} */
	
	
	/* %jp{以下、独自実装}%en{HOS extention} */
#if _KERNEL_SPT_RTSK_TSKATR
	p_rtsk->tskatr  = _KERNEL_TSK_GET_TSKATR(tcb_ro);					/* %jp{タスク属性(HOS独自拡張)} */
#endif

#if _KERNEL_SPT_RTSK_EXINF
	p_rtsk->exinf   = _KERNEL_TSK_GET_EXINF(tcb_ro);					/* %jp{タスクの拡張情報(HOS独自拡張)} */
#endif

#if _KERNEL_SPT_RTSK_TASK
	p_rtsk->task    = (FP)_KERNEL_TSK_GET_TASK(tcb_ro);					/* %jp{タスクの起動番地(HOS独自拡張)} */
#endif
#if _KERNEL_SPT_RTSK_ITSKPRI
	p_rtsk->itskpri = _KERNEL_TSK_GET_ITSKPRI(tcb_ro);					/* %jp{タスクの起動時優先度(HOS独自拡張)} */
#endif
#if _KERNEL_SPT_RTSK_STKSZ
	p_rtsk->stksz   = _KERNEL_TSK_GET_STKSZ(tcb_ro);					/* %jp{スタック領域のサイズ(バイト数)(HOS独自拡張)} */
#endif
#if _KERNEL_SPT_RTSK_STK
	p_rtsk->stk     = _KERNEL_TSK_GET_STK(tcb_ro);						/* %jp{スタック領域の先頭番地(HOS独自拡張)} */
#endif


	_KERNEL_LEAVE_SVC();	/* %jp{サービスコール終了} */

	return E_OK;
}


/* end of file */

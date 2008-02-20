/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  wup_tsk.c
 * @brief %jp{タスクの状態参照(簡易版)}%en{}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"



/* タスクの状態参照(簡易版) */
ER ref_tst(ID tskid, T_RTST *p_rtst)
{
	_KERNEL_T_TSKHDL		tskhdl;
	_KERNEL_T_TCB_PTR		tcb;
	_KERNEL_T_TCB_RO_PTR	tcb_ro;

	if ( tskid == TSK_SELF )		/* %jp{自タスク指定時の変換} */
	{
#if _KERNEL_SPT_REF_TST_E_ID
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
#if _KERNEL_SPT_REF_TST_E_ID
		if ( !_KERNEL_TSK_CHECK_TSKID(tskid) )
		{
			return E_ID;	/* %jp{不正ID番号} */
		}
#endif
		
		_KERNEL_ENTER_SVC();			/* %jp{enter service-call}%jp{サービスコールに入る} */
		
		/* %jp{オブジェクト存在チェック} */
#if _KERNEL_SPT_REF_TST_E_NOEXS
		if ( _KERNEL_TSK_CHECK_EXS(tskid) )
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
	
	p_rtst->tskstat = _KERNEL_DEC_TTS(_KERNEL_TSK_GET_TSKSTAT(tcb));	/* %jp{タスク状態} */
	p_rtst->tskwait = _KERNEL_DEC_TTW(_KERNEL_TSK_GET_TSKWAIT(tcb));	/* %jp{待ち要因} */
	
	
	/* %jp{以下、独自実装}%en{HOS extention} */
#if _KERNEL_SPT_RTST_TSKATR
	p_rtst->tskatr  = _KERNEL_TSK_GET_TSKATR(tcb_ro);					/* %jp{タスク属性(HOS独自拡張)} */
#endif

#if _KERNEL_SPT_RTST_EXINF
	p_rtst->exinf   = _KERNEL_TSK_GET_EXINF(tcb_ro);					/* %jp{タスクの拡張情報(HOS独自拡張)} */
#endif

#if _KERNEL_SPT_RTST_TASK
	p_rtst->task    = _KERNEL_TSK_GET_TASK(tcb_ro);						/* %jp{タスクの起動番地(HOS独自拡張)} */
#endif
#if _KERNEL_SPT_RTST_ITSKPRI
	p_rtst->itskpri = _KERNEL_TSK_GET_ITSKPRI(tcb_ro);					/* %jp{タスクの起動時優先度(HOS独自拡張)} */
#endif
#if _KERNEL_SPT_RTST_STKSZ
	p_rtst->stksz   = _KERNEL_TSK_GET_STKSZ(tcb_ro);					/* %jp{スタック領域のサイズ(バイト数)(HOS独自拡張)} */
#endif
#if _KERNEL_SPT_RTST_STK
	p_rtst->stk     = _KERNEL_TSK_GET_STK(tcb_ro);						/* %jp{スタック領域の先頭番地(HOS独自拡張)} */
#endif


	_KERNEL_LEAVE_SVC();	/* %jp{サービスコール終了} */

	return E_OK;
}


/* end of file */

/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  sus_tsk.c
 * @brief 
 *
 * @version $Id: sus_tsk.c,v 1.2 2006-09-03 14:09:04 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"


#if _KERNEL_SPT_SUS_TSK


ER sus_tsk(
		ID tskid)
{
	_KERNEL_T_TSKHDL      tskhdl;
	_KERNEL_T_TCB         *tcb;
	_KERNEL_TSK_T_TSKSTAT tskstat;

	if ( tskid == TSK_SELF )		/* %jp{自タスク指定時の変換} */
	{
#if _KERNEL_SPT_SUS_TSK_E_ID
		if ( _KERNEL_SYS_SNS_CTX() )
		{
			return E_CTX;		/* %jp{コンテキスト不正} */
		}
#endif	
		/* %jp{実行中タスクを取得} */
		tskhdl = _KERNEL_SYS_GET_RUNTSK();
		
		_KERNEL_ENTER_SVC();		/* %jp{enter service-call}%jp{サービスコールに入る} */
	}
	else
	{
#if _KERNEL_SPT_SUS_TSK_E_ID
		if ( !_KERNEL_TSK_CHECK_TSKID(tskid) )
		{
			return E_ID;	/* %jp{不正ID番号} */
		}
#endif
		
		_KERNEL_ENTER_SVC();			/* %jp{enter service-call}%jp{サービスコールに入る} */
		
		/* %jp{オブジェクト存在チェック} */
#ifdef _KERNEL_SPT_SUS_TSK_E_NOEXS
		if ( _KERNEL_TSK_CHECK_EXS(tskid) )
		{
			_KERNEL_LEAVE_SVC();		/* %jp{leave service-call}%jp{サービスコールを出る} */
			return E_NOEXS;				/* %jp{オブジェクト未生成} */
		}
#endif
		/* ID番号指定時の変換 */
		tskhdl = _KERNEL_TSK_ID2TSKHDL(tskid);
	}
	
	/* %jp{コントロールブロック取得} */
	tcb = _KERNEL_TSK_TSKHDL2TCB(tskhdl);

	/* %jp{タスク状態取得} */
	tskstat = _KERNEL_TSK_GET_TSKSTAT(tcb);
	if ( tskstat & _KERNEL_TTS_SUS )
	{
		_KERNEL_TSK_T_SUSCNT suscnt;
		
		suscnt = _KERNEL_TSK_GET_SUSCNT(tcb);
		if ( suscnt >= _KERNEL_TMAX_SUSCNT )
		{
			_KERNEL_LEAVE_SVC();		/* %jp{leave service-call}%jp{サービスコールを出る} */
			return E_QOVR;
		}

		_KERNEL_TSK_SET_SUSCNT(tcb, suscnt + 1);
	}
	else
	{
		_KERNEL_DSP_SUS_TSK(tskhdl);			/* %jp{タスクの強制待ち} */
		
		_KERNEL_DSP_TSK();
	}

	_KERNEL_LEAVE_SVC();	/* %jp{サービスコール終了} */

	return E_OK;
}


#else	/* _KERNEL_SPT_SUS_TSK */


#if _KERNEL_SPT_SUS_TSK_E_NOSPT

ER sus_tsk(
		ID tskid)
{
	return E_NOSPT;
}

#endif


#endif


/* end of file */

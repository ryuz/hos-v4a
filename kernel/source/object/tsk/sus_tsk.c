/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  sus_tsk.c
 * @brief 
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

	
	/* %jp{タスクハンドル取得} */
	if ( tskid == TSK_SELF )		/* %jp{自タスク指定時の変換} */
	{
		/* %jp{実行中タスクを取得} */
		tskhdl = _KERNEL_SYS_GET_RUNTSK();
		
		_KERNEL_ENTER_SVC();		/* %jp{サービスコールに入る}%en{enter service-call} */
	}
	else
	{
#if _KERNEL_SPT_SUS_TSK_E_ID
		if ( !_KERNEL_TSK_CHECK_TSKID(tskid) )
		{
			return E_ID;			/* %jp{不正ID番号} */
		}
#endif
	
		_KERNEL_ENTER_SVC();		/* %jp{サービスコールに入る}%en{enter service-call} */
		
		/* %jp{オブジェクト存在チェック} */
#if _KERNEL_SPT_SUS_TSK_E_NOEXS
		if ( !_KERNEL_TSK_CHECK_EXS(tskid) )
		{
			_KERNEL_LEAVE_SVC();	/* %jp{サービスコールを出る}%en{leave service-call} */
			return E_NOEXS;			/* %jp{オブジェクト未生成} */
		}
#endif
		/* ID番号指定時の変換 */
		tskhdl = _KERNEL_TSK_ID2TSKHDL(tskid);
	}
	
	
	/* %jp{コンテキストチェック} */	
#if _KERNEL_SPT_SUS_TSK_E_CTX
		if ( _KERNEL_SYS_GET_RUNTSK() == tskhdl && _KERNEL_SYS_SNS_DPN() )
		{
			_KERNEL_LEAVE_SVC();	/* %jp{サービスコールを出る}%en{leave service-call} */
			return E_CTX;			/* %jp{コンテキスト不正} */
		}
#endif
	
	/* %jp{コントロールブロック取得} */
	tcb = _KERNEL_TSK_TSKHDL2TCB(tskhdl);
	
	/* %jp{タスク状態取得} */
	tskstat = _KERNEL_TSK_GET_TSKSTAT(tcb);
	
	
	/* %jp{状態チェック} */	
#if _KERNEL_SPT_SUS_TSK_E_CTX
	if ( tskstat == _KERNEL_TTS_DMT )
	{
			_KERNEL_LEAVE_SVC();	/* %jp{サービスコールを出る}%en{leave service-call} */
			return E_OBJ;			/* %jp{状態不正} */		
	}
#endif
	
	/* %jp{サスペンド処理} */
	if ( tskstat & _KERNEL_TTS_SUS )
	{
		_KERNEL_TSK_T_SUSCNT suscnt;
		
		/* %jp{現在のサスペンドカウンタ取得} */
		suscnt = _KERNEL_TSK_GET_SUSCNT(tcb);
		
#if _KERNEL_SPT_SUS_TSK_E_QOVR
		if ( suscnt >= _KERNEL_TMAX_SUSCNT )
		{
			_KERNEL_LEAVE_SVC();	/* %jp{サービスコールを出る}%en{leave service-call} */
			return E_QOVR;			/* %jp{キューイングオーバーフロー} */
		}
#endif

		_KERNEL_TSK_SET_SUSCNT(tcb, suscnt + 1);
	}
	else
	{
		_KERNEL_DSP_SUS_TSK(tskhdl);	/* %jp{タスクの強制待ち} */
		
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

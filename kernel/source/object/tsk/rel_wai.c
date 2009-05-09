/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  rel_wai.c
 * @brief %jp{待ち状態の強制解除}%en{Release Task from Waiting}
 *
 * Copyright (C) 1998-2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"



#if _KERNEL_SPT_REL_WAI


/** %jp{待ち状態の強制解除}%en{Release Task from Waiting}
 * @param  tskid    %jp{待ち状態の強制解除対象のタスクのID番号}%en{ID number of the task to be release task from waiting}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 * @retval E_ID     %jp{不正ID番号(tskidが不正あるいは使用できない)}%en{Invalid ID number(tskid is invalid or unusable)}
 * @retval E_NOEXS  %jp{オブジェクト未生成(対象タスクが未登録)}%en{Non-existant object(specified task is not registered)}
 * @retval E_OBJ    %jp{オブジェクト状態エラー(対象タスクが待ち状態でない)}%en{Object state error(specified task is neither in WAITING state)}
 */
ER rel_wai(
		ID tskid)
{
	_KERNEL_T_TSKHDL tskhdl;
	_KERNEL_T_TCB    *tcb;

	if ( tskid == TSK_SELF )		/* %jp{自タスク指定時の変換} */
	{
#if _KERNEL_SPT_REL_WAI_E_ID
		if ( _KERNEL_SYS_SNS_CTX() )
		{
			return E_ID;			/* %jp{不正ID番号}%en{Invalid ID number} */
		}
#endif	
		/* %jp{実行中タスクを取得} */
		tskhdl = _KERNEL_SYS_GET_RUNTSK();

		_KERNEL_ENTER_SVC();		/* %jp{サービスコールに入る}%en{enter service-call} */
	}
	else
	{
#if _KERNEL_SPT_REL_WAI_E_ID
		if ( !_KERNEL_TSK_CHECK_TSKID(tskid) )
		{
			return E_ID;			/* %jp{不正ID番号}%en{Invalid ID number} */
		}
#endif
		
		_KERNEL_ENTER_SVC();		/* %jp{サービスコールに入る}%en%jp{enter service-call} */
		
		/* %jp{オブジェクト存在チェック} */
#if _KERNEL_SPT_REL_WAI_E_NOEXS
		if ( !_KERNEL_TSK_CHECK_EXS(tskid) )
		{
			_KERNEL_LEAVE_SVC();	/* %jp{サービスコールを出る}%en{%jp{leave service-call} */
			return E_NOEXS;			/* %jp{オブジェクト未生成}%en{Non-existant object} */
		}
#endif
		/* %jp{ID番号指定時の変換} */
		tskhdl = _KERNEL_TSK_ID2TSKHDL(tskid);
	}
	
	/* %jp{TCB取得}%en{get TCB} */
	tcb = _KERNEL_TSK_TSKHDL2TCB(tskhdl);
	
	/* %jp{タスク状態取得チェック} */
#if _KERNEL_SPT_REL_WAI_E_OBJ
	{
		_KERNEL_TSK_T_TSKSTAT tskstat;

		tskstat = _KERNEL_TSK_GET_TSKSTAT(tcb);
		if ( !(tskstat & _KERNEL_TTS_WAI) )
		{
			_KERNEL_LEAVE_SVC();	/* %jp{サービスコールを出る}%en{leave service-call} */
			return E_OBJ;			/* %jp{オブジェクト状態エラー}%en{Object state error} */
		}
	}
#endif
	
	/* %jp{待ち解除} */
	_KERNEL_TRM_QUE(tskhdl);
	_KERNEL_TSK_SET_ERCD(tcb, E_RLWAI);		/* %jp{エラーコード設定} */
	_KERNEL_DSP_WUP_TSK(tskhdl);			/* %jp{タスクの待ち解除} */
		
	/* %jp{タスクディスパッチの実行}%en{Task dispatch} */
	_KERNEL_DSP_TSK();
	
	_KERNEL_LEAVE_SVC();		/* %jp{サービスコールを出る}%en{leave service-call} */
	
	return E_OK;
}


#else	/* _KERNEL_SPT_REL_WAI */


#if _KERNEL_SPT_REL_WAI_E_NOSPT

/** %jp{待ち状態の強制解除}%en{Release Task from Waiting}
 * @param  tskid    %jp{待ち状態の強制解除対象のタスクのID番号}%en{ID number of the task to be release task from waiting}
 * @retval E_NOSPT  %jp{未サポート機能}%en{Unsupported function}
 */
ER rel_wai(
		ID tskid)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_REL_WAI */



/* end of file */

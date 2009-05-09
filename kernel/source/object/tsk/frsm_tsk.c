/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  frsm_tsk.c
 * @brief %jp{強制待ち状態からの強制再開}%en{Forcibly Resume Suspended Task}
 *
 * Copyright (C) 1998-2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"


#if _KERNEL_SPT_FRSM_TSK


/** %jp{強制待ち状態からの強制再開}%en{Forcibly Resume Suspended Task}
 * @param  tskid    %jp{再開対象のタスクのID番号}%en{ID number of the task to be resumed}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 * @retval E_ID     %jp{不正ID番号(tskidが不正あるいは使用できない)}%en{Invalid ID number(tskid is invalid or unusable)}
 * @retval E_NOEXS  %jp{オブジェクト未生成(対象タスクが未登録)}%en{Non-existant object(specified task is not registered)}
 * @retval E_OBJ    %jp{オブジェクト状態エラー(対象タスクが強制待ち状態でない)}%en{Object state error(specified task is neither in SUSPENDED state nor WAITING-SUSPENDED state)}
 */
ER frsm_tsk(
		ID tskid)
{
	_KERNEL_T_TSKHDL      tskhdl;
	_KERNEL_T_TCB         *tcb;
	
	
#if _KERNEL_SPT_FRSM_TSK_E_ID
	if ( !_KERNEL_TSK_CHECK_TSKID(tskid) )
	{
		return E_ID;				/* %jp{不正ID番号}%en{Invalid ID number} */
	}
#endif
	
	_KERNEL_ENTER_SVC();			/* %jp{サービスコールに入る}%en{enter service-call} */
		
	/* %jp{オブジェクト存在チェック} */
#if _KERNEL_SPT_FRSM_TSK_E_NOEXS
	if ( !_KERNEL_TSK_CHECK_EXS(tskid) )
	{
		_KERNEL_LEAVE_SVC();		/* %jp{サービスコールを出る}%en{leave service-call} */
		return E_NOEXS;				/* %jp{オブジェクト未生成} */
	}
#endif
	
	/* %jp{ID番号指定時の変換} */
	tskhdl = _KERNEL_TSK_ID2TSKHDL(tskid);
	
	/* %jp{コントロールブロック取得} */
	tcb = _KERNEL_TSK_TSKHDL2TCB(tskhdl);

	/* %jp{タスク状態チェック}%en{check current state} */
#if _KERNEL_SPT_FRSM_TSK_E_OBJ
	{
		_KERNEL_TSK_T_TSKSTAT tskstat;
		tskstat = _KERNEL_TSK_GET_TSKSTAT(tcb);
		if ( !(tskstat & _KERNEL_TTS_SUS) )
		{
			_KERNEL_LEAVE_SVC();	/* %jp{サービスコールを出る}%en{leave service-call} */
			return E_OBJ;			/* %jp{オブジェクト状態エラー}%en{Object state error} */
		}
	}
#endif

	/* %jp{タスクの強制待ち解除} */
	_KERNEL_TSK_SET_SUSCNT(tcb, 0);
	_KERNEL_DSP_RSM_TSK(tskhdl);
	
	/* %jp{タスクディスパッチ} */
	_KERNEL_DSP_TSK();
	
	_KERNEL_LEAVE_SVC();	/* %jp{サービスコール終了} */
	
	return E_OK;
}


#else	/* _KERNEL_SPT_FRSM_TSK */


#if _KERNEL_SPT_FRSM_TSK_E_NOSPT

/** %jp{強制待ち状態からの強制再開}%en{Forcibly Resume Suspended Task}
 * @param  tskid    %jp{再開対象のタスクのID番号}%en{ID number of the task to be resumed}
 * @retval E_NOSPT  %jp{未サポート機能}%en{Unsupported function}
 */
ER frsm_tsk(
		ID tskid)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_FRSM_TSK */



/* end of file */

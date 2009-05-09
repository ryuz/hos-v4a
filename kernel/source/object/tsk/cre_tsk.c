/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  cre_tsk.c
 * @brief %jp{タスクの生成}%en{Create Task}
 *
 * Copyright (C) 1998-2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"


#if _KERNEL_SPT_CRE_TSK


/** %jp{タスクの生成}%en{Create Task}
 * @param  tskid	%jp{タスクID}%en{ID number of the task to be created}
 * @param  pk_ctsk	%jp{タスク生成情報を入れたパケットへのポインタ}%en{Pointer to the packet containing the task creation information}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 * @retval E_ID     %jp{不正ID番号(tskidが不正あるいは使用できない)}%en{Invalid ID number(tskid is invalid or unusable)}
 * @retval E_NOMEM	%jp{メモリ不足}%en{Insufficient memory}
 * @retval E_PAR    %jp{パラメータエラー}%en{Perameter error}
 * @retval E_RSATR  %jp{予約属性(tskatrが不正あるいは使用できない)}%en{Reserved attribute(tskatr is invalid or unusable)}
 */
ER cre_tsk(
		ID				tskid,
		const T_CTSK	*pk_ctsk)
{
	ER ercd;

	_KERNEL_ENTER_SVC();		/* %jp{サービスコールに入る}%en{enter service-call} */
	
	/* %jp{IDチェック}%en{check ID} */
#if _KERNEL_SPT_CRE_TSK_E_ID
	if ( _KERNEL_TSK_CHECK_EXS(tskid) )
	{
		_KERNEL_LEAVE_SVC();		/* %jp{サービスコールから出る}%en{leave service-call} */
		return E_OBJ;				/* %jp{ID番号不足} */
	}
#endif
	
	/* %jp{タスク生成} */
	ercd = _kernel_cre_tsk(tskid, pk_ctsk);

	_KERNEL_LEAVE_SVC();		/* %jp{サービスコールから出る}%en{leave service-call} */
	
	return ercd;	/* 成功 */
}


#else	/* _KERNEL_SPT_CRE_TSK */


#if _KERNEL_SPT_CRE_TSK_E_NOSPT

/** %jp{タスクの生成}%en{Create Task}
 * @param  tskid	%jp{タスクID}%en{ID number of the task to be created}
 * @param  pk_ctsk	%jp{タスク生成情報を入れたパケットへのポインタ}%en{Pointer to the packet containing the task creation information}
 * @retval E_NOSPT  %jp{未サポート機能}%en{Unsupported function}
 */
ER cre_tsk(
		ID				tskid,
		const T_CTSK	*pk_ctsk)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_CRE_TSK */



/* end of file */

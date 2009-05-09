/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  acre_tsk.c
 * @brief %jp{タスクの生成(ID番号自動割付け)}%en{Create Task(ID Number Automatic Assignment)}
 *
 * Copyright (C) 1998-2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"


#if _KERNEL_SPT_ACRE_TSK


/** %jp{タスクの生成}%en{Create Task}
 * @param  tskid	%jp{タスクID}%en{ID number of the task to be created}
 * @param  pk_ctsk	%jp{タスク生成情報を入れたパケットへのポインタ}%en{Pointer to the packet containing the task creation information}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 * @retval E_NOID   %jp{ID番号不足}%en{No ID number available}
 * @retval E_NOMEM	%jp{メモリ不足}%en{Insufficient memory}
 * @retval E_PAR    %jp{パラメータエラー}%en{Perameter error}
 * @retval E_RSATR  %jp{予約属性(tskatrが不正あるいは使用できない)}%en{Reserved attribute(tskatr is invalid or unusable)}
 */
ER_ID acre_tsk(
		const T_CTSK *pk_ctsk)
{
	ID    tskid;
	ER_ID erid;

	_KERNEL_ENTER_SVC();		/* %jp{サービスコールに入る}%en{enter service-call} */
	
	/* %jp{空きID探索} */
#if _KERNEL_ACRE_TSK_ASCENDING_ORDER
	/* %jp{空きID昇順探索} */
	for ( tskid = _KERNEL_TSK_TMIN_ID; tskid <= _KERNEL_TSK_TMAX_ID; tskid++ )
	{
		if ( !_KERNEL_TSK_CHECK_EXS(tskid) )
		{
			break;
		}
	}
	if ( tskid > _KERNEL_TSK_TMAX_ID )
	{
		_KERNEL_LEAVE_SVC();		/* %jp{サービスコールから出る}%en{leave service-call} */
		return E_NOID;				/* %jp{ID番号不足}%en{No ID number available} */
	}
#else
	/* %jp{空きID降順探索} */
	for ( tskid = _KERNEL_TSK_TMAX_ID; tskid >= _KERNEL_TSK_TMIN_ID; tskid-- )
	{
		if ( !_KERNEL_TSK_CHECK_EXS(tskid) )
		{
			break;
		}
	}
	if ( tskid < _KERNEL_TSK_TMIN_ID )
	{
		_KERNEL_LEAVE_SVC();		/* %jp{サービスコールから出る}%en{leave service-call} */
		return E_NOID;				/* %jp{ID番号不足}%en{No ID number available} */
	}
#endif
	
	/* %jp{タスク生成} */
	erid = (ER_ID)_kernel_cre_tsk(tskid, pk_ctsk);
	if ( erid == E_OK )
	{
		erid = (ER_ID)tskid;
	}
	
	_KERNEL_LEAVE_SVC();		/* %jp{サービスコールから出る}%en{leave service-call} */
	
	return erid;
}



#else	/* _KERNEL_SPT_ACRE_TSK */


#if _KERNEL_SPT_ACRE_TSK_E_NOSPT

/** %jp{タスクの生成}%en{Create Task}
 * @param  tskid	%jp{タスクID}%en{ID number of the task to be created}
 * @param  pk_ctsk	%jp{タスク生成情報を入れたパケットへのポインタ}%en{Pointer to the packet containing the task creation information}
 * @retval E_NOSPT  %jp{未サポート機能}%en{Unsupported function}
 */
ER acre_tsk(
		const T_CTSK	*pk_ctsk)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_ACRE_TSK */


/* end of file */

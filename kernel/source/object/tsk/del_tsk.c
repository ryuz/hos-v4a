/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  del_tsk.c
 * @brief %jp{タスクの削除}%en{Delete Task}
 *
 * Copyright (C) 1998-2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/tskobj.h"



#if _KERNEL_SPT_DEL_TSK


/** %jp{タスクの削除}%en{Delete Task}
 * @param  tskid    %jp{削除対象のタスクのID番号}%en{ID number of the task to be deleted}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 * @retval E_ID     %jp{不正ID番号(tskidが不正あるいは使用できない)}%en{Invalid ID number(tskid is invalid or unusable)}
 * @retval E_NOEXS  %jp{オブジェクト未生成(対象タスクが未登録)}%en{Non-existant object(specified task is not registerd)}
 */
ER del_tsk(ID tskid)
{
	_KERNEL_T_TCB_PTR	tcb;
	
	/* %jp{IDチェック}%en{check ID} */
#if _KERNEL_SPT_DEL_TSK_E_ID
	if ( !_KERNEL_TSK_CHECK_TSKID(tskid) )
	{
		return E_ID;			/* %jp{不正ID番号}%en{Invalid ID number} */
	}	
#endif
	
	_KERNEL_ENTER_SVC();		/* %jp{サービスコールに入る}%en{enter service-call} */
	
	/* %jp{存在チェック}%en{check object} */
#if _KERNEL_SPT_DEL_TSK_E_NOEXS
	if ( !_KERNEL_TSK_CHECK_EXS(tskid) )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
		return E_NOEXS;
	}
#endif
	
	/* %jp{コントロールブロック取得} */
	tcb = _KERNEL_TSK_ID2TCB(tskid);
	
#if _KERNEL_SPT_DEL_TSK_E_OBJ
	if ( _KERNEL_TSK_GET_TSKSTAT(tcb) != _KERNEL_TTS_DMT )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
		return E_OBJ;
	}
#endif
	
	
	/* %jp{オブジェクト削除} */
#if _KERNEL_TCB_ALGORITHM == _KERNEL_TCB_ALG_PTRARRAY
	_KERNEL_SYS_FRE_HEP(tcb);			/* %jp{メモリ開放} */
	_KERNEL_TSK_ID2TCB(tskid) = NULL;
#elif _KERNEL_TCB_ALGORITHM == _KERNEL_TCB_ALG_BLKARRAY
	_KERNEL_TSK_SET_TASK(tcb, 0);
#endif
	
	_KERNEL_LEAVE_SVC();		/* %jp{サービスコールから出る}%en{leave service-call} */
	
	return E_OK;
}


#else	/* _KERNEL_SPT_DEL_TSK */


#if _KERNEL_SPT_DEL_TSK_E_NOSPT

/** %jp{タスクの削除}%en{Delete Task}
 * @param  tskid    %jp{削除対象のタスクのID番号}%en{ID number of the task to be deleted}
 * @retval E_NOSPT  %jp{未サポート機能}%en{Unsupported function}
 */
ER del_tsk(ID tskid)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_DEL_TSK */



/* end of file */

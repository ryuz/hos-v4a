/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  del_sem.c
 * @brief %jp{セマフォの削除}%en{Delete Semaphore}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/semobj.h"



#if _KERNEL_SPT_DEL_SEM


/** %jp{セマフォの削除}%en{Delete Semaphore}
 * @param  semid    %jp{削除対象のセマフォのID番号}%en{ID number of the semaphore to be deleted}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 * @retval E_ID     %jp{不正ID番号(semidが不正あるいは使用できない)}%en{Invalid ID number(semid is invalid or unusable)}
 * @retval E_NOEXS  %jp{オブジェクト未生成(対象セマフォが未登録)}%en{Non-existant object(specified semaphore is not registerd)}
 */
ER del_sem(ID semid)
{
	_KERNEL_T_SEMCB  *semcb;
	_KERNEL_T_QUE    *pk_que;
	_KERNEL_T_TSKHDL tskhdl;
	_KERNEL_T_TCB    *tcb;

	/* %jp{IDチェック}%en{check ID} */
#if _KERNEL_SPT_DEL_SEM_E_ID
	if ( !_KERNEL_SEM_CHECK_SEMID(semid) )
	{
		return E_ID;	/* %jp{不正ID番号}%en{Invalid ID number} */
	}	
#endif
	
	_KERNEL_ENTER_SVC();	/* %jp{サービスコールに入る}%en{enter service-call} */
	
	/* %jp{存在チェック}%en{check object} */
#if _KERNEL_SPT_DEL_SEM_E_NOEXS
	if ( !_KERNEL_SEM_CHECK_EXS(semid) )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
		return E_NOEXS;
	}
#endif
	
	/* %jp{セマフォコントロールブロック取得} */
	semcb = _KERNEL_SEM_ID2SEMCB(semid);
	
	/* %jp{待ち行列取得} */
	pk_que = _KERNEL_SEM_GET_QUE(semcb);
	
	/* %jp{待ち行列のタスクを全て起床} */
	while ( (tskhdl = _KERNEL_RMH_QUE(pk_que)) != _KERNEL_TSKHDL_NULL )
	{
		/* %jp{待ちタスクがあれば待ち解除} */
		tcb = _KERNEL_TSK_TSKHDL2TCB(tskhdl);		/* %jp{TCB取得} */
		_KERNEL_TSK_SET_ERCD(tcb, E_DLT);			/* %jp{エラーコード設定} */
		_KERNEL_SEM_RMV_TOQ(tskhdl);				/* %jp{タイムアウトキューから外す} */
		_KERNEL_DSP_WUP_TSK(tskhdl);				/* %jp{タスクの待ち解除} */	
	}
	
	/* %jp{オブジェクト削除} */
#if _KERNEL_SEMCB_ALGORITHM == _KERNEL_SEMCB_ALG_PTRARRAY
	_KERNEL_SYS_FRE_HEP(semcb);						/* %jp{メモリ開放} */
	_KERNEL_SEM_ID2SEMCB(semid) = NULL;
#elif _KERNEL_SEMCB_ALGORITHM == _KERNEL_SEMCB_ALG_BLKARRAY
	_KERNEL_SEM_SET_MAXSEM(semcb, 0);
#endif

	_KERNEL_LEAVE_SVC();		/* %jp{サービスコールから出る}%en{leave service-call} */
	
	return E_OK;
}


#else	/* _KERNEL_SPT_DEL_SEM */


#if _KERNEL_SPT_DEL_SEM_E_NOSPT

/** %jp{セマフォの削除}%en{Delete Semaphore}
 * @param  semid    %jp{削除対象のセマフォのID番号}%en{ID number of the semaphore to be deleted}
 * @retval E_NOSPT  %jp{未サポート機能}%en{Unsupported function}
 */
ER del_sem(ID semid)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_DEL_SEM */



/* end of file */

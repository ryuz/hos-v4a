/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  ref_sem.c
 * @brief %jp{セマフォの状態参照}%en{Reference Semaphore State}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/semobj.h"



#if _KERNEL_SPT_REF_SEM


/** %jp{セマフォの状態参照}%en{Reference Semaphore State}
 * @param  semid    %jp{資源獲得対象のセマフォID番号}%en{ID number of the semaphore from which resource is acquired}
 * @param  pk_rsem  %jp{セマフォ状態を返すパケットへのポインタ}%en{Pointer to the packet returning the semaphore state}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 * @retval E_ID     %jp{不正ID番号(semidが不正あるいは使用できない)}%en{Invalid ID number(semid is invalid or unusable)}
 * @retval E_NOEXS  %jp{オブジェクト未生成(対象セマフォが未登録)}%en{Non-existant object(specified semaphore is not registerd)}
 * @retval E_PAR    %jp{パラメータエラー(pk_rsemが不正)}%en{Parameter error(pk_rsem is invalid)}
 */
ER ref_sem(ID semid, T_RSEM *pk_rsem)
{
	_KERNEL_T_SEMCB_PTR semcb;
	
	/* %jp{ID のチェック} */
#if _KERNEL_SPT_REF_SEM_E_ID
	if ( !_KERNEL_SEM_CHECK_SEMID(semid) )
	{
		return E_ID;	/* %jp{不正ID番号}%en{Invalid ID number} */
	}
#endif
	
#if _KERNEL_SPT_REF_SEM_E_PAR
	if ( pk_rsem == NULL )
	{
		return E_PAR;	/* %jp{パラメータエラー}%en{Parameter error} */
	}
#endif
		
	_KERNEL_ENTER_SVC();		/* %jp{サービスコールに入る}%en{enter service-call} */
	
	/* %jp{オブジェクト存在チェック} */
#if _KERNEL_SPT_REF_SEM_E_NOEXS
	if ( !_KERNEL_SEM_CHECK_EXS(semid) )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
		return E_NOEXS;			/* %jp{オブジェクト未生成}%en{Non-existant object} */
	}
#endif

	/* %jp{セマフォコントロールブロック取得} */
	semcb = _KERNEL_SEM_ID2SEMCB(semid);
	
	/* %jp{情報取得} */
	pk_rsem->wtskid = _KERNEL_TSK_GET_TSKID(_KERNEL_REF_QUE(_KERNEL_SEM_GET_QUE(semcb)));
	pk_rsem->semcnt = _KERNEL_SEM_GET_SEMCNT(semcb);
	
	_KERNEL_LEAVE_SVC();	/* %jp{オブジェクト未生成}%en{Non-existant object} */
	
	return E_OK;
}


#else	/* _KERNEL_SPT_REF_SEM */


#if _KERNEL_SPT_REF_SEM_E_NOSPT

/** %jp{セマフォ資源の獲得(ポーリング)}%en{Acquire Semaphore Resource(Polling)}
 * @param  semid    %jp{資源獲得対象のセマフォID番号}%en{ID number of the semaphore from which resource is acquired}
 * @retval E_NOSPT  %jp{未サポート機能}%en{Unsupported function}
 */
ER ref_sem(ID semid, T_RSEM *pk_rsem)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_REF_SEM */



/* end of file */

/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  cre_sem.c
 * @brief %jp{セマフォの生成}%en{Create Semaphore}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/semobj.h"



#if _KERNEL_SPT_CRE_SEM


/** %jp{セマフォの生成}%en{Create Semaphore}
 * @param  semid    %jp{生成対象のセマフォのID番号}%en{ID number of the semaphore to be created}
 * @param  pk_ctsk	%jp{セマフォ生成情報を入れたパケットへのポインタ}%en{Pointer to the packet containing the semaphore creation information}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 * @retval E_ID     %jp{不正ID番号(semidが不正あるいは使用できない)}%en{Invalid ID number(semid is invalid or unusable)}
 * @retval E_RSATR  %jp{予約属性(sematrが不正あるいは使用できない)}%en{Reserved attribute(sematr is invalid or unusable)}
 * @retval E_OBJ    %jp{オブジェクト状態エラー(対象セマフォが登録済み)}%en{Object state error(specified semaphore is already registerd)}
 */
ER cre_sem(ID semid, const T_CSEM *pk_csem)
{
	ER ercd;

	/* %jp{IDチェック}%en{check ID} */
#if _KERNEL_SPT_CRE_SEM_E_ID
	if ( !_KERNEL_SEM_CHECK_SEMID(semid) )
	{
		return E_ID;	/* %jp{不正ID番号}%en{Invalid ID number} */
	}	
#endif

	/* %jp{属性チェック}%en{check attribute} */
#if _KERNEL_SPT_CRE_SEM_E_RSATR
	if ( ((pk_csem->sematr & TA_TPRI) == 0 && !_KERNEL_SPT_SEM_TA_TFIFO)
		|| ((pk_csem->sematr & TA_TPRI) != 0 && !_KERNEL_SPT_SEM_TA_TPRI) )
	{
		return E_RSATR;	/* %jp{予約属性}%en{Reserved attribute} */
	}
#endif
	
	_KERNEL_ENTER_SVC();	/* %jp{サービスコールに入る}%en{enter service-call} */
	
	/* %jp{存在チェック}%en{check object} */
#if _KERNEL_SPT_CRE_SEM_E_OBJ
	if ( _KERNEL_SEM_CHECK_EXS(semid) )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
		return E_OBJ;			/* %jp{オブジェクト状態エラー}%en{Object state error} */
	}
#endif
	
	/* %jp{オブジェクト生成}%en{create object} */
	ercd = _kernel_cre_sem(semid, pk_csem);
	
	_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
	
	return ercd;
}


#else	/* _KERNEL_SPT_CRE_SEM */


#if _KERNEL_SPT_CRE_SEM_E_NOSPT

/** %jp{セマフォの生成}%en{Create Semaphore}
 * @param  semid    %jp{生成対象のセマフォのID番号}%en{ID number of the semaphore to be created}
 * @param  pk_ctsk	%jp{セマフォ生成情報を入れたパケットへのポインタ}%en{Pointer to the packet containing the semaphore creation information}
 * @retval E_NOSPT  %jp{未サポート機能}%en{Unsupported function}
 */
ER cre_sem(ID semid, const T_CSEM *pk_csem)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_CRE_SEM */



/* end of file */

/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  pol_sem.c
 * @brief %jp{セマフォ資源の獲得(ポーリング)}%en{Acquire Semaphore Resource(Polling)}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/semobj.h"



#if _KERNEL_SPT_POL_SEM


#if _KERNEL_SPT_TWAI_SEM && (_KERNEL_OPT_CODE_SIZE <= _KERNEL_OPT_SPEED)	/* %jp{twai_semありで、サイズ優先なら} */

/** %jp{セマフォ資源の獲得(ポーリング)}%en{Acquire Semaphore Resource(Polling)}
 * @param  semid    %jp{資源獲得対象のセマフォID番号}%en{ID number of the semaphore from which resource is acquired}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 * @retval E_ID     %jp{不正ID番号(semidが不正あるいは使用できない)}%en{Invalid ID number(semid is invalid or unusable)}
 * @retval E_NOEXS  %jp{オブジェクト未生成(対象セマフォが未登録)}%en{Non-existant object(specified semaphore is not registerd)}
 * @retval E_TMOUT  %jp{ポーリング失敗}%en{Polling failure}
 */
ER pol_sem(ID semid)
{
	/* %jp{pol_semやtwai_semと共通処理とする} */
	return _kernel_wai_sem(semid, TMO_POL);
}

#else

/** %jp{セマフォ資源の獲得(ポーリング)}%en{Acquire Semaphore Resource(Polling)}
 * @param  semid    %jp{資源獲得対象のセマフォID番号}%en{ID number of the semaphore from which resource is acquired}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 * @retval E_ID     %jp{不正ID番号(semidが不正あるいは使用できない)}%en{Invalid ID number(semid is invalid or unusable)}
 * @retval E_NOEXS  %jp{オブジェクト未生成(対象セマフォが未登録)}%en{Non-existant object(specified semaphore is not registerd)}
 * @retval E_TMOUT  %jp{ポーリング失敗}%en{Polling failure}
 */
ER pol_sem(ID semid)
{
	_KERNEL_T_SEMCB_PTR  semcb;
	_KERNEL_SEM_T_SEMCNT semcnt;
	ER                   ercd;
	
	/* %jp{ID のチェック} */
#if _KERNEL_SPT_POL_SEM_E_ID
	if ( !_KERNEL_SEM_CHECK_SEMID(semid) )
	{
		return E_ID;	/* %jp{不正ID番号}%en{Invalid ID number} */
	}
#endif
	
	_KERNEL_ENTER_SVC();		/* %jp{サービスコールに入る}%en{enter service-call} */
	
	/* %jp{オブジェクト存在チェック} */
#if _KERNEL_SPT_POL_SEM_E_NOEXS
	if ( !_KERNEL_SEM_CHECK_EXS(semid) )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
		return E_NOEXS;			/* %jp{オブジェクト未生成}%en{Non-existant object} */
	}
#endif

	/* %jp{セマフォコントロールブロック取得} */
	semcb = _KERNEL_SEM_ID2SEMCB(semid);
	
	/* %jp{セマフォカウンタ取得} */
	semcnt = _KERNEL_SEM_GET_SEMCNT(semcb);

	/* %jp{資源数チェック} */
	if ( semcnt > 0 ) 
	{
		/* %jp{セマフォ資源が獲得} */
		_KERNEL_SEM_SET_SEMCNT(semcb, semcnt - 1); 		/* %jp{セマフォ資源の獲得} */
		ercd = E_OK;
	}
	else
	{
		ercd = E_TMOUT;
	}
	
	
	_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
	
	return ercd;
}

#endif


#else	/* _KERNEL_SPT_POL_SEM */


#if _KERNEL_SPT_POL_SEM_E_NOSPT

/** %jp{セマフォ資源の獲得(ポーリング)}%en{Acquire Semaphore Resource(Polling)}
 * @param  semid    %jp{資源獲得対象のセマフォID番号}%en{ID number of the semaphore from which resource is acquired}
 * @retval E_NOSPT  %jp{未サポート機能}%en{Unsupported function}
 */
ER wai_sem(ID semid)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_POL_SEM */



/* end of file */

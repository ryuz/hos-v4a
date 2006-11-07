/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  acre_sem.c
 * @brief %jp{セマフォの生成(ID番号自動割付け)}%en{Create Semaphore(ID Number Automatic Assignment)}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/semobj.h"



#if _KERNEL_SPT_ACRE_SEM

/** %jp{セマフォの生成(ID番号自動割付け)}%en{Create Semaphore(ID Number Automatic Assignment)}
 * @param  pk_csem	      %jp{セマフォ生成情報を入れたパケットへのポインタ}%en{Pointer to the packet containing the semaphore creation information}
 * @retval %jp{正の値}%en{positiv-value} %jp{生成したセマフォのID番号}%en{ID number of the created semaphore}
 * @retval E_NOID  %jp{ID番号不足(割付可能なセマフォIDが無い)}%en{No ID number available(there id no semaphore ID assignable)}
 * @retval E_RSATR %jp{予約属性(sematrが不正あるいは使用できない)}%en{Reserved attribute(sematr is invalid or unusable)}
 */
ER_ID acre_sem(const T_CSEM *pk_csem)
{
	ID    semid;
	ER_ID erid;

	/* %jp{属性チェック}%en{check attribute} */
#if _KERNEL_SPT_ACRE_SEM_E_RSATR
	if ( ((pk_csem->sematr & TA_TPRI) == 0 && !_KERNEL_SPT_SEM_TA_TFIFO)
		|| ((pk_csem->sematr & TA_TPRI) != 0 && !_KERNEL_SPT_SEM_TA_TPRI) )
	{
		return E_RSATR;	/* %jp{予約属性}%en{Reserved attribute} */
	}
#endif

	_KERNEL_ENTER_SVC();		/* %jp{サービスコールに入る}%en{enter service-call} */
	
	/* %jp{空きID探索} */
	for ( semid = _KERNEL_SEM_TMAX_ID; semid >= _KERNEL_SEM_TMIN_ID; semid-- )
	{
		if ( !_KERNEL_SEM_CHECK_EXS(semid) )
		{
			break;
		}
	}

	/* %jp{空きID探索チェック} */
#if _KERNEL_SPT_ACRE_SEM_E_NOID
	if ( semid < _KERNEL_SEM_TMIN_ID )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
		return E_NOID;			/* %jp{ID番号不足} */
	}
#endif
	
	/* %jp{オブジェクト生成} */
#if (_KERNEL_SEMCB_ALGORITHM == _KERNEL_SEMCB_ALG_PTRARRAY) && _KERNEL_SPT_ACRE_SEM_E_NOMEM
	erid = (ER_ID)_kernel_cre_sem(semid, pk_csem);
	if ( erid == E_OK )
	{
		erid = (ER_ID)semid;	/* %jp{エラーでなければセマフォIDを格納} */
	}
#else
	_kernel_cre_sem(semid, pk_csem);
	erid = (ER_ID)semid;		/* %jp{セマフォIDを格納} */
#endif

	_KERNEL_LEAVE_SVC();		/* %jp{サービスコールから出る}%en{leave service-call} */
	
	return erid;
}


#else	/* _KERNEL_SPT_ACRE_SEM */


#if _KERNEL_SPT_ACRE_SEM_E_NOSPT


/** %jp{セマフォの生成(ID番号自動割付け)}%en{Create Semaphore(ID Number Automatic Assignment)}
 * @param  pk_csem  %jp{セマフォ生成情報を入れたパケットへのポインタ}%en{Pointer to the packet containing the semaphore creation information}
 * @retval E_NOSPT  %jp{未サポート機能}%en{Unsupported function}
 */
ER_ID acre_sem(const T_CSEM *pk_csem)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_ACRE_SEM */



/* end of file */

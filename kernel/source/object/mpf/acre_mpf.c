/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  acre_mpf.c
 * @brief %jp{固定長メモリプールの生成(ID番号自動割付け)}%en{Create fixed-sized memory pool(ID Number Automatic Assignment)}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/mpfobj.h"



#if _KERNEL_SPT_ACRE_MPF

/** %jp{固定長メモリプールの生成(ID番号自動割付け)}%en{Create fixed-sized memory pool(ID Number Automatic Assignment)}
 * @param  pk_cmpf	      %jp{固定長メモリプール生成情報を入れたパケットへのポインタ}%en{Pointer to the packet containing the fixed-sized memory pool creation information}
 * @retval %jp{正の値}%en{positiv-value} %jp{生成した固定長メモリプールのID番号}%en{ID number of the created fixed-sized memory pool}
 * @retval E_NOID  %jp{ID番号不足(割付可能な固定長メモリプールIDが無い)}%en{No ID number available(there id no fixed-sized memory pool ID assignable)}
 * @retval E_RSATR %jp{予約属性(mpfatrが不正あるいは使用できない)}%en{Reserved attribute(mpfatr is invalid or unusable)}
 */
ER_ID acre_mpf(const T_CMPF *pk_cmpf)
{
	ID    mpfid;
	ER_ID erid;

	/* %jp{属性チェック}%en{check attribute} */
#if _KERNEL_SPT_ACRE_MPF_E_RSATR
	if ( ((pk_cmpf->mpfatr & TA_TPRI) == 0 && !_KERNEL_SPT_MPF_TA_TFIFO)
		|| ((pk_cmpf->mpfatr & TA_TPRI) != 0 && !_KERNEL_SPT_MPF_TA_TPRI) )
	{
		return E_RSATR;	/* %jp{予約属性}%en{Reserved attribute} */
	}
#endif

	_KERNEL_ENTER_SVC();		/* %jp{サービスコールに入る}%en{enter service-call} */
	
	/* %jp{空きID探索} */
	for ( mpfid = _KERNEL_MPF_TMAX_ID; mpfid >= _KERNEL_MPF_TMIN_ID; mpfid-- )
	{
		if ( !_KERNEL_MPF_CHECK_EXS(mpfid) )
		{
			break;
		}
	}

	/* %jp{空きID探索チェック} */
#if _KERNEL_SPT_ACRE_MPF_E_NOID
	if ( mpfid < _KERNEL_MPF_TMIN_ID )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
		return E_NOID;			/* %jp{ID番号不足} */
	}
#endif
	
	/* %jp{オブジェクト生成} */
#if (_KERNEL_MPFCB_ALGORITHM == _KERNEL_MPFCB_ALG_PTRARRAY) && _KERNEL_SPT_ACRE_MPF_E_NOMEM
	erid = (ER_ID)_kernel_cre_mpf(mpfid, pk_cmpf);
	if ( erid == E_OK )
	{
		erid = (ER_ID)mpfid;	/* %jp{エラーでなければ固定長メモリプールIDを格納} */
	}
#else
	_kernel_cre_mpf(mpfid, pk_cmpf);
	erid = (ER_ID)mpfid;		/* %jp{固定長メモリプールIDを格納} */
#endif

	_KERNEL_LEAVE_SVC();		/* %jp{サービスコールから出る}%en{leave service-call} */
	
	return erid;
}


#else	/* _KERNEL_SPT_ACRE_MPF */


#if _KERNEL_SPT_ACRE_MPF_E_NOSPT


/** %jp{固定長メモリプールの生成(ID番号自動割付け)}%en{Create Semaphore(ID Number Automatic Assignment)}
 * @param  pk_cmpf  %jp{固定長メモリプール生成情報を入れたパケットへのポインタ}%en{Pointer to the packet containing the mpfaphore creation information}
 * @retval E_NOSPT  %jp{未サポート機能}%en{Unsupported function}
 */
ER_ID acre_mpf(const T_CMPF *pk_cmpf)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_ACRE_MPF */



/* end of file */

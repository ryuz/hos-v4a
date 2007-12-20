/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  acre_mtx.c
 * @brief %jp{ミューテックスの生成(ID番号自動割付け)}%en{Create Mutex(ID Number Automatic Assignment)}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/mtxobj.h"



#if _KERNEL_SPT_ACRE_MTX

/** %jp{ミューテックスの生成(ID番号自動割付け)}%en{Create Mutex(ID Number Automatic Assignment)}
 * @param  pk_cmtx	      %jp{ミューテックス生成情報を入れたパケットへのポインタ}%en{Pointer to the packet containing the mutex creation information}
 * @retval %jp{正の値}%en{positiv-value} %jp{生成したミューテックスのID番号}%en{ID number of the created mutex}
 * @retval E_NOID  %jp{ID番号不足(割付可能なミューテックスIDが無い)}%en{No ID number available(there id no mutex ID assignable)}
 * @retval E_RSATR %jp{予約属性(mtxatrが不正あるいは使用できない)}%en{Reserved attribute(mtxatr is invalid or unusable)}
 */
ER_ID acre_mtx(const T_CMTX *pk_cmtx)
{
	ID    mtxid;
	ER_ID erid;

	/* %jp{属性チェック}%en{check attribute} */
#if _KERNEL_SPT_ACRE_MTX_E_RSATR
	if ( ((pk_cmtx->mtxatr & TA_TPRI) == 0 && !_KERNEL_SPT_MTX_TA_TFIFO)
		|| ((pk_cmtx->mtxatr & TA_TPRI) != 0 && !_KERNEL_SPT_MTX_TA_TPRI) )
	{
		return E_RSATR;	/* %jp{予約属性}%en{Reserved attribute} */
	}
#endif

	_KERNEL_ENTER_SVC();		/* %jp{サービスコールに入る}%en{enter service-call} */
	
	/* %jp{空きID探索} */
	for ( mtxid = _KERNEL_MTX_TMAX_ID; mtxid >= _KERNEL_MTX_TMIN_ID; mtxid-- )
	{
		if ( !_KERNEL_MTX_CHECK_EXS(mtxid) )
		{
			break;
		}
	}

	/* %jp{空きID探索チェック} */
#if _KERNEL_SPT_ACRE_MTX_E_NOID
	if ( mtxid < _KERNEL_MTX_TMIN_ID )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
		return E_NOID;			/* %jp{ID番号不足} */
	}
#endif
	
	/* %jp{オブジェクト生成} */
#if (_KERNEL_MTXCB_ALGORITHM == _KERNEL_MTXCB_ALG_PTRARRAY) && _KERNEL_SPT_ACRE_MTX_E_NOMEM
	erid = (ER_ID)_kernel_cre_mtx(mtxid, pk_cmtx);
	if ( erid == E_OK )
	{
		erid = (ER_ID)mtxid;	/* %jp{エラーでなければミューテックスIDを格納} */
	}
#else
	_kernel_cre_mtx(mtxid, pk_cmtx);
	erid = (ER_ID)mtxid;		/* %jp{ミューテックスIDを格納} */
#endif

	_KERNEL_LEAVE_SVC();		/* %jp{サービスコールから出る}%en{leave service-call} */
	
	return erid;
}


#else	/* _KERNEL_SPT_ACRE_MTX */


#if _KERNEL_SPT_ACRE_MTX_E_NOSPT


/** %jp{ミューテックスの生成(ID番号自動割付け)}%en{Create Mutex(ID Number Automatic Assignment)}
 * @param  pk_cmtx  %jp{ミューテックス生成情報を入れたパケットへのポインタ}%en{Pointer to the packet containing the mutex creation information}
 * @retval E_NOSPT  %jp{未サポート機能}%en{Unsupported function}
 */
ER_ID acre_mtx(const T_CMTX *pk_cmtx)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_ACRE_MTX */



/* end of file */

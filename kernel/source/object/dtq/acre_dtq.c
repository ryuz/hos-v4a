/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  acre_dtq.c
 * @brief %jp{データキューの生成(ID番号自動割付け)}%en{Create Data queue(ID Number Automatic Assignment)}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/dtqobj.h"



#if _KERNEL_SPT_ACRE_DTQ

/** %jp{データキューの生成(ID番号自動割付け)}%en{Create Data queue(ID Number Automatic Assignment)}
 * @param  pk_cdtq	      %jp{データキュー生成情報を入れたパケットへのポインタ}%en{Pointer to the packet containing the data queue creation information}
 * @retval %jp{正の値}%en{positiv-value} %jp{生成したデータキューのID番号}%en{ID number of the created data queue}
 * @retval E_NOID  %jp{ID番号不足(割付可能なデータキューIDが無い)}%en{No ID number available(there id no data queue ID assignable)}
 * @retval E_RSATR %jp{予約属性(dtqatrが不正あるいは使用できない)}%en{Reserved attribute(dtqatr is invalid or unusable)}
 */
ER_ID acre_dtq(const T_CDTQ *pk_cdtq)
{
	ID    dtqid;
	ER_ID erid;

	/* %jp{属性チェック}%en{check attribute} */
#if _KERNEL_SPT_ACRE_DTQ_E_RSATR
	if ( ((pk_cdtq->dtqatr & TA_TPRI) == 0 && !_KERNEL_SPT_DTQ_TA_TFIFO)
		|| ((pk_cdtq->dtqatr & TA_TPRI) != 0 && !_KERNEL_SPT_DTQ_TA_TPRI) )
	{
		return E_RSATR;	/* %jp{予約属性}%en{Reserved attribute} */
	}
#endif

	_KERNEL_ENTER_SVC();		/* %jp{サービスコールに入る}%en{enter service-call} */
	
	/* %jp{空きID探索} */
	for ( dtqid = _KERNEL_DTQ_TMAX_ID; dtqid >= _KERNEL_DTQ_TMIN_ID; dtqid-- )
	{
		if ( !_KERNEL_DTQ_CHECK_EXS(dtqid) )
		{
			break;
		}
	}

	/* %jp{空きID探索チェック} */
#if _KERNEL_SPT_ACRE_DTQ_E_NOID
	if ( dtqid < _KERNEL_DTQ_TMIN_ID )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
		return E_NOID;			/* %jp{ID番号不足} */
	}
#endif
	
	/* %jp{オブジェクト生成} */
#if (_KERNEL_DTQCB_ALGORITHM == _KERNEL_DTQCB_ALG_PTRARRAY) && _KERNEL_SPT_ACRE_DTQ_E_NOMEM
	erid = (ER_ID)_kernel_cre_dtq(dtqid, pk_cdtq);
	if ( erid == E_OK )
	{
		erid = (ER_ID)dtqid;	/* %jp{エラーでなければデータキューIDを格納} */
	}
#else
	_kernel_cre_dtq(dtqid, pk_cdtq);
	erid = (ER_ID)dtqid;		/* %jp{データキューIDを格納} */
#endif

	_KERNEL_LEAVE_SVC();		/* %jp{サービスコールから出る}%en{leave service-call} */
	
	return erid;
}


#else	/* _KERNEL_SPT_ACRE_DTQ */


#if _KERNEL_SPT_ACRE_DTQ_E_NOSPT


/** %jp{データキューの生成(ID番号自動割付け)}%en{Create Data queue(ID Number Automatic Assignment)}
 * @param  pk_cdtq  %jp{データキュー生成情報を入れたパケットへのポインタ}%en{Pointer to the packet containing the data queue creation information}
 * @retval E_NOSPT  %jp{未サポート機能}%en{Unsupported function}
 */
ER_ID acre_dtq(const T_CDTQ *pk_cdtq)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_ACRE_DTQ */



/* end of file */

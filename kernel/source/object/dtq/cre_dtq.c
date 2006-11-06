/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  cre_dtq.c
 * @brief %jp{データキューの生成}%en{Create Data queue}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/dtqobj.h"



#if _KERNEL_SPT_CRE_DTQ


/** %jp{データキューの生成}%en{Create Data queue}
 * @param  dtqid    %jp{生成対象のデータキューのID番号}%en{ID number of the data queue to be created}
 * @param  pk_ctsk	%jp{データキュー生成情報を入れたパケットへのポインタ}%en{Pointer to the packet containing the data queue creation information}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 * @retval E_ID     %jp{不正ID番号(dtqidが不正あるいは使用できない)}%en{Invalid ID number(dtqid is invalid or unusable)}
 * @retval E_RSATR  %jp{予約属性(dtqatrが不正あるいは使用できない)}%en{Reserved attribute(dtqatr is invalid or unusable)}
 * @retval E_OBJ    %jp{オブジェクト状態エラー(対象データキューが登録済み)}%en{Object state error(specified data queue is already registerd)}
 */
ER cre_dtq(ID dtqid, const T_CDTQ *pk_cdtq)
{
	ER ercd;

	/* %jp{IDチェック}%en{check ID} */
#if _KERNEL_SPT_CRE_DTQ_E_ID
	if ( !_KERNEL_DTQ_CHECK_DTQID(dtqid) )
	{
		return E_ID;	/* %jp{不正ID番号}%en{Invalid ID number} */
	}	
#endif

	/* %jp{属性チェック}%en{check attribute} */
#if _KERNEL_SPT_CRE_DTQ_E_RSATR
	if ( ((pk_cdtq->dtqatr & TA_TPRI) == 0 && !_KERNEL_SPT_DTQ_TA_TFIFO)
		|| ((pk_cdtq->dtqatr & TA_TPRI) != 0 && !_KERNEL_SPT_DTQ_TA_TPRI) )
	{
		return E_RSATR;	/* %jp{予約属性}%en{Reserved attribute} */
	}
#endif
	
	_KERNEL_ENTER_SVC();	/* %jp{サービスコールに入る}%en{enter service-call} */
	
	/* %jp{存在チェック}%en{check object} */
#if _KERNEL_SPT_CRE_DTQ_E_OBJ
	if ( _KERNEL_DTQ_CHECK_EXS(dtqid) )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
		return E_OBJ;			/* %jp{オブジェクト状態エラー}%en{Object state error} */
	}
#endif
	
	/* %jp{オブジェクト生成}%en{create object} */
	ercd = _kernel_cre_dtq(dtqid, pk_cdtq);
	
	_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
	
	return ercd;
}


#else	/* _KERNEL_SPT_CRE_DTQ */


#if _KERNEL_SPT_CRE_DTQ_E_NOSPT

/** %jp{データキューの生成}%en{Create Data queue}
 * @param  dtqid    %jp{生成対象のデータキューのID番号}%en{ID number of the data queue to be created}
 * @param  pk_ctsk	%jp{データキュー生成情報を入れたパケットへのポインタ}%en{Pointer to the packet containing the data queue creation information}
 * @retval E_NOSPT  %jp{未サポート機能}%en{Unsupported function}
 */
ER cre_dtq(ID dtqid, const T_CDTQ *pk_cdtq)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_CRE_DTQ */



/* end of file */

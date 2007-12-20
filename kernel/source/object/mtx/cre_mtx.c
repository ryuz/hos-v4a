/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  cre_mtx.c
 * @brief %jp{ミューテックスの生成}%en{Create Mutex}
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/mtxobj.h"



#if _KERNEL_SPT_CRE_MTX


/** %jp{ミューテックスの生成}%en{Create Mutex}
 * @param  mtxid    %jp{生成対象のミューテックスのID番号}%en{ID number of the mutex to be created}
 * @param  pk_ctsk	%jp{ミューテックス生成情報を入れたパケットへのポインタ}%en{Pointer to the packet containing the mutex creation information}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 * @retval E_ID     %jp{不正ID番号(mtxidが不正あるいは使用できない)}%en{Invalid ID number(mtxid is invalid or unusable)}
 * @retval E_RSATR  %jp{予約属性(mtxatrが不正あるいは使用できない)}%en{Reserved attribute(mtxatr is invalid or unusable)}
 * @retval E_OBJ    %jp{オブジェクト状態エラー(対象ミューテックスが登録済み)}%en{Object state error(specified mutex is already registerd)}
 */
ER cre_mtx(ID mtxid, const T_CMTX *pk_cmtx)
{
	ER ercd;

	/* %jp{IDチェック}%en{check ID} */
#if _KERNEL_SPT_CRE_MTX_E_ID
	if ( !_KERNEL_MTX_CHECK_MTXID(mtxid) )
	{
		return E_ID;	/* %jp{不正ID番号}%en{Invalid ID number} */
	}	
#endif

	/* %jp{属性チェック}%en{check attribute} */
#if _KERNEL_SPT_CRE_MTX_E_RSATR
	if ( ((pk_cmtx->mtxatr & TA_TPRI) == 0 && !_KERNEL_SPT_MTX_TA_TFIFO)
		|| ((pk_cmtx->mtxatr & TA_TPRI) != 0 && !_KERNEL_SPT_MTX_TA_TPRI) )
	{
		return E_RSATR;	/* %jp{予約属性}%en{Reserved attribute} */
	}
#endif
	
	_KERNEL_ENTER_SVC();	/* %jp{サービスコールに入る}%en{enter service-call} */
	
	/* %jp{存在チェック}%en{check object} */
#if _KERNEL_SPT_CRE_MTX_E_OBJ
	if ( _KERNEL_MTX_CHECK_EXS(mtxid) )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
		return E_OBJ;			/* %jp{オブジェクト状態エラー}%en{Object state error} */
	}
#endif
	
	/* %jp{オブジェクト生成}%en{create object} */
	ercd = _kernel_cre_mtx(mtxid, pk_cmtx);
	
	_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
	
	return ercd;
}


#else	/* _KERNEL_SPT_CRE_MTX */


#if _KERNEL_SPT_CRE_MTX_E_NOSPT

/** %jp{ミューテックスの生成}%en{Create Mutex}
 * @param  mtxid    %jp{生成対象のミューテックスのID番号}%en{ID number of the mutex to be created}
 * @param  pk_ctsk	%jp{ミューテックス生成情報を入れたパケットへのポインタ}%en{Pointer to the packet containing the mutex creation information}
 * @retval E_NOSPT  %jp{未サポート機能}%en{Unsupported function}
 */
ER cre_mtx(ID mtxid, const T_CMTX *pk_cmtx)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_CRE_MTX */



/* end of file */

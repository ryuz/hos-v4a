/**
 *  Hyper Operating System V4 Advance
 *
 * @file  del_cyc.c
 * @brief %jp{周期ハンドラの削除}%en{Delete cyclic handler}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/cycobj.h"



#if _KERNEL_SPT_DEL_CYC


/** %jp{周期ハンドラの削除}%en{Delete cyclic handler}
 * @param  cycid    %jp{削除対象の周期ハンドラのID番号}%en{ID number of the cyclic handler to be deleted}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 * @retval E_ID     %jp{不正ID番号(cycidが不正あるいは使用できない)}%en{Invalid ID number(cycid is invalid or unusable)}
 * @retval E_NOEXS  %jp{オブジェクト未生成(対象周期ハンドラが未登録)}%en{Non-existant object(specified cyclic handler is not registerd)}
 */
ER del_cyc(ID cycid)
{
	_KERNEL_T_CYCCB  *cyccb;

	/* %jp{IDチェック}%en{check ID} */
#if _KERNEL_SPT_DEL_CYC_E_ID
	if ( !_KERNEL_CYC_CHECK_CYCID(cycid) )
	{
		return E_ID;	/* %jp{不正ID番号}%en{Invalid ID number} */
	}
#endif

	_KERNEL_ENTER_SVC();	/* %jp{サービスコールに入る}%en{enter service-call} */

	/* %jp{存在チェック}%en{check object} */
#if _KERNEL_SPT_DEL_CYC_E_NOEXS
	if ( !_KERNEL_CYC_CHECK_EXS(cycid) )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
		return E_NOEXS;
	}
#endif

	/* %jp{周期ハンドラコントロールブロック取得} */
	cyccb = _KERNEL_CYC_ID2CYCCB(cycid);

	/* %jp{オブジェクト削除} */
#if _KERNEL_CYCCB_ALGORITHM == _KERNEL_CYCCB_ALG_PTRARRAY
	_KERNEL_SYS_FRE_HEP(cyccb);						/* %jp{メモリ開放} */
	_KERNEL_CYC_ID2CYCCB(cycid) = NULL;
#elif _KERNEL_CYCCB_ALGORITHM == _KERNEL_CYCCB_ALG_BLKARRAY
	_KERNEL_CYC_SET_MAXCYC(cyccb, 0);
#endif

	_KERNEL_LEAVE_SVC();		/* %jp{サービスコールから出る}%en{leave service-call} */

	return E_OK;
}


#else	/* _KERNEL_SPT_DEL_CYC */


#if _KERNEL_SPT_DEL_CYC_E_NOSPT

/** %jp{周期ハンドラの削除}%en{Delete cyclic handler}
 * @param  cycid    %jp{削除対象の周期ハンドラのID番号}%en{ID number of the cyclic handler to be deleted}
 * @retval E_NOSPT  %jp{未サポート機能}%en{Unsupported function}
 */
ER del_cyc(ID cycid)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_DEL_cyc */



/* end of file */

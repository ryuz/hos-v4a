/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  ref_cyc.c
 * @brief %jp{周期ハンドラの状態参照}%en{Reference Cyclic Handler State}
 *
 * Copyright (C) 1998-2010 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/cycobj.h"



#if _KERNEL_SPT_REF_CYC


/** %jp{周期ハンドラの状態参照}%en{Reference Cyclic Handler State}
 * @param  cycid    %jp{資源獲得対象の周期ハンドラID番号}%en{ID number of the cycaphore from which resource is acquired}
 * @param  pk_rcyc  %jp{周期ハンドラ状態を返すパケットへのポインタ}%en{Pointer to the packet returning the cycaphore state}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 * @retval E_ID     %jp{不正ID番号(cycidが不正あるいは使用できない)}%en{Invalid ID number(cycid is invalid or unusable)}
 * @retval E_NOEXS  %jp{オブジェクト未生成(対象周期ハンドラが未登録)}%en{Non-existant object(specified cycaphore is not registerd)}
 * @retval E_PAR    %jp{パラメータエラー(pk_rcycが不正)}%en{Parameter error(pk_rcyc is invalid)}
 */
ER ref_cyc(ID cycid, T_RCYC *pk_rcyc)
{
	_KERNEL_T_CYCCB_PTR cyccb;
	
	/* %jp{ID のチェック} */
#if _KERNEL_SPT_REF_CYC_E_ID
	if ( !_KERNEL_CYC_CHECK_CYCID(cycid) )
	{
		return E_ID;	/* %jp{不正ID番号}%en{Invalid ID number} */
	}
#endif
	
#if _KERNEL_SPT_REF_CYC_E_PAR
	if ( pk_rcyc == NULL )
	{
		return E_PAR;	/* %jp{パラメータエラー}%en{Parameter error} */
	}
#endif

	_KERNEL_ENTER_SVC();		/* %jp{サービスコールに入る}%en{enter service-call} */
	
	/* %jp{オブジェクト存在チェック} */
#if _KERNEL_SPT_REF_CYC_E_NOEXS
	if ( !_KERNEL_CYC_CHECK_EXS(cycid) )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
		return E_NOEXS;			/* %jp{オブジェクト未生成}%en{Non-existant object} */
	}
#endif

	/* %jp{周期ハンドラコントロールブロック取得} */
	cyccb    = _KERNEL_CYC_ID2CYCCB(cycid);
	
	/* %jp{情報取得} */
	if( _KERNEL_CYC_GET_TIMOBJ(cyccb)->next == NULL)
	{
		pk_rcyc->cycatr = TCYC_STP;
	}
	else
	{
		pk_rcyc->cycatr = TCYC_STA;
	}
	pk_rcyc->lefttim = _KERNEL_TIMOBJ_GET_LEFTTIM( _KERNEL_CYC_GET_TIMOBJ(cyccb) );
	

	_KERNEL_LEAVE_SVC();	/* %jp{サービスコール終了} */	
	
	return E_OK;
}


#else	/* _KERNEL_SPT_REF_CYC */


#if _KERNEL_SPT_REF_CYC_E_NOSPT

/** %jp{周期ハンドラ資源の獲得(ポーリング)}%en{Acquire Cyclic Handler Resource(Polling)}
 * @param  cycid    %jp{資源獲得対象の周期ハンドラID番号}%en{ID number of the cycaphore from which resource is acquired}
 * @retval E_NOSPT  %jp{未サポート機能}%en{Unsupported function}
 */
ER ref_cyc(ID cycid, T_RCYC *pk_rcyc)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_REF_CYC */



/* end of file */

/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  cre_cyc.c
 * @brief %jp{周期ハンドラの生成(ID番号自動割付け)}%en{Create cyclic handler(ID Number Automatic Assignment)}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/cycobj.h"



#if _KERNEL_SPT_CRE_CYC

/** %jp{周期ハンドラの生成(ID番号自動割付け)}%en{Create cyclic handler(ID Number Automatic Assignment)}
 * @param  cycid		%jp{生成対象の周期ハンドラのID番号}%en{ID number of the cyclic handler to be created}
 * @param  pk_ccyc	    %jp{周期ハンドラ生成情報を入れたパケットへのポインタ}%en{Pointer to the packet containing the cyclic handler creation information}
 * @retval %jp{正の値}%en{positiv-value} %jp{生成した周期ハンドラのID番号}%en{ID number of the created cyclic handler}
 * @retval E_NOID  %jp{ID番号不足(割付可能な周期ハンドラIDが無い)}%en{No ID number available(there id no cyclic handler ID assignable)}
 * @retval E_RSATR %jp{予約属性(cycatrが不正あるいは使用できない)}%en{Reserved attribute(cycatr is invalid or unusable)}
 */
ID cre_cyc(ID cycid, const T_CCYC *pk_ccyc)
{
	ER_ID erid;
	
	/* %jp{IDチェック}%en{check ID} */
#if _KERNEL_SPT_CRE_CYC_E_ID
	if ( !_KERNEL_CYC_CHECK_CYCID(cycid) )
	{
		return E_ID;	/* %jp{不正ID番号}%en{Invalid ID number} */
	}	
#endif
	
	_KERNEL_ENTER_SVC();		/* %jp{サービスコールに入る}%en{enter service-call} */
	
	/* %jp{存在チェック}%en{check object} */
#if _KERNEL_SPT_CRE_CYC_E_OBJ
	if ( _KERNEL_CYC_CHECK_EXS(cycid) )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
		return E_OBJ;			/* %jp{オブジェクト状態エラー}%en{Object state error} */
	}
#endif
	
	/* %jp{オブジェクト生成} */
#if (_KERNEL_CYCCB_ALGORITHM == _KERNEL_CYCCB_ALG_PTRARRAY) && _KERNEL_SPT_ACRE_CYC_E_NOMEM
	erid = (ER_ID)_kernel_cre_cyc(cycid, pk_ccyc);
	if ( erid == E_OK )
	{
		erid = (ER_ID)cycid;	/* %jp{エラーでなければ周期ハンドラIDを格納} */
	}
#else
	_kernel_cre_cyc(cycid, pk_ccyc);
	erid = (ER_ID)cycid;		/* %jp{周期ハンドラIDを格納} */
#endif

	_KERNEL_LEAVE_SVC();		/* %jp{サービスコールから出る}%en{leave service-call} */
	
	return erid;
}


#else	/* _KERNEL_SPT_ACRE_CYC */


#if _KERNEL_SPT_ACRE_CYC_E_NOSPT


/** %jp{周期ハンドラの生成(ID番号自動割付け)}%en{Create cyclic handler(ID Number Automatic Assignment)}
 * @param  pk_ccyc  %jp{周期ハンドラ生成情報を入れたパケットへのポインタ}%en{Pointer to the packet containing the cyclic handler creation information}
 * @retval E_NOSPT  %jp{未サポート機能}%en{Unsupported function}
 */
ID cre_cyc(ID cycid, const T_CCYC *pk_ccyc)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_ACRE_CYC */



/* end of file */

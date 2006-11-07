/**
 *  Hyper Operating System V4 Advance
 *
 * @file  acre_mbx.c
 * @brief %jp{メールボックスの生成(ID番号自動割付)}%en{Create Mailbox(ID Number Automatic Assignment)}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/mbxobj.h"



#if _KERNEL_SPT_ACRE_MBX


/** %jp{メールボックスの生成(ID番号自動割付)}%en{Create Mailbox(ID Number Automatic Assignment)}
 * @param  pk_cmbx	      %jp{メールボックス生成情報を入れたパケットへのポインタ}%en{Pointer to the packet containing the mailbox creation information}
 * @retval %jp{正の値}%en{positiv-value} %jp{生成したメールボックスのID番号}%en{ID number of the created mailbox}
 * @retval E_NOID  %jp{ID番号不足(割付可能なメールボックスIDが無い)}%en{No ID number available(there id no mailbox ID assignable)}
 * @retval E_RSATR %jp{予約属性(mbxatrが不正あるいは使用できない)}%en{Reserved attribute(mbxatr is invalid or unusable)}
 */
ER_ID acre_mbx(const T_CMBX *pk_cmbx)
{
	ID    mbxid;
	ER_ID erid;
	
	/* %jp{属性チェック}%en{check attribute} */
#if _KERNEL_SPT_ACRE_MBX_E_RSATR
	if ( ((pk_cmbx->mbxatr & TA_TPRI) == 0 && !_KERNEL_SPT_MBX_TA_TFIFO)
		|| ((pk_cmbx->mbxatr & TA_TPRI) != 0 && !_KERNEL_SPT_MBX_TA_TPRI)
		|| ((pk_cmbx->mbxatr & TA_MPRI) == 0 && !_KERNEL_SPT_MBX_TA_MFIFO)
		|| ((pk_cmbx->mbxatr & TA_MPRI) != 0 && !_KERNEL_SPT_MBX_TA_MPRI) )
	{
		return E_RSATR;	/* %jp{予約属性}%en{Reserved attribute} */
	}
#endif

	_KERNEL_ENTER_SVC();		/* %jp{サービスコールに入る}%en{enter service-call} */
	
	/* %jp{空きID探索} */
	for ( mbxid = _KERNEL_MBX_TMAX_ID; mbxid >= _KERNEL_MBX_TMIN_ID; mbxid-- )
	{
		if ( !_KERNEL_MBX_CHECK_EXS(mbxid) )
		{
			break;
		}
	}

	/* %jp{空きID探索チェック} */
#if _KERNEL_SPT_ACRE_SEM_E_NOID
	if ( mbxid < _KERNEL_MBX_TMIN_ID )
	{
		_KERNEL_LEAVE_SVC();		/* %jp{サービスコールから出る}%en{leave service-call} */
		return E_NOID;				/* %jp{ID番号不足}%en{No ID number available} */
	}
#endif
	
	/* %jp{メールボックス生成} */
	erid = (ER_ID)_kernel_cre_mbx(mbxid, pk_cmbx);
	if ( erid == E_OK )
	{
		erid = (ER_ID)mbxid;
	}

	_KERNEL_LEAVE_SVC();		/* %jp{サービスコールから出る}%en{leave service-call} */
	
	return erid;
}


#else	/* _KERNEL_SPT_ACRE_MBX */


#if _KERNEL_SPT_ACRE_MBX_E_NOSPT

/** %jp{メールボックスの生成(ID番号自動割付)}%en{Create Eventflag(ID Number Automatic Assignment)}
 * @param  pk_cmbx	%jp{メールボックス生成情報を入れたパケットへのポインタ}%en{Pointer to the packet containing the eventflag creation information}
 * @retval E_NOSPT  %jp{未サポート機能}%en{Unsupported function}
 */
ER_ID acre_mbx(const T_CMBX *pk_cmbx)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_ACRE_MBX */



/* end of file */

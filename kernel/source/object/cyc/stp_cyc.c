/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  stp_cyc.c
 * @brief %jp{周期ハンドラの停止}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/cycobj.h"


#if _KERNEL_SPT_STP_CYC

ER stp_cyc(ID cycid)
{
	_KERNEL_T_CYCCB    *cyccb;
	_KERNEL_T_TIMOBJ   *pk_timobj;


	/* %jp{ID のチェック} */
#if _KERNEL_SPT_STP_CYC_E_ID
	if ( !_KERNEL_CYC_CHECK_CYCID(cycid) )
	{
		return E_ID;	/* %jp{ID不正} */
	}
#endif
	
	_KERNEL_ENTER_SVC();	/* %jp{サービスコール開始} */
	
	/* %jp{オブジェクト存在チェック} */
#if _KERNEL_SPT_STP_CYC_E_NOEXS
	if ( !_KERNEL_CYC_CHECK_EXS(cycid) )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコール終了} */
		return E_NOEXS;			/* %jp{オブジェクト未生成} */
	}
#endif
	
	/* %jp{コントロールブロック取得} */
	cyccb    = _KERNEL_CYC_ID2CYCCB(cycid);
	
	pk_timobj = _KERNEL_CYC_GET_TIMOBJ(cyccb);
	_KERNEL_SYS_RMV_TMQ(pk_timobj);
	
	_KERNEL_LEAVE_SVC();	/* %jp{サービスコール終了} */	

	return E_OK;
}

#endif


/* end of file */

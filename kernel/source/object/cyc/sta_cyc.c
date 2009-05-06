/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  sta_cyc.c
 * @brief %jp{周期ハンドラの開始}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/cycobj.h"


#if _KERNEL_SPT_STA_CYC

ER sta_cyc(ID cycid)
{
	_KERNEL_T_CYCCB    *cyccb;
	_KERNEL_T_CYCCB_RO *cyccb_ro;
	_KERNEL_T_TIMOBJ   *pk_timobj;
	
	
	/* %jp{ID のチェック} */
#if _KERNEL_SPT_STA_CYC_E_ID
	if ( !_KERNEL_CYC_CHECK_CYCID(cycid) )
	{
		return E_ID;	/* %jp{ID不正} */
	}
#endif
	
	_KERNEL_ENTER_SVC();	/* %jp{サービスコール開始} */
	
	/* %jp{オブジェクト存在チェック} */
#if _KERNEL_SPT_STA_CYC_E_NOEXS
	if ( !_KERNEL_CYC_CHECK_EXS(cycid) )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコール終了} */
		return E_NOEXS;			/* %jp{オブジェクト未生成} */
	}
#endif
	
	/* %jp{コントロールブロック取得} */
	cyccb    = _KERNEL_CYC_ID2CYCCB(cycid);
	cyccb_ro = _KERNEL_CYC_GET_CYCCB_RO(cycid, cyccb);

	pk_timobj = _KERNEL_CYC_GET_TIMOBJ(cyccb);
	_KERNEL_TIMOBJ_SET_TIMHDR(pk_timobj, _kernel_cyc_hdr);
	_KERNEL_TIMOBJ_SET_LEFTTIM(pk_timobj, _KERNEL_CYC_GET_CYCTIM(cyccb_ro));
	_KERNEL_SYS_ADD_TMQ(pk_timobj);

	_KERNEL_LEAVE_SVC();	/* %jp{サービスコール終了} */	

	return E_OK;
}

#endif


/* end of file */

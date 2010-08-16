/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  acre_cyc.c
 * @brief %en{Activate Task}%jp{タスクの起動}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/cycobj.h"


/** %jp{周期ハンドラ}%en{Cyclic Handler} */
void _kernel_cyc_hdr(_KERNEL_T_TIMOBJ *pk_timobj, RELTIM ovrtim)
{
	_KERNEL_T_CYCCB_PTR    cyccb;
	_KERNEL_T_CYCCB_RO_PTR cyccb_ro;
	_KERNEL_CYC_T_CYCHDR   cychdr;
	_KERNEL_CYC_T_EXINF    exinf;
    _KERNEL_CYC_T_RELTIM   cyctim;

	cyccb    = (_KERNEL_T_CYCCB_PTR)pk_timobj;
	cyccb_ro = _KERNEL_CYC_GET_CYCCB_RO(_KERNEL_CYC_CYCCB2ID(cyccb), cyccb);
	
	cychdr = _KERNEL_CYC_GET_CYCHDR(cyccb_ro);
	exinf  = _KERNEL_CYC_GET_EXINF(cyccb_ro);
	cyctim = _KERNEL_CYC_GET_CYCTIM(cyccb_ro);

	for ( ; ; )
	{
		/* %jp{ ハンドラ呼び出し} */
		cychdr(exinf);

		/* %jp{ ハンドラ内で自身が停止されていたら処理を打ち切る} */
		if ( !_KERNEL_SYS_BSY_TMQ(pk_timobj) )
		{

			break;
			return;	
		}
		
		/* %jp{周期以上にticが進んでいる場合は複数回ハンドラを呼ぶ} */
		if ( ovrtim < cyctim )
		{
			break;
		}
		ovrtim -= cyctim;
	}
	
	/* %jp{次の時刻を設定} */
	_KERNEL_TIMOBJ_SET_LEFTTIM(pk_timobj, cyctim - ovrtim);
}


/* end of file */

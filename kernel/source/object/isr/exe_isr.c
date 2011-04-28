/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  exe_int.c
 * @brief %jp{割込みの処理}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/isrobj.h"


#if _KERNEL_SPT_ISR

/* %jp{割込みの処理} */
void _kernel_exe_isr(INTNO intno)
{
	_KERNEL_T_ISRCB_RO_PTR isrcb_ro;
	_KERNEL_T_ISRCB_PTR    isrcb;
	_KERNEL_T_ISRHDL       isrhdl;
	
	isrhdl = _KERNEL_INT_GET_HEAD(intno);

	/* %jp{ISRのフック} */
#if _KERNEL_SPT_HOK_ISRSTA
	_kernel_isr_sta(intno);
#endif
	
	while ( isrhdl != _KERNEL_ISRHDL_NULL )
	{
		isrcb    = _KERNEL_ISR_ISRHDL2ISRCB(isrhdl);
		isrcb_ro = _KERNEL_ISR_ISRHDL2ISRCBRO(isrhdl);
		
#if _KERNEL_PROCATR_SPT_MULTINT
		_KERNEL_ENA_INT();			/* %jp{多重割込み許可} */
#endif
		_KERNEL_ISR_GET_ISR(isrcb_ro)(_KERNEL_ISR_GET_EXINF(isrcb_ro));
		
#if _KERNEL_PROCATR_SPT_MULTINT
		_KERNEL_DIS_INT();			/* %jp{割込み禁止} */
#endif
		
		isrhdl = _KERNEL_ISR_GET_NEXT(isrcb);
	}
	
	/* %jp{ISRのフック} */
#if _KERNEL_SPT_HOK_ISREND
	_kernel_isr_end(intno);
#endif
}

#endif


/* end of file */

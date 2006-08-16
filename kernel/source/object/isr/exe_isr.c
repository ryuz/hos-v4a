/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  exe_int.c
 * @brief %jp{割込みの処理}
 *
 * @version $Id: exe_isr.c,v 1.1 2006-08-16 16:27:03 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/isrobj.h"


#if _KERNEL_SPT_ISR

/* %jp{割り込みの処理} */
void _kernel_exe_isr(INTNO intno)
{
	_KERNEL_T_ISRHDL isrhdl;
	
	isrhdl = _KERNEL_INT_GET_HEAD(intno);
	while ( isrhdl != NULL )
	{
		_KERNEL_ISR_GET_ISR(isrhdl)(_KERNEL_ISR_GET_EXINF(isrhdl));
		
		isrhdl = _KERNEL_ISR_GET_NEXT(isrhdl);
	}
	
	_kernel_dis_int();
}

#endif


/* end of file */

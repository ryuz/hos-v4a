/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  acre_isr.c
 * @brief %jp{割込みサービスルーチンの生成}%en{Create Interrupt Service Routine}
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/isrobj.h"



/** %jp{割込みサービスルーチンの生成}%en{Create Interrupt Service Routine}
 * @param  pk_cisr	%jp{割込みサービスルーチン生成情報}%en{}
 * @return Error code or task ID
 */
ER_ID acre_isr(const T_CISR *pk_cisr)
{
	ID    isrid;
	ER_ID erid;
	
	_KERNEL_ENTER_SVC();		/* %jp{サービスコールに入る}%en{enter service-call} */
	
	/* %jp{空きID探索} */
	for ( isrid = _KERNEL_ISR_TMAX_ID; isrid >= _KERNEL_ISR_TMIN_ID; isrid-- )
	{
		if ( !_KERNEL_ISR_CHECK_EXS(isrid) )
		{
			break;
		}
	}
	if ( isrid < _KERNEL_ISR_TMIN_ID )
	{
		_KERNEL_LEAVE_SVC();		/* %jp{サービスコールから出る}%en{leave service-call} */
		return E_NOID;				/* %jp{ID番号不足} */
	}
	
	/* %jp{割込みサービスルーチンの生成}%en{Create Interrupt Service Routine} */
	erid = (ER_ID)_kernel_cre_isr(isrid, pk_cisr);
	if ( erid == E_OK )
	{
		erid = (ER_ID)isrid;
	}

	_KERNEL_LEAVE_SVC();		/* %jp{サービスコールから出る}%en{leave service-call} */
	
	return erid;
}



/* end of file */

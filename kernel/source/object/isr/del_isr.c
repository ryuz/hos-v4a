/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  del_isr.c
 * @brief %jp{割込みサービスルーチンの削除}%en{Delete Interrupt Service Routine}
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/isrobj.h"



/** %jp{割込みサービスルーチンの削除}%en{Delete Interrupt Service Routine}
 * @param  isrid 
 * @return Error code or task ID
 */
ER del_isr(ID isrid)
{
	_KERNEL_T_ISRCB_PTR		isrcb;

	/* %jp{IDチェック}%en{check ID} */
#if _KERNEL_SPT_DEL_ISR_E_ID
	if ( !_KERNEL_ISR_CHECK_ISRID(isrid) )
	{
		return E_ID;	/* %jp{不正ID番号}%en{Invalid ID number} */
	}
#endif
	
	_KERNEL_ENTER_SVC();		/* %jp{サービスコールに入る}%en{enter service-call} */
	
	/* %jp{存在チェック}%en{check object} */
#if _KERNEL_SPT_DEL_ISR_E_NOEXS
	if ( !_KERNEL_ISR_CHECK_EXS(isrid) )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
		return E_NOEXS;
	}
#endif
	
	isrcb = _KERNEL_ISR_ID2ISRCB(isrid);

#if _KERNEL_ISRCB_ALGORITHM == _KERNEL_ISRCB_ALG_BLKARRAY
	{
		_KERNEL_T_ISRCB_RO	*isrcb_ro;
		
		isrcb_ro = (_KERNEL_T_ISRCB_RO *)_KERNEL_ISR_GET_ISRCB_RO(isrid, isrcb);
		
		_KERNEL_ISR_SET_ISR(isrcb_ro, NULL);
	}
#else
	{
		_KERNEL_SYS_FRE_HEP(isrcb);
		_KERNEL_ISR_ID2ISRCB(isrid) = NULL;
	}
#endif

	_KERNEL_LEAVE_SVC();		/* %jp{サービスコールから出る}%en{leave service-call} */
	
	return E_OK;
}



/* end of file */

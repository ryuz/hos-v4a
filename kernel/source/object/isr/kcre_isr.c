/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  acre_sem.c
 * @brief %en{Activate Task}%jp{タスクの起動}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/isrobj.h"



/** %jp{セマフォの生成}%en{Create Semaphore}
 * @param  pk_ctsk	%jp{セマフォ生成情報}%en{}
 * @return Error code or task ID
 */
ER _kernel_cre_isr(ID isrid, const T_CISR *pk_cisr)
{
	_KERNEL_T_ISRHDL isrhdl;

	{
		VP mem;

		mem = _KERNEL_SYS_ALC_MEM(sizeof(_KERNEL_T_ISRCB));
		if ( mem == NULL )
		{
			return E_NOMEM;
		}

		_KERNEL_ISR_ID2ISRCB(isrid) = (_KERNEL_T_ISRCB *)mem;
	}

	isrhdl = _KERNEL_ISR_ID2ISRHDL(isrid);
	
	/* %jp{メンバの設定} */
	_KERNEL_ISR_SET_EXINF(isrhdl, pk_cisr->exinf);
	_KERNEL_ISR_SET_ISR(isrhdl, pk_cisr->isr);
	
	/* %jp{割り込みリストの先頭に繋ぐ} */
	_KERNEL_ISR_SET_NEXT(isrhdl, _KERNEL_INT_GET_HEAD(pk_cisr->intno));
	_KERNEL_INT_SET_HEAD(pk_cisr->intno, isrhdl);
	
	return E_OK;
}



/* end of file */

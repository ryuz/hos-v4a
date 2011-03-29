/**
 *  Hyper Operating System V4 Advance
 *
 * @file  dis_int.c
 * @brief %jp{ARMv7-M}%en{ARMv7-M}
 *
 * Copyright (C) 1998-2011 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/inhobj.h"


/* 割込みのクリア */
ER vclr_int(INTNO intno)
{
	if ( intno < _KERNEL_PROCATR_TMIN_INHNO || intno > _KERNEL_PROCATR_TMAX_INHNO )
	{
		return E_PAR;
	}

	*(_KERNEL_REG_INT_CLRPEND_BASE + (intno >> 2)) = (1 << (intno & 3));

	return E_OK;
}



/* end of file */

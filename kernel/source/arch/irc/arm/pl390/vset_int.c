/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  ena_int.c
 * @brief %jp{ARM GIC PL390}%en{ARM GIC PL390}
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"


/* %jp{割込みのセット} */
ER vset_int(INTNO intno)
{
	if ( intno < _KERNEL_INT_TMIN_INTNO || intno > _KERNEL_INT_TMAX_INTNO ) {
		return E_PAR;
	}

	*_KERNEL_IRC_ICDISPR(intno >> 5) = (1 << (intno & 0x1f));

	return E_OK;
}


/* end of file */

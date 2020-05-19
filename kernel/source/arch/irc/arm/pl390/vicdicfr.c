/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  vena_icd.c
 * @brief %jp{ARM GIC PL390}%en{ARM GIC PL390}
 * 
 * Copyright (C) 1998-2020 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"


/* change ICDICFR(target CPU) */
ER vchg_icdicfr(INTNO intno, UB config)
{
	int n     = ((int)intno >> 4);
	int shift = ((int)intno & 0x0f) * 2;

	UW  val = *_KERNEL_IRC_ICDICFR(n);
	val &= ~((UW)0x03 << shift);
	val |= ((UW)(config & 0x03) << shift);
	*_KERNEL_IRC_ICDICFR(n) = val;

	return E_OK;
}

/* end of file */

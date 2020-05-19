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


/* change ICDIPTR(target CPU) */
ER vchg_icdiptr(INTNO intno, UB targetcpu)
{
	*_KERNEL_IRC_ICDIPTR(intno) = targetcpu;
	return E_OK;
}

/* end of file */

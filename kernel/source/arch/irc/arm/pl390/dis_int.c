/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  dis_int.c
 * @brief %jp{ARM GIC PL390}%en{ARM GIC PL390}
 *
 * Copyright (C) 1998-2020 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"


/* 割込みの禁止 */
ER dis_int(INTNO intno)
{
	*_KERNEL_IRC_ICDICER(intno >> 5) = (1 << (intno & 0x1f));
	return E_OK;
}



/* end of file */

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


/**< %jp{割込みレベル変更(独自サービスコール)} */
ER vchg_ilv(INTNO intno, INT ilv)
{
	*_KERNEL_IRC_ICDIPR(intno) = ilv;
	return E_OK;
}


/* end of file */

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


/**< %jp{割込みレベル参照(独自サービスコール)} */
ER vget_ilv(INTNO intno, INT *p_ilv)
{
	*p_ilv = *_KERNEL_IRC_ICDIPR(intno);
	return E_OK;
}


/* end of file */

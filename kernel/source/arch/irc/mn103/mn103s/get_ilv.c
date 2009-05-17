/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  intc.h
 * @brief %jp{MN103S用割込みコントローラ操作}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"


/* 割込みレベルの取得 */
ER vget_ilv(INTNO intno, INT *p_ilv)
{
	*p_ilv = (*_KERNEL_MN103S_INTC_GICR(intno) >> 12) & 0x7;

	return E_OK;
}


/* end of file */

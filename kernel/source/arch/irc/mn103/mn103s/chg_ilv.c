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


/* 割込みレベルの設定 */
ER vchg_ilv(INTNO intno, INT ilv)
{
	*_KERNEL_MN103S_INTC_GICR(intno) = ((ilv & 0x7) << 12);
	
	return E_OK;
}


/* end of file */

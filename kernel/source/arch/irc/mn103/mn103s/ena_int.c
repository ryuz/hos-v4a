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


/* 割込みの許可 */
ER ena_int(INTNO intno)
{
	int mask;
	UH  gicr;
	
	gicr = *_KERNEL_MN103S_INTC_GICR(intno);
	mask = (0x0100 << (intno & 0x03));
	
	*_KERNEL_MN103S_INTC_GICR(intno) = ((mask | gicr) & 0xff00);
	
	return E_OK;
}


/* end of file */

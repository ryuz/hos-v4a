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


/* 割込み要因のクリア */
ER vclr_int(INTNO intno)
{
	int			mask;
	volatile UH	dummy;
	
	mask  = (0x0001 << (intno & 0x03));
	
	*_KERNEL_MN103S_INTC_GICR(intno) &= ~(mask << 4);
	dummy = *_KERNEL_MN103S_INTC_GICR(intno);
	
	return E_OK;
}


/* end of file */

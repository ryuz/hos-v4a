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


/* 割込みコントローラの初期化 */
void _kernel_ini_irc(void)
{
	int intno;
	
	for ( intno = _KERNEL_INT_TMIN_INTNO; intno <= _KERNEL_INT_TMAX_INTNO; intno += 4 )
	{
		*_KERNEL_MN103S_INTC_GICR(intno) = 0x6000;
	}
}


/* end of file */

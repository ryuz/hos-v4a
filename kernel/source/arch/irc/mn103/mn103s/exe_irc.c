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


/* IRQ割込み処理 */
void _kernel_exe_irc(void)
{
	INTNO intno;
	UH    gicr;
	int   i;
	
	/* %jp{割込み番号取得} */
	intno = *_KERNEL_MN103S_INTC_IAGR;
	gicr  = *_KERNEL_MN103S_INTC_GICR(intno);
	for ( i = 0; i < 4; i++ )
	{
		if ( gicr & 1 )
		{
			/* 割込みサービスルーチン呼び出し */
			_kernel_exe_isr(intno);
		}
		intno++;
		gicr >>= 1;
	}
}


/* end of file */

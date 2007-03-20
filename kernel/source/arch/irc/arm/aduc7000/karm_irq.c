/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  intc.h
 * @brief %jp{ADuC7000シリーズ用割込みコントローラ操作}%en{ADuC7000 series}
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"
#include "aduc7000.h"


/** %jp{IRQ割り込み処理開始} */
void _kernel_arm_irq(void)
{
	INTNO intno;
	UW    irqsta;
	
	irqsta = IRQSTA;
	
	/* 割り込み番号取得 */
	for ( intno = 0; intno <= 23; intno++ )
	{
		if ( irqsta & 1 )
		{
			/* 割込みサービスルーチン呼び出し */
			_kernel_exe_isr(intno);
		}
		
		irqsta >>= 1;
	}
}


/* end of file */

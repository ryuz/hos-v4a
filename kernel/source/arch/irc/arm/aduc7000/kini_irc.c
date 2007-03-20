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


/** %jp{割込みコントローラの初期化} */
void _kernel_ini_irc(void)
{
	IRQCLR = 0x00ffffff;
	FIQCLR = 0x00ffffff;
	
	_kernel_inh_tbl[_KERNEL_ARM_INHNO_IRQ].inthdr = (FP)_kernel_arm_irq;
	_kernel_inh_tbl[_KERNEL_ARM_INHNO_FIQ].inthdr = (FP)_kernel_arm_fiq;
}

void _kernel_exe_irc(INHNO inhno)
{
	switch ( inhno )
	{
	case _KERNEL_ARM_INHNO_IRQ:
		_kernel_arm_irq();
		break;

	case _KERNEL_ARM_INHNO_FIQ:
		_kernel_arm_fiq();
		break;
	}
}



/* end of file */

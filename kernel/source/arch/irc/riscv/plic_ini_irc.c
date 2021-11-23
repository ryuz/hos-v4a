/**
 *  Hyper Operating System V4 Advance
 *
 * @file  plic_ini_irc.c
 * @brief RISC-V Platform-Level Interrupt Controller Initialization
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"


/** %jp{割込みコントローラの初期化} */
void _kernel_riscv_irc_plic_ini_irc(void)
{
	int  i;

	for( i = _KERNEL_IRCATR_PLIC_TMIN_INTNO; _KERNEL_IRCATR_PLIC_TMAX_INTNO > i; ++i)
	{

		/*  %jp{ISR未登録な割込みをマスクし, ISR登録済み割込みのマスクを解放}  */
		if ( _KERNEL_INT_GET_HEAD(i) == _KERNEL_ISRHDL_NULL )
		{

			/*  %jp{割込みをマスク}  */
			*_KERNEL_RISCV_IRC_PLIC_MENABLE_REG(_kernel_riscv_get_hartid(),
			    _KERNEL_RISCV_IRC_PLIC_INTNO2IRQ(i))
				&= ~( _KERNEL_RISCV_IRC_PLIC_IRQBITMASK(
					    _KERNEL_RISCV_IRC_PLIC_INTNO2IRQ(i) ) );
		}
		else
		{

			/*  %jp{割込みのマスクを解放}  */
			*_KERNEL_RISCV_IRC_PLIC_MENABLE_REG(_kernel_riscv_get_hartid(),
			    _KERNEL_RISCV_IRC_PLIC_INTNO2IRQ(i))
				|= _KERNEL_RISCV_IRC_PLIC_IRQBITMASK(
					_KERNEL_RISCV_IRC_PLIC_INTNO2IRQ(i) );
		}

	}

	/* %jp{優先度を0に設定} */
	*_KERNEL_RISCV_IRC_PLIC_MPRIO_REG(_kernel_riscv_get_hartid()) = 0;
}

/* end of file */

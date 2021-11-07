/**
 *  Hyper Operating System V4 Advance
 *
 * @file plic_ena_int.c
 * @brief RISC-V Platform-Level Interrupt Controller Enable Interrupt
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"


/* 割込みの許可 */
ER _kernel_riscv_irc_plic_ena_int(INTNO intno)
{

	if ( intno < _KERNEL_IRCATR_PLIC_TMIN_INTNO ||
	    intno > _KERNEL_IRCATR_PLIC_TMAX_INTNO )
	{
		return E_PAR;
	}

	*_KERNEL_RISCV_IRC_PLIC_MENABLE_REG(_kernel_riscv_get_hartid(),
	    _KERNEL_RISCV_IRC_PLIC_INTNO2IRQ(intno))
		|= _KERNEL_RISCV_IRC_PLIC_IRQBITMASK(
			_KERNEL_RISCV_IRC_PLIC_INTNO2IRQ(intno));
	return E_OK;
}


/* end of file */

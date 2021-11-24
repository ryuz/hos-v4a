/**
 *  Hyper Operating System V4 Advance
 *
 * @file plic_dis_int.c
 * @brief RISC-V Platform-Level Interrupt Controller Disable Interrupt
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"


/* %jp{割込みの禁止} */
ER _kernel_riscv_irc_plic_dis_int(INTNO intno)
{

	if ( intno < _KERNEL_IRCATR_PLIC_TMIN_INTNO ||
	    intno > _KERNEL_IRCATR_PLIC_TMAX_INTNO )
	{
		return E_PAR;  /* %jp{有効な割込み番号の範囲外} */
	}


	/*
	 * %jp{割込みマスクを操作し, 処理対象IRQからの割込みをマスクする}
	 */
	*_KERNEL_RISCV_IRC_PLIC_MENABLE_REG(_kernel_riscv_get_hartid(),
		_KERNEL_RISCV_IRC_PLIC_INTNO2IRQ(intno))
		&= ~_KERNEL_RISCV_IRC_PLIC_IRQBITMASK(
			_KERNEL_RISCV_IRC_PLIC_INTNO2IRQ(intno));

	return E_OK;
}


/* end of file */

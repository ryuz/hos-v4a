/**
 *  Hyper Operating System V4 Advance
 *
 * @file clint_ena_int.c
 * @brief RISC-V Core-local Interruptor Enable Interrupt
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"


/* 割込みの許可 */
ER _kernel_riscv_irc_clint_ena_int(INTNO intno)
{
	if ( intno < _KERNEL_IRCATR_CLINT_TMIN_INTNO ||
	    intno > _KERNEL_IRCATR_CLINT_TMAX_INTNO )
	{
		return E_PAR;
	}

	if ( intno == 0 )
		_kernel_riscv_irc_write_mie(_kernel_riscv_irc_read_mie() |
		    ( (UD)1 << _KERNEL_RISCV_IRC_CLINT_MSIP_BIT ));
	else if ( intno == 1 )
		_kernel_riscv_irc_write_mie(_kernel_riscv_irc_read_mie() |
		    ( (UD)1 << _KERNEL_RISCV_IRC_CLINT_MTIP_BIT ));

	return E_OK;
}


/* end of file */

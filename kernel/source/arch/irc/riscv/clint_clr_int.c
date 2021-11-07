/**
 *  Hyper Operating System V4 Advance
 *
 * @file clint_clr_int.c
 * @brief RISC-V Core-local Interruptor Clear Interrupt Request
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"


/* 割込みの許可 */
ER _kernel_riscv_irc_clint_clr_int(INTNO intno)
{

	if ( intno < _KERNEL_IRCATR_CLINT_TMIN_INTNO ||
	    intno > _KERNEL_IRCATR_CLINT_TMAX_INTNO )
	{
		return E_PAR;
	}

	_kernel_riscv_irc_write_mip(_kernel_riscv_irc_read_mip() & ~( (UD)1 << intno ));

	return E_OK;
}


/* end of file */

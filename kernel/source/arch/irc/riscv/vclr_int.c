/**
 *  Hyper Operating System V4 Advance
 *
 * @file  vclr_int.c
 * @brief RISC-V Interrupt Request Controller Clear Interrupt Request
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"


/* %jp{割込みのクリア} */
ER vclr_int(INTNO intno)
{
	if ( intno < _KERNEL_IRCATR_PLIC_TMIN_INTNO )
		return _kernel_riscv_irc_clint_clr_int(intno);
	else if ( intno <= _KERNEL_IRCATR_PLIC_TMAX_INTNO )
		return _kernel_riscv_irc_plic_clr_int(intno);

	return E_PAR;
}


/* end of file */

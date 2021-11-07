/**
 *  Hyper Operating System V4 Advance
 *
 * @file  ena_int.c
 * @brief RISC-V Interrupt Request Controller
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"


/* %jp{割込みの許可} */
ER ena_int(INTNO intno)
{
	if ( intno < _KERNEL_IRCATR_PLIC_TMIN_INTNO )
		return _kernel_riscv_irc_clint_ena_int(intno);
	else
		return _kernel_riscv_irc_plic_ena_int(intno);

	return E_PAR;
}


/* end of file */

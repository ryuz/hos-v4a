/**
 *  Hyper Operating System V4 Advance
 *
 * @file plic_clr_int.c
 * @brief RISC-V Platform-Level Interrupt Controller Clear Interrupt Request
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"


/* 割込み受付通知 */
ER _kernel_riscv_irc_plic_clr_int(INTNO intno)
{

	if ( intno < _KERNEL_IRCATR_PLIC_TMIN_INTNO ||
	    intno > _KERNEL_IRCATR_PLIC_TMAX_INTNO )
	{
		return E_PAR;
	}

	/* %jp{処理した割込み番号を通知} */
	*_KERNEL_RISCV_IRC_PLIC_MCLAIM_REG(_kernel_riscv_get_hartid())
		= _KERNEL_RISCV_IRC_PLIC_INTNO2IRQ(intno);

	return E_OK;
}


/* end of file */

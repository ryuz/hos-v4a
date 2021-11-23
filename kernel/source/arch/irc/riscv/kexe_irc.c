/**
 *  Hyper Operating System V4 Advance
 *
 * @file  kexe_irc.c
 * @brief RISC-V Interrupt Request Controller
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"


/** %jp{割込みコントローラの割込み処理} */
void _kernel_exe_irc(INHNO inhno)
{

	if ( inhno <= _KERNEL_IRCATR_CLINT_TMAX_INTNO )
		_kernel_riscv_irc_clint_exe_irc(inhno);  /* %jp{CLINT割込み処理} */
	else
		_kernel_riscv_irc_plic_exe_irc(inhno);   /* %jp{PLIC割込み処理} */
}


/* end of file */

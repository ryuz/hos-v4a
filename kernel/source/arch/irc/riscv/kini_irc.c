/**
 *  Hyper Operating System V4 Advance
 *
 * @file  kini_irc.c
 * @brief RISC-V Interrupt Request Controller
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"


/** %jp{割込みコントローラの初期化} */
void _kernel_ini_irc(void)
{
	/* %jp{Platform-Level Interrupt Controllerの初期化} */
	_kernel_riscv_irc_plic_ini_irc();
	/* %jp{Core-local Interruptorの初期化} */
	_kernel_riscv_irc_clint_ini_irc();
}


/* end of file */

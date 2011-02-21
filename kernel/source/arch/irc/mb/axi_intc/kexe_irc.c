/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  kexe_int.c
 * @brief XILINX AXI INTC
 *
 * Copyright (C) 1998-2011 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"


/** %jp{割込みコントローラの割込み処理} */
void _kernel_exe_irc(INHNO inhno)
{
	/* %jp{割込みサービスルーチン呼び出し} */
	_kernel_exe_isr(*_KERNEL_IRC_IVR);
}


/* end of file */

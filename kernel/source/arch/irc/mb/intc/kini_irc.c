/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  kini_int.c
 * @brief XILINX AXI INTC
 *
 * Copyright (C) 1998-2011 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"


/** %jp{割込みコントローラの初期化} */
void _kernel_ini_irc(void)
{
	*_KERNEL_IRC_CIE = 0xffffffff;
	*_KERNEL_IRC_MER = 0x00000003;
}


/* end of file */

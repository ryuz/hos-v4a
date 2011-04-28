/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  vclr_int.c
 * @brief XILINX AXI INTC
 *
 * Copyright (C) 1998-2011 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"


/* 割込みのクリア */
ER vclr_int(INTNO intno)
{
	*_KERNEL_IRC_IAR = (1 << intno);
	
	return E_OK;
}


/* end of file */

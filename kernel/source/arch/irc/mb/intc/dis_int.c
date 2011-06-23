/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  dis_int.c
 * @brief XILINX AXI INTC
 *
 * Copyright (C) 1998-2011 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"


/* 割込みの禁止 */
ER dis_int(INTNO intno)
{
	*_KERNEL_IRC_CIE = (1 << intno);
	
	return E_OK;
}



/* end of file */

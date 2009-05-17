/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  dis_int.c
 * @brief %jp{PC/AT互換機}%en{PC/AT}
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"


/* 割込みの禁止 */
ER dis_int(INTNO intno)
{
	if ( intno < 0 || intno > 15 )
	{
		return E_PAR;
	}
	
	if ( intno >= 0 && intno < 8 )
	{
		_kernel_outpb(_KERNEL_IRC_PIC1_OCW1, (_kernel_inpb(_KERNEL_IRC_PIC1_IMR) | (1 << intno)));
	}
	else
	{
		_kernel_outpb(_KERNEL_IRC_PIC2_OCW1, (_kernel_inpb(_KERNEL_IRC_PIC2_IMR) | (1 << (intno - 8))));
	}
	
	return E_OK;
}



/* end of file */

/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  dis_int.c
 * @brief %jp{Freescale MX1用}%en{Freescale MX1}
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"


/* 割込みの禁止 */
ER dis_int(INTNO intno)
{
	if ( intno < _KERNEL_IRCATR_TMIN_INTNO || intno > _KERNEL_IRCATR_TMAX_INTNO )
	{
		return E_PAR;
	}

	*_KERNEL_IRC_INTDISNUM = intno;
	
	return E_OK;
}


/* end of file */

/** 
 *  Hyper Operating System V4 Advance
 *
 * @file ena_int.c
 * @brief %jp{Jelly FPGAシステム}%en{Jelly FPGA}
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"


/* 割込みの許可 */
ER ena_int(INTNO intno)
{
	if ( intno < _KERNEL_IRCATR_TMIN_INTNO || intno > *_KERNEL_IRC_FACTOR_ID_MAX )
	{
		return E_PAR;
	}
	
	*_KERNEL_IRC_ENABLE = 0;
	
	*_KERNEL_IRC_FACTOR_ENABLE(intno) = 1;

	*_KERNEL_IRC_ENABLE = 1;
	
	return E_OK;
}


/* end of file */

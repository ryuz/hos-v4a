/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  vclr_int.h
 * @brief %jp{Jelly FPGAシステム}%en{Jelly FPGA}
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"


/* %jp{割込みのクリア} */
ER vclr_int(INTNO intno)
{
	if ( intno < _KERNEL_IRCATR_TMIN_INTNO || intno > *_KERNEL_IRC_FACTOR_ID_MAX )
	{
		return E_PAR;
	}
	
	*_KERNEL_IRC_ENABLE = 0;

	*_KERNEL_IRC_FACTOR_PENDING(intno) = 0;

	*_KERNEL_IRC_ENABLE = 1;

	return E_OK;
}


/* end of file */

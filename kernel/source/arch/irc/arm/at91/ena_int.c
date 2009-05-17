/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  ena_int.c
 * @brief %jp{ATMEL AT91シリーズ}%en{ATMEL AT91 series}
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"


/* 割込みの許可 */
ER ena_int(INTNO intno)
{
	if ( intno < _KERNEL_IRCATR_TMIN_INTNO || intno > _KERNEL_IRCATR_TMAX_INTNO )
	{
		return E_PAR;
	}

	*_KERNEL_IRC_AIC_IECR = (1 << intno);

	return E_OK;
}


/* end of file */

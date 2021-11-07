/**
 *  Hyper Operating System V4 Advance
 *
 * @file  plic_chg_imsk.c
 * @brief %jp{割込みマスクの変更(実装依存サービスコール)}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"


/* %jp{割込みマスクの変更(実装依存サービスコール)} */
ER _kernel_riscv_irc_plic_chg_imsk(INT imsk)
{
	if ( ( imsk < _KERNEL_IRCATR_PLIC_TMIN_IMSK ) ||
	    ( imsk > _KERNEL_IRCATR_PLIC_TMAX_IMSK ) )
	{
		return E_PAR;
	}

	*_KERNEL_RISCV_IRC_PLIC_MPRIO_REG(_kernel_riscv_get_hartid()) = imsk;

	return E_OK;
}


/* end of file */

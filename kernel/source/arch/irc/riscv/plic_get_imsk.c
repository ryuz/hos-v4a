/**
 *  Hyper Operating System V4 Advance
 *
 * @file  plic_get_imsk.c
 * @brief %jp{割込みマスクの参照(実装依存サービスコール)}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"


/* %jp{割込みマスクの参照(実装依存サービスコール)} */
ER _kernel_riscv_irc_plic_get_imsk(INT *p_imsk)
{
	*p_imsk = (INT)*_KERNEL_RISCV_IRC_PLIC_MPRIO_REG(_kernel_riscv_get_hartid());

	return E_OK;
}


/* end of file */

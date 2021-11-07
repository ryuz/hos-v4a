/**
 *  Hyper Operating System V4 Advance
 *
 * @file  clint-ircatr.h
 * @brief RISC-V Interrupt Request Controller attributes
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__arch__irc__riscv__ircatr_h__
#define _KERNEL__arch__irc__riscv__ircatr_h__

#include "clint_ircatr.h"
#include "plic_ircatr.h"

#define _KERNEL_IRCATR_INC_PATH				"riscv"

#define _KERNEL_IRCATR_IRC				TRUE	/**< %jp{IRCの有無} */
#define _KERNEL_IRCATR_REG_BASE				FALSE	/**< %jp{IRCレジスタベースアドレスの有無} */

/**< %jp{割込み番号の最小値} */
#define _KERNEL_IRCATR_TMIN_INTNO			_KERNEL_IRCATR_CLINT_TMIN_INTNO
/**< %jp{割込み番号の最大値} */
#define _KERNEL_IRCATR_TMAX_INTNO			(_KERNEL_IRCATR_CLINT_TMAX_INTNO + _KERNEL_IRCATR_PLIC_TMAX_INTNO)

#endif	/* _KERNEL__arch__irc__riscv__ircatr_h__ */



/* end of file */

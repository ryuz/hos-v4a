/**
 *  Hyper Operating System V4 Advance
 *
 * @file  plic-ircatr.h
 * @brief RISC-V Platform-Level Interrupt Controller attributes
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__arch__irc__riscv__plic__plic_ircatr_h__
#define _KERNEL__arch__irc__riscv__plic__plic_ircatr_h__

#define _KERNEL_IRCATR_PLIC_INC_PATH		"riscv/plic"

#define _KERNEL_IRCATR_PLIC_IRC			TRUE  /**< %jp{IRCの有無} */
#define _KERNEL_IRCATR_PLIC_REG_BASE		FALSE  /**< %jp{IRCレジスタベースアドレスの有無} */

#define _KERNEL_IRCATR_PLIC_TMIN_INTNO		2 /**< %jp{割込み番号の最小値} */
#define _KERNEL_IRCATR_PLIC_TMAX_INTNO	     1024 /**< %jp{割込み番号の最大値} */

#define _KERNEL_IRCATR_PLIC_TMIN_PRIO	       -7 /**< %jp{QEmuでの割込み優先度の最小値} */
#define _KERNEL_IRCATR_PLIC_TMAX_PRIO	       -1 /**< %jp{QEmuでの割込み優先度の最大値} */

/**< %jp{割込みマスクの最小値} */
#define _KERNEL_IRCATR_PLIC_TMIN_IMSK		0
/**< %jp{割込みマスクの最大値} */
#define _KERNEL_IRCATR_PLIC_TMAX_IMSK		7

#endif	/* _KERNEL__arch__irc__riscv__clint__ircatr_h__ */



/* end of file */

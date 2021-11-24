/**
 *  Hyper Operating System V4 Advance
 *
 * @file  clint-ircatr.h
 * @brief RISC-V Core-local Interruptor attributes
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__arch__irc__riscv__clint__clint_ircatr_h__
#define _KERNEL__arch__irc__riscv__clint__clint_ircatr_h__

#define _KERNEL_IRCATR_CLINT_INC_PATH			"riscv/clint"

#define _KERNEL_IRCATR_CLINT_IRC			FALSE  /**< %jp{IRCの有無} */
#define _KERNEL_IRCATR_CLINT_REG_BASE			FALSE /**< %jp{IRCレジスタベースアドレスの有無} */

#define _KERNEL_IRCATR_CLINT_TMIN_INTNO			0 /**< %jp{割込み番号の最小値} */
#define _KERNEL_IRCATR_CLINT_TMAX_INTNO			1 /**< %jp{割込み番号の最大値} */

/* %jp{RISC-V固有定義} */
#define _KERNEL_IRCATR_CLINT_MSOFT_INTNO               (0) /**< %jp{ソフトウエア割り込み} */
#define _KERNEL_IRCATR_CLINT_MTIMER_INTNO              (1) /**< %jp{タイマ}  */
#define _KERNEL_IRCATR_CLINT_MEXT_INTNO                (2) /**< %jp{外部割り込み}  */
#endif	/* _KERNEL__arch__irc__riscv__clint__clint_ircatr_h__ */



/* end of file */

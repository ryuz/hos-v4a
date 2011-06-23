/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  ircatr.h
 * @brief XILINX XPS/AXI INTC
 *
 * Copyright (C) 1998-2011 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__arch__irc__xilinx_intc__ircatr_h__
#define _KERNEL__arch__irc__xilinx_intc__ircatr_h__


#define _KERNEL_IRCATR_INC_PATH				"mb/intc"

#define _KERNEL_IRCATR_IRC					TRUE		/**< %jp{IRCの有無} */
#define _KERNEL_IRCATR_REG_BASE				TRUE		/**< %jp{IRCレジスタベースアドレスの有無} */
#define _KERNEL_IRCATR_REG_BASE_DEF			0x41200000	/**< %jp{デフォルトのIRCレジスタベースアドレス} */

#define _KERNEL_IRCATR_TMIN_INTNO			0			/**< %jp{割込み番号の最小値} */
#define _KERNEL_IRCATR_TMAX_INTNO			31			/**< %jp{割込み番号の最大値} */


#endif	/* _KERNEL__arch__irc__xilinx_intc__ircatr_h__ */



/* end of file */

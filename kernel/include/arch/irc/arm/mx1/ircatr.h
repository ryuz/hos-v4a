/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  ircatr.h
 * @brief %jp{Freescale MX1 ファミリ用割込みコントローラ属性}%en{Freescale MX1 family}
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__arch__irc__mx1__ircatr_h__
#define _KERNEL__arch__irc__mx1__ircatr_h__


#define _KERNEL_IRCATR_INC_PATH				"arm/mx1"

#define _KERNEL_IRCATR_IRC					TRUE		/**< %jp{IRCの有無} */
#define _KERNEL_IRCATR_REG_BASE				FALSE		/**< %jp{IRCレジスタベースアドレスの有無} */

#define _KERNEL_IRCATR_TMIN_INTNO			0			/**< %jp{割込み番号の最小値} */
#define _KERNEL_IRCATR_TMAX_INTNO			63			/**< %jp{割込み番号の最大値} */


#endif	/* _KERNEL__arch__irc__mx1__ircatr_h__ */



/* end of file */

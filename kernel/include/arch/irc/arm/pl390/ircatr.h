/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  ircatr.h
 * @brief %jp{ARM PL390割込みコントローラ操作}%en{ARM PL390}
 *
 * Copyright (C) 1998-2020 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__arch__irc__arm_pl390__ircatr_h__
#define _KERNEL__arch__irc__arm_pl390__ircatr_h__


#define _KERNEL_IRCATR_INC_PATH				"arm/pl390"

#define _KERNEL_IRCATR_IRC					TRUE		/**< %jp{IRCの有無} */

/* ICC */ 
#define _KERNEL_IRCATR_REG_BASE				TRUE		/**< %jp{IRCレジスタベースアドレスの有無} */
#define _KERNEL_IRCATR_REG_BASE_DEF         0xf9001000  /**< %jp{デフォルトのIRCレジスタベースアドレス(ZynqMP)} */

/* ICD */ 
#define _KERNEL_IRCATR_REG2_BASE			TRUE		/**< %jp{IRCレジスタベース2アドレスの有無} */
#define _KERNEL_IRCATR_REG2_BASE_DEF        0xf9000000  /**< %jp{デフォルトのIRCレジスタベースアドレス(ZynqMP)} */

#define _KERNEL_IRCATR_TMIN_INTNO			0			/**< %jp{割込み番号の最小値} */
#define _KERNEL_IRCATR_TMAX_INTNO			254			/**< %jp{割込み番号の最大値} */


#endif	/* _KERNEL__arch__irc__arm_pl390__ircatr_h__ */



/* end of file */

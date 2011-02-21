/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  ircatr.h
 * @brief %jp{Analog Devices ADuC7000シリーズ用割込みコントローラ操作}%en{Analog Devices ADuC7000 series}
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__arch__irc__aduc7000__ircatr_h__
#define _KERNEL__arch__irc__aduc7000__ircatr_h__

#define _KERNEL_IRCATR_INC_PATH				"arm/aduc7000"

#define _KERNEL_IRCATR_IRC					TRUE		/**< %jp{IRCの有無} */
#define _KERNEL_IRCATR_REG_BASE				FALSE		/**< %jp{IRCレジスタベースアドレスの有無} */

#define _KERNEL_IRCATR_TMIN_INTNO			0			/**< %jp{割込み番号の最小値} */
#define _KERNEL_IRCATR_TMAX_INTNO			31			/**< %jp{割込み番号の最大値} */


#endif	/* _KERNEL__arch__irc__aduc7000__ircatr_h__ */



/* end of file */

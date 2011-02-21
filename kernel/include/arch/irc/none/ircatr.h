/**
 *  Hyper Operating System V4 Advance
 *
 * @file  ircatr.h
 * @brief %jp{割込みコントローラ固有属性定義}%jp{Interrupt controler attribute}
 *
 * Copyright (C) 1998-2011 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__arch__none__ircatr_h__
#define _KERNEL__arch__none__ircatr_h__


#define _KERNEL_IRCATR_INC_PATH				"none"

#define _KERNEL_IRCATR_IRC					FALSE			/**< %jp{IRCの有無} */
#define _KERNEL_IRCATR_REG_BASE				FALSE			/**< %jp{IRCレジスタベースアドレスの有無} */

#define _KERNEL_IRCATR_TMIN_INTNO			0				/**< %jp{割込みハンドラ番号の最小値} */
#define _KERNEL_IRCATR_TMAX_INTNO			0				/**< %jp{割込みハンドラ番号の最大値} */


#endif	/* _KERNEL__arch__none__ircatr_h__ */


/* end of file */

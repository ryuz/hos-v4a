/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  irc.h
 * @brief %jp{Jelly FPGAシステム}%en{Jelly FPGA}
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__arch__irc__jelly__irc_h__
#define _KERNEL__arch__irc__jelly__irc_h__


/* %jp{メモリマップドレジスタ定義} */
#define _KERNEL_IRC_BASE				0xffff8000

#define _KERNEL_IRC_ENABLE				((volatile       UW *)(_KERNEL_IRC_BASE + 0x00))		/* Enable Register */
#define _KERNEL_IRC_MASK				((volatile       UW *)(_KERNEL_IRC_BASE + 0x04))		/* Mask Register */
#define _KERNEL_IRC_REQ_FACTOR_ID		((volatile const UW *)(_KERNEL_IRC_BASE + 0x08))		/*  */
#define _KERNEL_IRC_REQ_PRIORITY		((volatile const UW *)(_KERNEL_IRC_BASE + 0x0c))
#define _KERNEL_IRC_FACTOR_ID_MAX		((volatile const UW *)(_KERNEL_IRC_BASE + 0x10))
#define _KERNEL_IRC_PRIORITY_MAX		((volatile const UW *)(_KERNEL_IRC_BASE + 0x14))
#define _KERNEL_IRC_FACTOR_ENABLE(n)	((volatile       UW *)(_KERNEL_IRC_BASE + 0x20 + ((n) * 0x10)))
#define _KERNEL_IRC_FACTOR_PENDING(n)	((volatile       UW *)(_KERNEL_IRC_BASE + 0x24 + ((n) * 0x10)))
#define _KERNEL_IRC_FACTOR_STATUS(n)	((volatile const UW *)(_KERNEL_IRC_BASE + 0x28 + ((n) * 0x10)))
#define _KERNEL_IRC_FACTOR_PRIORITY(n)	((volatile       UW *)(_KERNEL_IRC_BASE + 0x2c + ((n) * 0x10)))



#ifdef __cplusplus
extern "C" {
#endif

void _kernel_ini_irc(void);			/**< %jp{割込みコントローラの初期化} */
void _kernel_exe_irc(INHNO inhno);	/**< %jp{割込み処理} */

#ifdef __cplusplus
}
#endif


#define _KERNEL_INI_IRC()		_kernel_ini_irc()		/**< %jp{割込みコントローラの初期化} */
#define _KERNEL_EXE_IRC(inhno)	_kernel_exe_irc(inhno)	/**< %jp{割込み処理} */


#endif	/* _KERNEL__arch__irc__jelly__irc_h__ */


/* end of file */

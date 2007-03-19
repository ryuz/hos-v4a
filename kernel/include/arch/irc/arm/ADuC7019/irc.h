/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  irc.h
 * @brief %jp{ADuC7019/20/21/22/24/25/26/27 用割り込みコントローラ操作}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__arch__irc__ADuC7019__irc_h__
#define _KERNEL__arch__irc__ADuC7019__irc_h__


#ifdef __cplusplus
extern "C" {
#endif

void _kernel_ini_irc(void);			/**< %jp{割込みコントローラの初期化} */
void _kernel_exe_irc(INHNO inhno);
void _kernel_arm_irq(void);			/**< %jp{割り込み処理の実施} */
void _kernel_arm_fiq(void);			/**< %jp{割り込み処理の実施} */

#ifdef __cplusplus
}
#endif


#define _KERNEL_INI_IRC()		_kernel_ini_irc()		/**< %jp{割込みコントローラの初期化} */
#define _KERNEL_EXE_IRC(inhno)	_kernel_exe_irc(inhno)	/**< %jp{割込み処理} */


#endif	/* _KERNEL__arch__irc__ADuC7019__irc_h__ */


/* end of file */


/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  irc.h
 * @brief %jp{Philips LPC2000ファミリ用割込みコントローラ操作}%en{Philips LPC2000 family}
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__arch__irc__lpc2000__irc_h__
#define _KERNEL__arch__irc__lpc2000__irc_h__


/* %jp{メモリマップドレジスタ定義} */
#define _KERNEL_IRC_

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


#endif	/* _KERNEL__arch__irc__lpc2000__irc_h__ */


/* end of file */


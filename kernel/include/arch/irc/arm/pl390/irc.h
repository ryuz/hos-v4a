/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  irc.h
 * @brief %jp{Freescale MX1 ファミリ用割込みコントローラ操作}%en{Freescale MX1 family}
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__arch__irc__mx1__irc_h__
#define _KERNEL__arch__irc__mx1__irc_h__


/* %jp{メモリマップドレジスタ定義} */
#define _KERNEL_IRC_ICCICR				((volatile UW *)_kernel_irc_reg_base + 0x00000000)
#define _KERNEL_IRC_ICCPMR				((volatile UW *)_kernel_irc_reg_base + 0x00000004)
#define _KERNEL_IRC_ICCBPR				((volatile UW *)_kernel_irc_reg_base + 0x00000008)
#define _KERNEL_IRC_ICCIAR				((volatile UW *)_kernel_irc_reg_base + 0x0000000C)


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


#endif	/* _KERNEL__arch__irc__mx1__irc_h__ */


/* end of file */


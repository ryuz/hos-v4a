/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  irc.h
 * @brief %jp{Analog Devices ADuC7000シリーズ用割込みコントローラ操作}%en{Analog Devices ADuC7000 series}
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__arch__irc__aduc7000__irc_h__
#define _KERNEL__arch__irc__aduc7000__irc_h__


/* %jp{メモリマップドレジスタ定義} */
#define _KERNEL_IRC_IRQSTA		((volatile UW *)0xffff0000)
#define _KERNEL_IRC_IRQSIG		((volatile UW *)0xffff0004)
#define _KERNEL_IRC_IRQEN		((volatile UW *)0xffff0008)
#define _KERNEL_IRC_IRQCLR		((volatile UW *)0xffff000c)

#define _KERNEL_IRC_FIQSTA		((volatile UW *)0xffff0100)
#define _KERNEL_IRC_FIQSIG		((volatile UW *)0xffff0104)
#define _KERNEL_IRC_FIQEN		((volatile UW *)0xffff0108)
#define _KERNEL_IRC_FIQCLR		((volatile UW *)0xffff010c)


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


#endif	/* _KERNEL__arch__irc__aduc7000__irc_h__ */


/* end of file */


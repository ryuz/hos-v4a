/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  irc.h
 * @brief %jp{PC/AT互換機}%en{PC/AT}
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__arch__irc__pcat__irc_h__
#define _KERNEL__arch__irc__pcat__irc_h__


/* %jp{PIC I/Oポート定義} */
#define _KERNEL_IRC_PIC1_ICW1	0x20
#define _KERNEL_IRC_PIC1_ICW2	0x21
#define _KERNEL_IRC_PIC1_ICW3	0x21
#define _KERNEL_IRC_PIC1_ICW4	0x21
#define _KERNEL_IRC_PIC1_OCW1	0x21
#define _KERNEL_IRC_PIC1_OCW2	0x20
#define _KERNEL_IRC_PIC1_OCW3	0x20
#define _KERNEL_IRC_PIC1_IMR	0x21
#define _KERNEL_IRC_PIC1_IRR	0x20
#define _KERNEL_IRC_PIC1_ISR	0x20

#define _KERNEL_IRC_PIC2_ICW1	0xa0
#define _KERNEL_IRC_PIC2_ICW2	0xa1
#define _KERNEL_IRC_PIC2_ICW3	0xa1
#define _KERNEL_IRC_PIC2_ICW4	0xa1
#define _KERNEL_IRC_PIC2_OCW1	0xa1
#define _KERNEL_IRC_PIC2_OCW2	0xa0
#define _KERNEL_IRC_PIC2_OCW3	0xa0
#define _KERNEL_IRC_PIC2_IMR	0xa1
#define _KERNEL_IRC_PIC2_IRR	0xa0
#define _KERNEL_IRC_PIC2_ISR	0xa0


/* %jp{PIC ベクタアドレス定義} */
#define _KERNEL_IRC_PIC1_VECT	0x20
#define _KERNEL_IRC_PIC2_VECT	0x28


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


#endif	/* _KERNEL__arch__irc__pcat__irc_h__ */


/* end of file */

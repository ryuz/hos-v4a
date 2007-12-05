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
#define _KERNEL_IRC_INTCNTL				((volatile UW *)0x00223000)		/* Interrupt Control Register */
#define _KERNEL_IRC_NIMASK				((volatile UW *)0x00223004)		/* Normal Interrupt Mask Register */
#define _KERNEL_IRC_INTENNUM			((volatile UW *)0x00223008)		/* Interrupt Enable Number Register */
#define _KERNEL_IRC_INTDISNUM			((volatile UW *)0x0022300c)		/* Interrupt Disable Number Register */
#define _KERNEL_IRC_INTENABLEH			((volatile UW *)0x00223010)		/* Interrupt Enable Register High */
#define _KERNEL_IRC_INTENABLEL			((volatile UW *)0x00223014)		/* Interrupt Enable Register Low */
#define _KERNEL_IRC_INTTYPEH			((volatile UW *)0x00223018)		/* Interrupt Type Register High */
#define _KERNEL_IRC_INTTYPEL			((volatile UW *)0x0022301c)		/* Interrupt Type Register Low */
#define _KERNEL_IRC_NIPRIORITY7			((volatile UW *)0x00223020)		/* Normal Interrupt Priority Level Register 7 */
#define _KERNEL_IRC_NIPRIORITY6			((volatile UW *)0x00223024)		/* Normal Interrupt Priority Level Register 6 */
#define _KERNEL_IRC_NIPRIORITY5			((volatile UW *)0x00223028)		/* Normal Interrupt Priority Level Register 5 */
#define _KERNEL_IRC_NIPRIORITY4			((volatile UW *)0x0022302c)		/* Normal Interrupt Priority Level Register 4 */
#define _KERNEL_IRC_NIPRIORITY3			((volatile UW *)0x00223030)		/* Normal Interrupt Priority Level Register 3 */
#define _KERNEL_IRC_NIPRIORITY2			((volatile UW *)0x00223034)		/* Normal Interrupt Priority Level Register 2 */
#define _KERNEL_IRC_NIPRIORITY1			((volatile UW *)0x00223038)		/* Normal Interrupt Priority Level Register 1 */
#define _KERNEL_IRC_NIPRIORITY0			((volatile UW *)0x0022303c)		/* Normal Interrupt Priority Level Register 0 */
#define _KERNEL_IRC_NIVECSR				((volatile UW *)0x00223040)		/* Normal Interrupt Vector and Status Register */
#define _KERNEL_IRC_FIVECSR				((volatile UW *)0x00223044)		/* Fast Interrupt Vector and Status Register */
#define _KERNEL_IRC_INTSRCH				((volatile UW *)0x00223048)		/* Interrupt Source Register High */
#define _KERNEL_IRC_INTSRCL				((volatile UW *)0x0022304c)		/* Interrupt Source Register Low */
#define _KERNEL_IRC_INTFRCH				((volatile UW *)0x00223050)		/* Interrupt Force Register High */
#define _KERNEL_IRC_INTFRCL				((volatile UW *)0x00223054)		/* Interrupt Force Register Low */
#define _KERNEL_IRC_NIPNDH				((volatile UW *)0x00223058)		/* Normal Interrupt Pending Register High */
#define _KERNEL_IRC_NIPNDL				((volatile UW *)0x0022305c)		/* Normal Interrupt Pending Register Low */
#define _KERNEL_IRC_FIPNDH				((volatile UW *)0x00223060)		/* Fast Interrupt Pending Register High */
#define _KERNEL_IRC_FIPNDL				((volatile UW *)0x00223064)		/* Fast Interrupt Pending Register Low */


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


/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  irc.h
 * @brief %jp{ATMEL AT91シリーズ}%en{ATMEL AT91 series}
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__arch__irc__at91__irc_h__
#define _KERNEL__arch__irc__at91__irc_h__


/* %jp{メモリマップドレジスタ定義} */
#define _KERNEL_IRC_AIC_BASE		0xfffff000

#define _KERNEL_IRC_AIC_SMR(n)		((volatile       UW *)(_KERNEL_IRC_AIC_BASE + 0x000 + ((n) * 4)))		/* Source Mode Register */
#define _KERNEL_IRC_AIC_SVR(n)		((volatile       UW *)(_KERNEL_IRC_AIC_BASE + 0x080 + ((n) * 4)))		/* Source Vector Register 0 */
#define _KERNEL_IRC_AIC_IVR			((volatile const UW *)(_KERNEL_IRC_AIC_BASE + 0x100))					/* IRQ Vector Register */
#define _KERNEL_IRC_AIC_FVR			((volatile const UW *)(_KERNEL_IRC_AIC_BASE + 0x104))					/* FIQ Vector Register */
#define _KERNEL_IRC_AIC_ISR			((volatile const UW *)(_KERNEL_IRC_AIC_BASE + 0x108))					/* Interrupt Status Register */
#define _KERNEL_IRC_AIC_IPR			((volatile const UW *)(_KERNEL_IRC_AIC_BASE + 0x10c))					/* Interrupt Pending Register */
#define _KERNEL_IRC_AIC_IMR			((volatile const UW *)(_KERNEL_IRC_AIC_BASE + 0x110))					/* Interrupt Mask Register */
#define _KERNEL_IRC_AIC_CISR		((volatile const UW *)(_KERNEL_IRC_AIC_BASE + 0x114))					/* Core Interrupt Status Register */
#define _KERNEL_IRC_AIC_IECR		((volatile       UW *)(_KERNEL_IRC_AIC_BASE + 0x120))					/* Interrupt Enable Command Register */
#define _KERNEL_IRC_AIC_IDCR		((volatile       UW *)(_KERNEL_IRC_AIC_BASE + 0x124))					/* Interrupt Disable Command Register */
#define _KERNEL_IRC_AIC_ICCR		((volatile       UW *)(_KERNEL_IRC_AIC_BASE + 0x128))					/* Interrupt Clear Command Register */
#define _KERNEL_IRC_AIC_ISCR		((volatile       UW *)(_KERNEL_IRC_AIC_BASE + 0x12c))					/* Interrupt Set Command Register */
#define _KERNEL_IRC_AIC_EOICR		((volatile       UW *)(_KERNEL_IRC_AIC_BASE + 0x130))					/* End of Interrupt Command Register */
#define _KERNEL_IRC_AIC_SPU			((volatile       UW *)(_KERNEL_IRC_AIC_BASE + 0x134))					/* Spurious Vector Register */



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


#endif	/* _KERNEL__arch__irc__at91__irc_h__ */


/* end of file */


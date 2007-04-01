/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  irc.h
 * @brief %jp{Philips LPC2000ファミリ用}%en{Philips LPC2000 family}
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__arch__irc__lpc2000__irc_h__
#define _KERNEL__arch__irc__lpc2000__irc_h__


/* %jp{メモリマップドレジスタ定義} */
#define _KERNEL_IRC_VICIRQStatus		((volatile UW *)0xfffff000)
#define _KERNEL_IRC_VICFIQStatus		((volatile UW *)0xfffff004)
#define _KERNEL_IRC_VICRawIntr			((volatile UW *)0xfffff008)
#define _KERNEL_IRC_VICIntSelect		((volatile UW *)0xfffff00c)
#define _KERNEL_IRC_VICIntEnable		((volatile UW *)0xfffff010)
#define _KERNEL_IRC_VICIntEnClr			((volatile UW *)0xfffff014)
#define _KERNEL_IRC_VICSoftInt			((volatile UW *)0xfffff018)
#define _KERNEL_IRC_VICSoftIntClear		((volatile UW *)0xfffff01c)
#define _KERNEL_IRC_VICProtection		((volatile UW *)0xfffff020)
#define _KERNEL_IRC_VICVectAddr			((volatile UW *)0xfffff030)
#define _KERNEL_IRC_VICDefVectAddr		((volatile UW *)0xfffff034)
#define _KERNEL_IRC_VICVectAddrN(n)		((volatile UW *)0xfffff100 + ((n) * 4))
#define _KERNEL_IRC_VICVectCntlN(n)		((volatile UW *)0xfffff200 + ((n) * 4))



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


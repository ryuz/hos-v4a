/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  irc.h
 * @brief %jp{ARM PL390割込みコントローラ操作}%en{ARM PL390}
 *
 * Copyright (C) 1998-2020 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__arch__irc__arm_pl390__irc_h__
#define _KERNEL__arch__irc__arm_pl390__irc_h__


/* %jp{メモリマップドレジスタ定義} */
#define _KERNEL_IRC_ICCICR				((volatile UW *)((B*)_kernel_irc_reg_base + 0x000))
#define _KERNEL_IRC_ICCPMR				((volatile UW *)((B*)_kernel_irc_reg_base + 0x004))
#define _KERNEL_IRC_ICCBPR				((volatile UW *)((B*)_kernel_irc_reg_base + 0x008))
#define _KERNEL_IRC_ICCIAR				((volatile UW *)((B*)_kernel_irc_reg_base + 0x00C))
#define _KERNEL_IRC_ICCEOIR		    	((volatile UW *)((B*)_kernel_irc_reg_base + 0x010))
#define _KERNEL_IRC_ICCRPR		    	((volatile UW *)((B*)_kernel_irc_reg_base + 0x014))
#define _KERNEL_IRC_ICCHPIR		    	((volatile UW *)((B*)_kernel_irc_reg_base + 0x018))
#define _KERNEL_IRC_ICCABPR		    	((volatile UW *)((B*)_kernel_irc_reg_base + 0x01c))
#define _KERNEL_IRC_ICCIDR		    	((volatile UW *)((B*)_kernel_irc_reg_base + 0x0fc))

#define _KERNEL_IRC_ICDDCR		        ((volatile UW *)((B*)_kernel_irc_reg2_base + 0x000))
#define _KERNEL_IRC_ICDICTR		        ((volatile UW *)((B*)_kernel_irc_reg2_base + 0x004))
#define _KERNEL_IRC_ICDIIDR		        ((volatile UW *)((B*)_kernel_irc_reg2_base + 0x008))
#define _KERNEL_IRC_ICDISR(n)			((volatile UW *)((B*)_kernel_irc_reg2_base + 0x080 + 4*(n)))    /* 割り込みセキュリティレジスタ */
#define _KERNEL_IRC_ICDISER(n)			((volatile UW *)((B*)_kernel_irc_reg2_base + 0x100 + 4*(n)))    /* 割り込みイネーブルセットレジスタ */
#define _KERNEL_IRC_ICDICER(n)			((volatile UW *)((B*)_kernel_irc_reg2_base + 0x180 + 4*(n)))    /* 割り込みイネーブルクリアレジスタ */
#define _KERNEL_IRC_ICDISPR(n)			((volatile UW *)((B*)_kernel_irc_reg2_base + 0x200 + 4*(n)))    /* 割り込み保留セットレジスタ */
#define _KERNEL_IRC_ICDICPR(n)			((volatile UW *)((B*)_kernel_irc_reg2_base + 0x280 + 4*(n)))    /* 割り込み保留クリアセットレジスタ */
#define _KERNEL_IRC_ICDABR(n)			((volatile UW *)((B*)_kernel_irc_reg2_base + 0x300 + 4*(n)))    /* アクティブビット レジスタ */
#define _KERNEL_IRC_ICDIPR(n)			((volatile UB *)((B*)_kernel_irc_reg2_base + 0x400 + 1*(n)))    /* 割り込み優先度レジスタ */ 
#define _KERNEL_IRC_ICDIPTR(n)          ((volatile UB *)((B*)_kernel_irc_reg2_base + 0x800 + 1*(n)))    /* 割り込みプロセッサターゲットレジスタ */
#define _KERNEL_IRC_ICDICFR(n)          ((volatile UW *)((B*)_kernel_irc_reg2_base + 0xc00 + 4*(n)))    /* 割り込み構成レジスタ */
#define _KERNEL_IRC_ICDSGIR             ((volatile UW *)((B*)_kernel_irc_reg2_base + 0xf00)

#ifdef __cplusplus
extern "C" {
#endif

#define _KERNEL_ARM_PL390_ICDICFR_LEVEL 0x01
#define _KERNEL_ARM_PL390_ICDICFR_EDGE  0x03

ER   vchg_icdiptr(INTNO intno, UB cpuid);   /* set ICDIPTR */ 
ER   vchg_icdicfr(INTNO intno, UB type);    /* set ICDICFR */
ER   vdis_icd(void);
ER   vena_icd(void);

void _kernel_ini_irc(void);			/**< %jp{割込みコントローラの初期化} */
void _kernel_exe_irc(INHNO inhno);	/**< %jp{割込み処理} */

#ifdef __cplusplus
}
#endif


#define _KERNEL_INI_IRC()		_kernel_ini_irc()		/**< %jp{割込みコントローラの初期化} */
#define _KERNEL_EXE_IRC(inhno)	_kernel_exe_irc(inhno)	/**< %jp{割込み処理} */


#endif	/* _KERNEL__arch__irc__arm_pl390__irc_h__ */


/* end of file */


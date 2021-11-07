/**
 *  Hyper Operating System V4 Advance
 *
 * @file  clint-irc.h
 * @brief RISC-V Core-local Interruptor
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__arch__irc__riscv__clint__clint_irc_h__
#define _KERNEL__arch__irc__riscv__clint__clint_irc_h__

/** %jp{マシンモードソフトウエア割込み} */
#define _KERNEL_RISCV_IRC_CLINT_MSIP_BIT     (3)
/** %jp{マシンモードタイマ割込み} */
#define _KERNEL_RISCV_IRC_CLINT_MTIP_BIT     (7)
/** %jp{マシンモード外部割込み} */
#define _KERNEL_RISCV_IRC_CLINT_MEIP_BIT     (11)
/** %jp{割込み要因数} */
#define _KERNEL_RISCV_IRC_CLINT_FACTORS      (2)

#ifndef _ASM_FILE
#ifdef __cplusplus
extern "C" {
#endif

/**
   %jp{QEMU Core Local Interruptor (CLINT)
   レジスタアドレス}
*/
#define _KERNEL_RISCV_IRC_CLINT_ADDR             ((VP)(0x2000000))

/**
   %jp{QEMU Core Local Interruptor (CLINT)
   レジスタサイズ  (単位:バイト)}
*/
#define _KERNEL_RISCV_IRC_CLINT_SIZE             (0x10000)
/**
   %jp{QEMU Core Local Interruptor (CLINT)
   MTIME レジスタのカウンタ1ms単位での更新値}
 */
#define _KERNEL_RISCV_IRC_CLINT_MTIME_INTERVAL   (10000)

/**
   %jp{QEMU Core Local Interruptor (CLINT)
   MTIMECMP レジスタ
   サイズ (単位:バイト)}
*/
#define _KERNEL_RISCV_IRC_CLINT_MTIMECMP_SIZE    (8)

/**
   %jp{QEmu Core Local Interruptor (CLINT) MTIMECMP レジスタ
   オフセットアドレス}
*/
#define _KERNEL_RISCV_IRC_CLINT_MTIMECMP_OFFSET  (0x4000)

/**
   %jp{QEmu Core Local Interruptor (CLINT)
   MTIME オフセットアドレス}
*/
#define _KERNEL_RISCV_IRC_CLINT_MTIME_OFFSET      (0xBFF8)

/**
   %jp{Core Local Interruptor (CLINT)
   Machine Mode Software Interrupt Pending (MSIP) レジスタ
   オフセットアドレス}
*/
#define _KERNEL_RISCV_IRC_CLINT_MSIP_OFFSET      (0x0)

/**
   %jp{Core Local Interruptor (CLINT)
   Machine Mode Software Interrupt Pending (MSIP) レジスタ
   サイズ (単位:バイト)}
*/
#define _KERNEL_RISCV_IRC_CLINT_MSIP_SIZE        (4)

/**
   %jp{Core Local Interruptor (CLINT)
   MSIP レジスタ
   物理アドレス}
   _hart %jp{コアのhartid}
   返り値 %jp{MSIP レジスタ 物理アドレス}
 */
#define _KERNEL_RISCV_IRC_CLINT_MSIP_PADDR(_hart)		\
	((volatile UW *)(_KERNEL_RISCV_IRC_CLINT_ADDR		\
	    + _KERNEL_RISCV_IRC_CLINT_MSIP_OFFSET		\
	    + ( (_hart) * _KERNEL_RISCV_IRC_CLINT_MSIP_SIZE) ) )

/**
   %jp{Core Local Interruptor (CLINT)
   MTIMECMP レジスタ 物理アドレス}
   _hart %jp{コアのhartid}
   返り値 %jp{MTIMECMP レジスタ 物理アドレス}
 */
#define _KERNEL_RISCV_IRC_CLINT_MTIMECMP_ADDR(_hart)			\
	( (volatile UD *)(_KERNEL_RISCV_IRC_CLINT_ADDR			\
	    + _KERNEL_RISCV_IRC_CLINT_MTIMECMP_OFFSET			\
	    + ( (_hart) * _KERNEL_RISCV_IRC_CLINT_MTIMECMP_SIZE)) )


UD _kernel_riscv_irc_read_mie(void);
void _kernel_riscv_irc_write_mie(UD reg);

UD _kernel_riscv_irc_read_mip(void);
void _kernel_riscv_irc_write_mip(UD reg);

void _kernel_riscv_irc_clint_ini_irc(void);	        /**< %jp{割込み初期化} */
void _kernel_riscv_irc_clint_exe_irc(INHNO inhno);	/**< %jp{割込み処理} */
ER _kernel_riscv_irc_clint_ena_int(INTNO intno);	/**< %jp{割込み許可} */
ER _kernel_riscv_irc_clint_dis_int(INTNO intno);	/**< %jp{割込み禁止} */
ER _kernel_riscv_irc_clint_clr_int(INTNO intno);        /**< %jp{割込み要因クリア} */
#ifdef __cplusplus
}
#endif
#endif  /* !_ASM_FILE */

#endif	/* _KERNEL__arch__irc__riscv__clint__clint_irc_h__ */


/* end of file */

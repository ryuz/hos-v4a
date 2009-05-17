
#ifndef _KERNEL__arch__irc__mn103s__irc_h__
#define _KERNEL__arch__irc__mn103s__irc_h__


#define _KERNEL_MN103S_MAKE_INTNO(group, factor)	(((group) << 2) + ((factor) & 0x03))

/* %jp{割込みコントローラのレジスタ定義} */
#define _KERNEL_MN103S_INTC_BASE			0x00008900
#define _KERNEL_MN103S_INTC_GICR(intno)		((volatile UH *)(0x00008900 + ((intno) & ~0x03)))
#define _KERNEL_MN103S_INTC_IAGR			((volatile UH *)(0x00008a00))
#define _KERNEL_MN103S_INTC_EXTMD0			((volatile UH *)(0x00008a80))
#define _KERNEL_MN103S_INTC_EXTMD1			((volatile UH *)(0x00008a84))


#ifdef __cplusplus
extern "C" {
#endif

void _kernel_ini_irc(void);				/* 割込みコントローラの初期化 */
void _kernel_exe_irc(void);				/* 割込み処理の実施 */

#ifdef __cplusplus
}
#endif


#define _KERNEL_INI_IRC()			_kernel_ini_irc()
#define _KERNEL_EXE_IRC(inhno)		_kernel_exe_irc()


#endif	/* _KERNEL__arch__irc__mn103s__irc_h__ */


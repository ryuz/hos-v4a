/**
 *  Hyper Operating System V4 Advance
 *
 * @file  clint-irc.h
 * @brief RISC-V Core-local Interrupt Controller
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__arch__irc__riscv__irc_h__
#define _KERNEL__arch__irc__riscv__irc_h__

#include "clint_irc.h"
#include "plic_irc.h"

#if !defined(_MACRO_ONLY)

#ifdef __cplusplus
extern "C" {
#endif

void _kernel_ini_irc(void);		/**< %jp{割込みコントローラの初期化} */
void _kernel_exe_irc(INHNO inhno);	/**< %jp{割込み処理} */

#define _KERNEL_INI_IRC()	_kernel_ini_irc()	/**< %jp{割込みコントローラの初期化} */
#define _KERNEL_EXE_IRC(inhno)	_kernel_exe_irc(inhno)	/**< %jp{割込み処理} */

#define chg_imsk(_imsk)          _kernel_riscv_irc_plic_chg_imsk(_imsk) /**< %jp{割込みマスク変更} */
#define get_imsk(_p_imsk)        _kernel_riscv_irc_plic_get_imsk(_p_imsk) /**< %jp{割込みマスク取得} */
#define cfg_int(_intno, _p_cint)  _kernel_riscv_irc_plic_cfg_int((_intno), (_p_cint)) /**< %jp{割込み線設定} */


#ifdef __cplusplus
}
#endif

#endif  /* !_MACRO_ONLY */

#endif	/* _KERNEL__arch__irc__riscv__irc_h__ */


/* end of file */

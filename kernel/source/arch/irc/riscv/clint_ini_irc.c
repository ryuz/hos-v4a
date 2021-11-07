/**
 *  Hyper Operating System V4 Advance
 *
 * @file  clint_exe_irc.c
 * @brief RISC-V Core-local Interruptor 初期化
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"


/** %jp{割込みコントローラの初期化} */
void _kernel_riscv_irc_clint_ini_irc(void)
{
	UD mask;

	mask = _kernel_riscv_irc_read_mie(); /* %jp{現在のマスクを取得} */
	/* %jp{マシンモードのソフトウェア割込み, タイマ割込みをマスク} */
	mask &= ~(
		( (UD)1 << _KERNEL_RISCV_IRC_CLINT_MSIP_BIT ) |
		( (UD)1 << _KERNEL_RISCV_IRC_CLINT_MTIP_BIT ) );
	/* %jp{マシンモードの外部割込みをアンマスク} */
	mask |= ( (UD)1 << _KERNEL_RISCV_IRC_CLINT_MEIP_BIT );

	_kernel_riscv_irc_write_mie(mask); /* %jp{マスクを設定} */
}

/* end of file */

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

	/*
	  %jp{マシンモードのソフトウェア割込み, タイマ割込みをマスクする。
	  外部割込みのマスク操作は, PLICで実施するために,
	  動作中は, CLINTの外部割込みマスクを常に解放しておく。}
	 */
	_kernel_riscv_irc_write_mie( ( _kernel_riscv_irc_read_mie()
	    &  ~( ( (UD)1 << _KERNEL_RISCV_IRC_CLINT_MSIP_BIT ) |
		( (UD)1 << _KERNEL_RISCV_IRC_CLINT_MTIP_BIT ) ) ) |
	    ( (UD)1 << _KERNEL_RISCV_IRC_CLINT_MEIP_BIT ) );
}


/* end of file */

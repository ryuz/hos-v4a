/**
 *  Hyper Operating System V4 Advance
 *
 * @file  clint_exe_irc.c
 * @brief RISC-V Core-local Interruptor
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"

static UD riscv_irc_clint_pending_list[]={
	_KERNEL_RISCV_IRC_CLINT_MSIP_BIT,  /* INHNO = 0 */
	_KERNEL_RISCV_IRC_CLINT_MTIP_BIT  /* INHNO = 1 */
};

/** %jp{割込みコントローラの割込み処理} */
void _kernel_riscv_irc_clint_exe_irc(INHNO inhno)
{
	UD	    mask;
	UD       pending;
	UD           cur;
	INHNO          i;


	/* %jp{割込み要因解析} */
	pending = _kernel_riscv_irc_read_mip();
	mask = _kernel_riscv_irc_read_mie();
	for(i = 0; _KERNEL_RISCV_IRC_CLINT_FACTORS > i; ++i) {

		/* %jp{割込み発生有無を確認} */
		cur = (UD)1 << riscv_irc_clint_pending_list[i];
		if ( pending & cur ) {

			/* %jp{前処理} */
			/* %jp{割込みをマスク} */
			_kernel_riscv_irc_write_mie(mask & ~cur);
			/* %jp{タイマ割込みで無ければ割込みペンディングビットをクリア
			 * MIPのタイマ割込みビットは, 読み取り専用ビットであるため書き換えない
			 * (CLICのTIMECMPレジスタへの書込みによりビットクリアされる)}
			 */
			if (i != 1)
				pending &= ~cur;
			 /* %jp{割込みACK}  */
			_kernel_riscv_irc_write_mip(pending);

			/* %jp{割込みサービスルーチン呼び出し} */
			_kernel_exe_isr(i);

			/* %jp{割込み終了} */
			_kernel_riscv_irc_write_mie(mask | cur); /* 割込みをアンマスク */
		}
	}
}


/* end of file */

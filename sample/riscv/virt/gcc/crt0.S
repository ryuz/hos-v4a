/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Advance                                       */
/*  Sample program for mvirt                                                */
/*                                                                          */
/*                                  Copyright (C) 2008 by Project HOS       */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */

#define _ASM_FILE
#include "arch/proc/riscv/procatr.h"

				.extern		_kernel_int_isp
				.extern		_kernel_exc_hdr
				.extern		___data
				.extern		___data_end
				.extern		___bss
				.extern		___bss_end
				.extern		_gp
				.extern		main

				.global		_entry
				.global		_riscv_machine_vector

				.text
/************************************************
  %jp{エントリアドレス}
************************************************/
_entry:
				la		gp, _gp /* %jp{GPレジスタ初期化} */
				/* %jp{非タスクコンテキスト用スタックロード} */
				la		t0, _kernel_int_isp
				_KERNEL_RISCV_PROC_LD	sp, (t0) /* %jp{スタック設定} */

				/* %jp{BSSの初期化} */
				la		t0, ___bss /* %jp{BSS開始アドレス} */
				la		t1, ___bss_end /* %jp{BSS終了アドレス} */
clear_bss:
				_KERNEL_RISCV_PROC_ST	zero, (t0)  /* %jp{ゼロクリア} */
				add 		t0, t0, 8 /*  %jp{アドレスを加算} */
				/* %jp{BSS領域の終了までループする} */
				blt 		t0, t1, clear_bss

				/* %jp{割込みベクタ設定} */
        			la   		t0, _riscv_machine_vector
				/* %jp{マシンモードベクタアドレスを設定} */
        			csrw		mtvec, t0

				/* %jp{main関数のアドレスをロード} */
				la   		ra, main
				/* %jp{main関数にジャンプする} */
				jr              ra
junk:
				/* %jp{main関数から復帰後はループする} */
				j		junk

.balign 4
_riscv_machine_vector:
				j	_kernel_exc_hdr
/* end of file */

/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Advance                                       */
/*    RISC-V Architecture                                                   */
/*                                                                          */
/*                                  Copyright (C) 1998-2008 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */

#define _MACRO_ONLY
#include "procatr.h"

				.text


/************************************************
  実行コンテキストの作成
  void _kernel_cre_ctx(
			_KERNEL_T_CTXCB *pk_ctxcb,	[a0]   : 作成するコンテキスト
			VP             isp,		[a1]   : スタックポインタ
			FP             entry,		[a2]   : 実行アドレス
			VP_INT         par1,		[a3]   : 実行時パラメータ1
			VP_INT         par2)		[a4]   : 実行時パラメータ2
 ************************************************/
				.global	_kernel_cre_ctx
_kernel_cre_ctx:
				/* %jp{コンテキスト保存領域を確保} */
				addi	a1, a1, -_KERNEL_RISCV_PROC_TSKCTX_SIZE

				/* %jp{コンテキスト保存領域をpk_ctxcbが指し示すアドレスに格納} */
				_KERNEL_RISCV_PROC_ST	a1, (a0)
				/* %jp{実行パラメタ1を実行コンテキストのs0レジスタに格納} */
				_KERNEL_RISCV_PROC_ST	a3, _KERNEL_RISCV_PROC_TSKCTX_S0(a1)
				/* %jp{実行パラメタ2を実行コンテキストのs1レジスタに格納} */
				_KERNEL_RISCV_PROC_ST	a4, _KERNEL_RISCV_PROC_TSKCTX_S1(a1)
				/* %jp{実行アドレスを実行コンテキストのs2レジスタに格納} */
				_KERNEL_RISCV_PROC_ST	a2, _KERNEL_RISCV_PROC_TSKCTX_S2(a1)
				/* %jp{エントリアドレスをロード} */
				la	t0, ctx_entry
				/* %jp{エントリアドレスを実行コンテキストのraレジスタに格納} */
				_KERNEL_RISCV_PROC_ST	t0, _KERNEL_RISCV_PROC_TSKCTX_RA(a1)

				jr	ra

/************************************************
  実行コンテキストエントリーアドレス
 ************************************************/
ctx_entry:
				mv	a0, s0		/* s0 : 実行時パラメータ1 */
				mv	a1, s1		/* s1 : 実行時パラメータ2 */
				jr	s2
/* end of file */

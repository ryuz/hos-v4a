/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Advance                                       */
/*    RISC-V Architecture                                                   */
/*                                                                          */
/*                                  Copyright (C) 1998-2008 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */

#define _ASM_FILE
#include "procatr.h"

				.text
/************************************************
  %jp{実行コンテキストの切替
  void _kernel_swi_ctx(
			_KERNEL_T_CTXCB *pk_ctxinf_nxt,	[a0] : 切り替えるコンテキスト
			_KERNEL_T_CTXCB *pk_ctxinf_now)	[a1] : 現在のコンテキストの保存先}
 ************************************************/
				.global	_kernel_swi_ctx
_kernel_swi_ctx:
				/* %jp{コンテキスト保存領域を確保} */
				addi	sp, sp, -_KERNEL_RISCV_PROC_TSKCTX_SIZE
				_KERNEL_RISCV_PROC_ST	ra, _KERNEL_RISCV_PROC_TSKCTX_RA(sp)	/* ra */
				_KERNEL_RISCV_PROC_ST	s0, _KERNEL_RISCV_PROC_TSKCTX_S0(sp)	/* s0 */
				_KERNEL_RISCV_PROC_ST	s1, _KERNEL_RISCV_PROC_TSKCTX_S1(sp)	/* s1 */
				_KERNEL_RISCV_PROC_ST	s2, _KERNEL_RISCV_PROC_TSKCTX_S2(sp)	/* s2 */
				_KERNEL_RISCV_PROC_ST	s3, _KERNEL_RISCV_PROC_TSKCTX_S3(sp)	/* s3 */
				_KERNEL_RISCV_PROC_ST	s4, _KERNEL_RISCV_PROC_TSKCTX_S4(sp)	/* s4 */
				_KERNEL_RISCV_PROC_ST	s5, _KERNEL_RISCV_PROC_TSKCTX_S5(sp)	/* s5 */
				_KERNEL_RISCV_PROC_ST	s6, _KERNEL_RISCV_PROC_TSKCTX_S6(sp)	/* s6 */
				_KERNEL_RISCV_PROC_ST	s7, _KERNEL_RISCV_PROC_TSKCTX_S7(sp)	/* s7 */
				_KERNEL_RISCV_PROC_ST	s8, _KERNEL_RISCV_PROC_TSKCTX_S8(sp)	/* s8 */
				_KERNEL_RISCV_PROC_ST	s9, _KERNEL_RISCV_PROC_TSKCTX_S9(sp)	/* s9 */
				_KERNEL_RISCV_PROC_ST	s10, _KERNEL_RISCV_PROC_TSKCTX_S10(sp)	/* s10 */
				_KERNEL_RISCV_PROC_ST	s11, _KERNEL_RISCV_PROC_TSKCTX_S11(sp)	/* s11 */

				_KERNEL_RISCV_PROC_ST	sp, (a1)        /* %jp{sp保存} */

				/* --- %jp{そのまま _kernel_sta_ctx に続ける} */

/************************************************
  %jp{実行コンテキストの開始
  void _kernel_sta_ctx(
	_KERNEL_T_CTXCB *pk_ctxcb) [a0] : 実行を開始するコンテキスト}
 ************************************************/
				.global	_kernel_sta_ctx
_kernel_sta_ctx:
				_KERNEL_RISCV_PROC_LD	sp, 0(a0)	/* %jp{sp復帰} */

				_KERNEL_RISCV_PROC_LD	s11, _KERNEL_RISCV_PROC_TSKCTX_S11(sp)	/* s11 */
				_KERNEL_RISCV_PROC_LD	s10, _KERNEL_RISCV_PROC_TSKCTX_S10(sp)	/* s10 */
				_KERNEL_RISCV_PROC_LD	s9, _KERNEL_RISCV_PROC_TSKCTX_S9(sp)	/* s9 */
				_KERNEL_RISCV_PROC_LD	s8, _KERNEL_RISCV_PROC_TSKCTX_S8(sp)	/* s8 */
				_KERNEL_RISCV_PROC_LD	s7, _KERNEL_RISCV_PROC_TSKCTX_S7(sp)	/* s7 */
				_KERNEL_RISCV_PROC_LD	s6, _KERNEL_RISCV_PROC_TSKCTX_S6(sp)	/* s6 */
				_KERNEL_RISCV_PROC_LD	s5, _KERNEL_RISCV_PROC_TSKCTX_S5(sp)	/* s5 */
				_KERNEL_RISCV_PROC_LD	s4, _KERNEL_RISCV_PROC_TSKCTX_S4(sp)	/* s4 */
				_KERNEL_RISCV_PROC_LD	s3, _KERNEL_RISCV_PROC_TSKCTX_S3(sp)	/* s3 */
				_KERNEL_RISCV_PROC_LD	s2, _KERNEL_RISCV_PROC_TSKCTX_S2(sp)	/* s2 */
				_KERNEL_RISCV_PROC_LD	s1, _KERNEL_RISCV_PROC_TSKCTX_S1(sp)	/* s1 */
				_KERNEL_RISCV_PROC_LD	s0, _KERNEL_RISCV_PROC_TSKCTX_S0(sp)	/* s0 */
				_KERNEL_RISCV_PROC_LD	ra, _KERNEL_RISCV_PROC_TSKCTX_RA(sp)	/* ra */

				/* %jp{コンテキスト保存領域を解放} */
				addi	sp, sp, _KERNEL_RISCV_PROC_TSKCTX_SIZE

				jr	ra

/* end of file */

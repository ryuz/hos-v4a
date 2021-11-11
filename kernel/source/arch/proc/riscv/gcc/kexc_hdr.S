/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Advance                                       */
/*    RISC-V Architecture                                                   */
/*                                                                          */
/*                                  Copyright (C) 1998-2008 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */

#define _ASM_FILE
#include "procatr.h"
#include "clint_irc.h"

				.extern	_kernel_ictxcb
				.extern	_kernel_sta_inh
				.extern	_kernel_end_inh
				.extern	_kernel_exe_inh
				.extern _kernel_exe_exh

				.global	_kernel_exc_hdr
				.global handle_exception
				.text

/************************************************
   %jp{例外処理ハンドラ}
 ************************************************/
_kernel_exc_hdr:
				/* %jp{例外コンテキスト保存領域を確保} */
				addi	sp, sp, -_KERNEL_RISCV_PROC_ICTX_SIZE
				/* %jp{例外コンテキスト保存} */
				_KERNEL_RISCV_PROC_ST	ra, _KERNEL_RISCV_PROC_ICTX_RA(sp)
				_KERNEL_RISCV_PROC_ST	t0, _KERNEL_RISCV_PROC_ICTX_T0(sp)
				_KERNEL_RISCV_PROC_ST	t1, _KERNEL_RISCV_PROC_ICTX_T1(sp)
				_KERNEL_RISCV_PROC_ST	t2, _KERNEL_RISCV_PROC_ICTX_T2(sp)
				_KERNEL_RISCV_PROC_ST	t3, _KERNEL_RISCV_PROC_ICTX_T3(sp)
				_KERNEL_RISCV_PROC_ST	t4, _KERNEL_RISCV_PROC_ICTX_T4(sp)
				_KERNEL_RISCV_PROC_ST	t5, _KERNEL_RISCV_PROC_ICTX_T5(sp)
				_KERNEL_RISCV_PROC_ST	t6, _KERNEL_RISCV_PROC_ICTX_T6(sp)
				_KERNEL_RISCV_PROC_ST	a0, _KERNEL_RISCV_PROC_ICTX_A0(sp)
				_KERNEL_RISCV_PROC_ST	a1, _KERNEL_RISCV_PROC_ICTX_A1(sp)
				_KERNEL_RISCV_PROC_ST	a2, _KERNEL_RISCV_PROC_ICTX_A2(sp)
				_KERNEL_RISCV_PROC_ST	a3, _KERNEL_RISCV_PROC_ICTX_A3(sp)
				_KERNEL_RISCV_PROC_ST	a4, _KERNEL_RISCV_PROC_ICTX_A4(sp)
				_KERNEL_RISCV_PROC_ST	a5, _KERNEL_RISCV_PROC_ICTX_A5(sp)
				_KERNEL_RISCV_PROC_ST	a6, _KERNEL_RISCV_PROC_ICTX_A6(sp)
				_KERNEL_RISCV_PROC_ST	a7, _KERNEL_RISCV_PROC_ICTX_A7(sp)
				csrr	t0, mepc
				_KERNEL_RISCV_PROC_ST   t0, _KERNEL_RISCV_PROC_ICTX_EPC(sp)
        			csrr	t0, mstatus
				_KERNEL_RISCV_PROC_ST	t0, _KERNEL_RISCV_PROC_ICTX_STATUS(sp)

				/* %jp{割込み/例外判定} */
				csrr	a0, mcause
				bgez	a0, handle_exception /* %jp{例外処理} */
handle_interrupt:
				/* %jp{割込み要因取得} */
				/* %jp{割込みビットクリアマスク} */
				li	t0, ~(1 << (_KERNEL_RISCV_XLEN - 1))
				and	t0, a0, t0 /* %jp{割込みビットクリア} */

				/* %jp{割込み番号取得} */
				li	a0, 2  /* %jp{外部割り込みを仮定} */
check_softint:
				li	t1, _KERNEL_RISCV_IRC_CLINT_MSIP_BIT
				bne     t0, t1, check_timer
				mv	a0, zero  /* %jp{ソフトウエア割込み} */
				j	check_multipleint
check_timer:
				li	t1, _KERNEL_RISCV_IRC_CLINT_MTIP_BIT
				bne     t0, t1, check_multipleint
				li	a0, 1  /* %{タイマ割込み} */
				/* %jp{多重割込み判定に入る} */

				/*
				 * %jp{多重割込み判定}
				 */
check_multipleint:
				/* %jp{割込みコンテキスト制御ブロック} */
				la	t0, _kernel_ictxcb
				lbu	t1, 0(t0) /* %jp{intcnt読込み} */
				/* %jp{多重割込みの場合は, multiple_int にジャンプ} */
				bne	zero, t1, multiple_int

				/*
				 * %jp{スタック入れ替え}
				 */
				mv	t2, sp /* %jp{タスクスタック値保存} */
				_KERNEL_RISCV_PROC_LD	sp, _KERNEL_RISCV_REGSIZE(t0) /* %jp{割込みスタックロード} */

				/* %jp{割込みスタックの底にタスクスタックポインタ保存} */
				/* %jp{保存領域確保} */
				add	sp, sp, -_KERNEL_RISCV_REGSIZE
				/* %jp{スタック値保存} */
				_KERNEL_RISCV_PROC_ST	t2, 0(sp)

				/* %jp{割込み開始(非タスクコンテキストへの遷移)処理} */
				jal	_kernel_sta_inh
multiple_int:
				add	t1, t1, 1  /* %jp{intcntインクリメント} */
				sb	t1, 0(t0) /* %jp{intcnt更新} */

				/* %jp{割込みハンドラ実行, a0:割込み要因} */
				jal	_kernel_exe_inh

				/*
				 * %jp{多重割込み判定}
				 */
				/* %jp{割込みコンテキスト制御ブロック} */
				la	t0, _kernel_ictxcb
				lbu	t1, 0(t0) /* %jp{intcnt読込み} */

				add	t1, t1, -1  /* %jp{intcntデクリメント} */
				sb	t1, 0(t0) /* %jp{intcnt更新} */

				/* %jp{多重割込みの場合は, resume_exceptionにジャンプ} */
				bne	zero, t1, _kernel_riscv_resume_exc

				/* %jp{割込みスタックからタスクスタックポインタ復元} */
				_KERNEL_RISCV_PROC_LD	sp, 0(sp) /* %jp{スタック値復元} */

				/* %jp{割込み終了(タスクコンテキストへの遷移)処理} */
				jal	_kernel_end_inh

				/* %jp{割込み元に復帰} */
_kernel_riscv_resume_exc:
				_KERNEL_RISCV_PROC_LD	t0, _KERNEL_RISCV_PROC_ICTX_STATUS(sp)
				csrw	mstatus, t0
				_KERNEL_RISCV_PROC_LD	t0, _KERNEL_RISCV_PROC_ICTX_EPC(sp)
				csrw	mepc, t0
				_KERNEL_RISCV_PROC_LD	a7, _KERNEL_RISCV_PROC_ICTX_A7(sp)
				_KERNEL_RISCV_PROC_LD	a6, _KERNEL_RISCV_PROC_ICTX_A6(sp)
				_KERNEL_RISCV_PROC_LD	a5, _KERNEL_RISCV_PROC_ICTX_A5(sp)
				_KERNEL_RISCV_PROC_LD	a4, _KERNEL_RISCV_PROC_ICTX_A4(sp)
				_KERNEL_RISCV_PROC_LD	a3, _KERNEL_RISCV_PROC_ICTX_A3(sp)
				_KERNEL_RISCV_PROC_LD	a2, _KERNEL_RISCV_PROC_ICTX_A2(sp)
				_KERNEL_RISCV_PROC_LD	a1, _KERNEL_RISCV_PROC_ICTX_A1(sp)
				_KERNEL_RISCV_PROC_LD	a0, _KERNEL_RISCV_PROC_ICTX_A0(sp)
				_KERNEL_RISCV_PROC_LD	t6, _KERNEL_RISCV_PROC_ICTX_T6(sp)
				_KERNEL_RISCV_PROC_LD	t5, _KERNEL_RISCV_PROC_ICTX_T5(sp)
				_KERNEL_RISCV_PROC_LD	t4, _KERNEL_RISCV_PROC_ICTX_T4(sp)
				_KERNEL_RISCV_PROC_LD	t3, _KERNEL_RISCV_PROC_ICTX_T3(sp)
				_KERNEL_RISCV_PROC_LD	t2, _KERNEL_RISCV_PROC_ICTX_T2(sp)
				_KERNEL_RISCV_PROC_LD	t1, _KERNEL_RISCV_PROC_ICTX_T1(sp)
				_KERNEL_RISCV_PROC_LD	t0, _KERNEL_RISCV_PROC_ICTX_T0(sp)
				_KERNEL_RISCV_PROC_LD	ra, _KERNEL_RISCV_PROC_ICTX_RA(sp)
				addi	sp, sp, _KERNEL_RISCV_PROC_ICTX_SIZE
				mret

				/* %jp{例外ハンドラ処理} */
handle_exception:
				/* %jp{例外ハンドラ実行, a0:割込み要因} */
				/* TODO:def_exc関連処理実装 */
//				jal	_kernel_exe_exh

				j 	_kernel_riscv_resume_exc  /* %jp{例外復帰} */
/* end of file */

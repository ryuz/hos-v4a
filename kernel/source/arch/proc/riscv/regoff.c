/**
 * Hyper Operating System V4 Advance
 *
 * @file  regoff.c
 * @brief %jp{アセンブラ用レジスタオフセット定義生成ファイル}%en{register offset definitions}
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include "asm_offset_helper.h"

#include "itron.h"
#include "procatr.h"

int main(int argc, char *argv[])
{

	/*
	 * %jp{割込みコンテキスト定義}
	 */

	/* %jp{割込みコンテキストサイズ(単位:バイト)}  */
	DEFINE_VAL(_KERNEL_RISCV_PROC_ICTX_SIZE, sizeof(struct _kernel_riscv_ictx));


	/*  %jp{RAレジスタオフセット(単位:バイト)}  */
	OFFSET(_KERNEL_RISCV_PROC_ICTX_RA, _kernel_riscv_ictx, ra);

	/*
	 * %jp{T0-T6レジスタオフセット(単位:バイト)}
	 */
	OFFSET(_KERNEL_RISCV_PROC_ICTX_T0, _kernel_riscv_ictx, t0);
	OFFSET(_KERNEL_RISCV_PROC_ICTX_T1, _kernel_riscv_ictx, t1);
	OFFSET(_KERNEL_RISCV_PROC_ICTX_T2, _kernel_riscv_ictx, t2);
	OFFSET(_KERNEL_RISCV_PROC_ICTX_T3, _kernel_riscv_ictx, t3);
	OFFSET(_KERNEL_RISCV_PROC_ICTX_T4, _kernel_riscv_ictx, t4);
	OFFSET(_KERNEL_RISCV_PROC_ICTX_T5, _kernel_riscv_ictx, t5);
	OFFSET(_KERNEL_RISCV_PROC_ICTX_T6, _kernel_riscv_ictx, t6);

	/*
	 * %jp{A0-A6レジスタオフセット(単位:バイト)}
	 */
	OFFSET(_KERNEL_RISCV_PROC_ICTX_A0, _kernel_riscv_ictx, a0);
	OFFSET(_KERNEL_RISCV_PROC_ICTX_A1, _kernel_riscv_ictx, a1);
	OFFSET(_KERNEL_RISCV_PROC_ICTX_A2, _kernel_riscv_ictx, a2);
	OFFSET(_KERNEL_RISCV_PROC_ICTX_A3, _kernel_riscv_ictx, a3);
	OFFSET(_KERNEL_RISCV_PROC_ICTX_A4, _kernel_riscv_ictx, a4);
	OFFSET(_KERNEL_RISCV_PROC_ICTX_A5, _kernel_riscv_ictx, a5);
	OFFSET(_KERNEL_RISCV_PROC_ICTX_A6, _kernel_riscv_ictx, a6);
	OFFSET(_KERNEL_RISCV_PROC_ICTX_A7, _kernel_riscv_ictx, a7);

	/*  %jp{EPCレジスタオフセット(単位:バイト)}  */
	OFFSET(_KERNEL_RISCV_PROC_ICTX_EPC, _kernel_riscv_ictx, epc);

	/*  %jp{STATUSレジスタオフセット(単位:バイト)}  */
	OFFSET(_KERNEL_RISCV_PROC_ICTX_STATUS, _kernel_riscv_ictx, status);


	/*
	 * %jp{タスクコンテキスト定義}
	 */
	/* %jp{タスクコンテキストサイズ(単位:バイト)}  */
	DEFINE_VAL(_KERNEL_RISCV_PROC_TSKCTX_SIZE,
	    sizeof(struct _kernel_riscv_tskswctx));

	/*  %jp{RAレジスタオフセット(単位:バイト)}  */
	OFFSET(_KERNEL_RISCV_PROC_TSKCTX_RA, _kernel_riscv_tskswctx, ra);

	/*
	 * %jp{S0-S11レジスタオフセット(単位:バイト)}
	 */
	OFFSET(_KERNEL_RISCV_PROC_TSKCTX_S0, _kernel_riscv_tskswctx, s0);
	OFFSET(_KERNEL_RISCV_PROC_TSKCTX_S1, _kernel_riscv_tskswctx, s1);
	OFFSET(_KERNEL_RISCV_PROC_TSKCTX_S2, _kernel_riscv_tskswctx, s2);
	OFFSET(_KERNEL_RISCV_PROC_TSKCTX_S3, _kernel_riscv_tskswctx, s3);
	OFFSET(_KERNEL_RISCV_PROC_TSKCTX_S4, _kernel_riscv_tskswctx, s4);
	OFFSET(_KERNEL_RISCV_PROC_TSKCTX_S5, _kernel_riscv_tskswctx, s5);
	OFFSET(_KERNEL_RISCV_PROC_TSKCTX_S6, _kernel_riscv_tskswctx, s6);
	OFFSET(_KERNEL_RISCV_PROC_TSKCTX_S7, _kernel_riscv_tskswctx, s7);
	OFFSET(_KERNEL_RISCV_PROC_TSKCTX_S8, _kernel_riscv_tskswctx, s8);
	OFFSET(_KERNEL_RISCV_PROC_TSKCTX_S9, _kernel_riscv_tskswctx, s9);
	OFFSET(_KERNEL_RISCV_PROC_TSKCTX_S10, _kernel_riscv_tskswctx, s10);
	OFFSET(_KERNEL_RISCV_PROC_TSKCTX_S11, _kernel_riscv_tskswctx, s11);

	/*  %jp{TPレジスタオフセット(単位:バイト)}  */
	OFFSET(_KERNEL_RISCV_PROC_TSKCTX_TP, _kernel_riscv_tskswctx, tp);

	return 0;
}



/* end of file */

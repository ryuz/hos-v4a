/* ------------------------------------------------------------------------ */
/* Hyper Operating System V4 Advance                                        */
/*                                                                          */
/*                                  Copyright (C) 1998-2006 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


				.text


/************************************************
 実行コンテキストの切替
 void _kernel_swi_ctx(
		_KERNEL_T_CTXCB *pk_ctxcb_nxt,			切り替え先のコンテキスト [r4]
		_KERNEL_T_CTXCB *pk_ctxcb_now)			現在のコンテキスト       [r5]
************************************************/
				.align	2
				.global	__kernel_swi_ctx
__kernel_swi_ctx:
				mov.l	r8, @-r15				/* レジスタを退避 */
				mov.l	r9, @-r15
				mov.l	r10, @-r15
				mov.l	r11, @-r15
				mov.l	r12, @-r15
				mov.l	r13, @-r15
				mov.l	r14, @-r15
				sts.l	macl, @-r15
				sts.l	mach, @-r15
				sts.l	pr, @-r15
				mov.l	r15, @(0, r5)			/* スタックポインタ保存 */
		/* ---- このまま _kernel_sta_ctx に続ける */

/************************************************
 実行コンテキストの開始
 void _kernel_sta_ctx(
		_KERNEL_T_CTXCB *pk_ctxcb)		開始するコンテキスト [r4]
************************************************/
				.global	__kernel_sta_ctx
__kernel_sta_ctx:
				mov.l	@(0, r4), r15			/* スタックポインタ復帰 */
				lds.l	@r15+, pr				/* r8-r14,prを復帰 */
				lds.l	@r15+, mach
				lds.l	@r15+, macl
				mov.l	@r15+, r14
				mov.l	@r15+, r13
				mov.l	@r15+, r12
				mov.l	@r15+, r11
				mov.l	@r15+, r10
				mov.l	@r15+, r9
				rts
				mov.l	@r15+, r8


				.end


/* end of file */

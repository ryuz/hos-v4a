/* ------------------------------------------------------------------------ */
/* Hyper Operating System V4 Advance                                        */
/*                                                                          */
/*                                  Copyright (C) 2011 by Project HOS       */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


				.text


/************************************************
 実行コンテキストの切替
 void _kernel_swi_ctx(
		_KERNEL_T_CTXCB *pk_ctxcb_nxt,			切り替え先のコンテキスト [r5]
		_KERNEL_T_CTXCB *pk_ctxcb_now)			現在のコンテキスト       [r6]
************************************************/
				.align	2
				.global	_kernel_swi_ctx
_kernel_swi_ctx:
				addik	r1, r1, -56
				swi		r15, r1, 0			/* 不揮発レジスタを退避 */
				swi		r19, r1, 4
				swi		r20, r1, 8
				swi		r21, r1, 12
				swi		r22, r1, 16
				swi		r23, r1, 20
				swi		r24, r1, 24
				swi		r25, r1, 28
				swi		r26, r1, 32
				swi		r27, r1, 36
				swi		r28, r1, 40
				swi		r29, r1, 44
				swi		r30, r1, 48
				swi		r31, r1, 52
				swi		r1, r6, 0			/* スタックポインタ保存 */
		/* ---- このまま _kernel_sta_ctx に続ける */

/************************************************
 実行コンテキストの開始
 void _kernel_sta_ctx(
		_KERNEL_T_CTXCB *pk_ctxcb)		開始するコンテキスト [r5]
************************************************/
				.global	_kernel_sta_ctx
_kernel_sta_ctx:
				lwi		r1, r5, 0
				lwi		r15, r1, 0			/* 不揮発レジスタを復帰 */
				lwi		r19, r1, 4
				lwi		r20, r1, 8
				lwi		r21, r1, 12
				lwi		r22, r1, 16
				lwi		r23, r1, 20
				lwi		r24, r1, 24
				lwi		r25, r1, 28
				lwi		r26, r1, 32
				lwi		r27, r1, 36
				lwi		r28, r1, 40
				lwi		r29, r1, 44
				lwi		r30, r1, 48
				lwi		r31, r1, 52
				rtsd	r15, 8
				addik	r1, r1, 56



/* end of file */

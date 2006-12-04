/* ------------------------------------------------------------------------ */
/* Hyper Operating System V4 Advance                                        */
/*                                                                          */
/*                                  Copyright (C) 1998-2006 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


				.h8300h



				.text



/************************************************
  実行コンテキストの切替
  void _kernel_swi_ctx(
		_KERNEL_T_CTXCB *pk_ctxcb_nxt,			切り替え先のコンテキスト [er0]
		_KERNEL_T_CTXCB *pk_ctxcb_now)			現在のコンテキスト       [er1]
************************************************/
				.global	__kernel_swi_ctx		/* 実行コンテキストの切替 */
__kernel_swi_ctx:
				push.l	er3
				push.l	er4
				push.l	er5
				push.l	er6
				mov.l	er7, @(0, er1)			/* スタックポインタ保存 */
		/* ---- このまま _kernel_sta_ctx に続ける ---- */

/************************************************
  実行コンテキストの開始
  void _kernel_sta_ctx(
		_KERNEL_T_CTXCB *pk_ctxcb)				開始するコンテキスト [er0]
************************************************/
				.global	__kernel_sta_ctx		/* 実行コンテキストの開始 */
__kernel_sta_ctx:
				mov.l	@(0, er0), er7			/* スタックポインタ復帰 */
				pop.l	er6
				pop.l	er5
				pop.l	er4
				pop.l	er3
				rts


				.end


/* end of file */

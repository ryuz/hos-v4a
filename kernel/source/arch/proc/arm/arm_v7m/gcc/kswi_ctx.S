/**
 *  Hyper Operating System V4 Advance
 *
 * Copyright (C) 1998-2011 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


				.syntax unified


				.text
				.align	2

/************************************************
  実行コンテキストの切替
  void _kernel_swi_ctx(
			_KERNEL_T_CTXCB *pk_ctxinf_nxt,	r0 : 切り替えるコンテキスト
			_KERNEL_T_CTXCB *pk_ctxinf_now)	r1 : 現在のコンテキストの保存先
 ************************************************/
				.global	_kernel_swi_ctx
				.thumb
				.thumb_func
				.type	_kernel_swi_ctx, %function
_kernel_swi_ctx:
				push	{r0, r4-r11, lr}		/* レジスタ保存(r0は8の倍数にするダミー) */
				mov		r4, sp
				str		r4, [r1]				/* スタックポインタ保存 */
		/* --- そのまま _kernel_sta_ctx に続ける */


/************************************************
  実行コンテキストの開始
  void _kernel_sta_ctx(
			_KERNEL_T_CTXCB *pk_ctxcb)		r0: 実行を開始するコンテキスト
 ************************************************/
				.global	_kernel_sta_ctx
				.thumb
				.thumb_func
				.type	_kernel_sta_ctx, %function
_kernel_sta_ctx:
				ldr		r4, [r0]				/* スタックポインタ復帰 */
				mov		sp, r4
				pop		{r0, r4-r11, pc}		/* レジスタ復帰 */

				.size	_kernel_swi_ctx, .-_kernel_swi_ctx
				.size	_kernel_sta_ctx, .-_kernel_sta_ctx



				.end


; end of file


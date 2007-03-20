/** 
 *  Hyper Operating System V4 Advance
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "arm_v4t.inc"


				.text
				.align	2

/************************************************
  実行コンテキストの切替
  void _kernel_swi_ctx(
			_KERNEL_T_CTXCB *pk_ctxinf_nxt,	r0 : 現在のコンテキストの保存先
			_KERNEL_T_CTXCB *pk_ctxinf_now)	r1 : 切り替えるコンテキスト
 ************************************************/
				.global	_kernel_swi_ctx
_kernel_swi_ctx:
				stmfd	sp!, {r4-r11, lr}			/* レジスタ保存 */
				str		sp, [r1]					/* スタックポインタ保存 */
		/* --- そのまま _kernel_sta_ctx に続ける */


/************************************************
  実行コンテキストの開始
  void _kernel_sta_ctx(
			_KERNEL_T_CTXCB *pk_ctxcb)		r0: 実行を開始するコンテキスト
 ************************************************/
				.global	_kernel_sta_ctx
_kernel_sta_ctx:
				ldr		sp, [r0]					/* スタックポインタ復帰 */
				ldmfd	sp!, {r4-r11, lr}			/* レジスタ復帰 */
				bx		lr

				.end


; end of file


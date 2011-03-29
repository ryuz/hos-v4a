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
  実行コンテキストのリスタート
  void _kernel_rst_ctx(
			VP_INT         par1,	r0 : 実行時パラメータ
			VP_INT         par2,	r1 : 実行時パラメータ
			FP             entry,	r2 : 実行アドレス
			VP             isp)		r3 : スタックポインタ
 ************************************************/
				.global	_kernel_rst_ctx
				.thumb
				.thumb_func
				.type	_kernel_rst_ctx, %function
_kernel_rst_ctx:
				mov		sp, r3		/* スタックを初期値にリセット */
				bx		r2			/* エントリーアドレスから再開始 */
				.size	_kernel_rst_ctx, .-_kernel_rst_ctx

				.end


/* end of file */

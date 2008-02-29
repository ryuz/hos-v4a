/****************************************************************************
  Hyper Operating System V4 Advance
  %jp{コンテキスト制御(MN1030シリーズ用}%en{MN1030}

  Copyright (C) 1998-2006 by Project HOS
  http://sourceforge.jp/projects/hos/
****************************************************************************/



				.text
				.align	2


/************************************************
  実行コンテキストのリスタート
  void _kernel_rst_ctx(
			VP_INT         par1,		実行時パラメータ     [d0]
			VP_INT         par2,		実行時パラメータ     [d1]
			FP             entry,		実行アドレス         [(12, sp)]
			VP             isp)			初期スタックポインタ [(16, sp)]
*************************************************/
				.global	__kernel_rst_ctx
 				.type	__kernel_rst_ctx, %function
__kernel_rst_ctx:
				mov		(12, sp), a0		/* 初期スタックポインタ取り出し */
				mov		(16, sp), a1		/* 実行アドレス取り出し */
				mov		a1, sp				/* スタックを初期値にリセット */
				jmp		(a0)				/* 実行アドレスから再開始 */
				.size	__kernel_rst_ctx, .-_kernel_rst_ctx




				.END


/* end of file */

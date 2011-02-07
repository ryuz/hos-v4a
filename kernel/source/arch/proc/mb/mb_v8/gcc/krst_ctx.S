/* ------------------------------------------------------------------------ */
/* Hyper Operating System V4 Advance                                        */
/*                                                                          */
/*                                  Copyright (C) 2011 by Project HOS       */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */



				.text

/************************************************
 実行コンテキストのリスタート
 void _kernel_rst_ctx(
		VP_INT par1,		実行時パラメータ1    [r5]
		VP_INT par2,		実行時パラメータ2    [r6]
		VP     isp,			初期スタックポインタ [r7]
		FP     entry)		実行アドレス         [r8]
************************************************/
				.align	2
				.global	_kernel_rst_ctx
_kernel_rst_ctx:
				brad	r8						/* 実行アドレスに分岐 */
				addik	r15, r7, 0				/* スタックポインタリセット(遅延スロット) */



/* end of file */

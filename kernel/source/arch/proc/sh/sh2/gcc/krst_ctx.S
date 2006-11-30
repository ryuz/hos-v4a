/* ------------------------------------------------------------------------ */
/* Hyper Operating System V4 Advance                                        */
/*                                                                          */
/*                                  Copyright (C) 1998-2006 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */



				.text

/************************************************
 実行コンテキストのリスタート
 void _kernel_rst_ctx(
		VP_INT par1,		実行時パラメータ1    [r4]
		VP_INT par2,		実行時パラメータ2    [r5]
		VP     isp,			初期スタックポインタ [r6]
		FP     entry)		実行アドレス         [r7]
************************************************/
				.align	2
				.global	__kernel_rst_ctx
__kernel_rst_ctx:
				jmp		@r7						/* 実行アドレスに分岐 */
				mov		r6, r15					/* スタックポインタリセット(遅延スロット) */


				.end


/* end of file */

/* ------------------------------------------------------------------------ */
/* Hyper Operating System V4 Advance                                        */
/*                                                                          */
/*                                  Copyright (C) 1998-2006 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


				.h8300h


				.text


/************************************************
 実行コンテキストのリスタート
 void _kernel_rst_ctx(
		VP_INT par1,							実行時パラメータ1    [er0]
		VP_INT par2,							実行時パラメータ2    [er1]
		VP     isp,								初期スタックポインタ [er2]
		FP     entry)							実行アドレス         [@(4, er7)]
************************************************/
				.global	__kernel_rst_ctx		/* 実行コンテキストのリスタート */
__kernel_rst_ctx:
				mov.l	@(4, er7), er3			/* 実行アドレス取り出し */
				mov.l	er2, er7				/* スタックポインタリセット */
				jmp		@er3					/* 実行アドレスに分岐 */


				.end


/* end of file */

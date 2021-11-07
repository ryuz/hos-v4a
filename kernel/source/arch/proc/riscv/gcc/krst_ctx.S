/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Advance                                       */
/*    RISC-V Architecture                                                   */
/*                                                                          */
/*                                  Copyright (C) 1998-2008 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */



				.text


/************************************************
  実行コンテキストのリスタート
  void _kernel_rst_ctx(
			VP_INT         par1,	[a0] : 実行時パラメータ
			VP_INT         par2,	[a1] : 実行時パラメータ
			FP             entry,	[a2] : 実行アドレス
			VP             isp)	[a3] : スタックポインタ
 ************************************************/
				.global	_kernel_rst_ctx

_kernel_rst_ctx:
				mv	sp, a3 	/* スタックを初期値にリセット */
				jr	a2      /* 実行アドレスから再開 */
/* end of file */

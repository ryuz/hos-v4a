/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Advance                                       */
/*    MIPS-I Architecture                                                   */
/*                                                                          */
/*                                  Copyright (C) 1998-2008 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */



				.text
				.set	noreorder


/************************************************
  実行コンテキストのリスタート
  void _kernel_rst_ctx(
			VP_INT         par1,	$4 [$a0] : 実行時パラメータ
			VP_INT         par2,	$5 [$a1] : 実行時パラメータ
			FP             entry,	$6 [$a2] : 実行アドレス
			VP             isp)		$7 [$a3] : スタックポインタ
 ************************************************/
				.global	_kernel_rst_ctx
				.ent	_kernel_rst_ctx
_kernel_rst_ctx:
				jr		$6			/* エントリーアドレスから再開始 */
				move	$sp, $7		/* スタックを初期値にリセット */

				.end	_kernel_rst_ctx


/* end of file */

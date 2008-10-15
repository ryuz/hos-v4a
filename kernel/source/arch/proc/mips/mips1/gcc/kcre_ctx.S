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
  実行コンテキストの作成
  void _kernel_cre_ctx(
			_KERNEL_T_CTXCB *pk_ctxcb,	$4 [$a0]   : 作成するコンテキスト
			VP             isp,			$5 [$a1]   : スタックポインタ
			FP             entry,		$6 [$a2]   : 実行アドレス
			VP_INT         par1,		$7 [$a3]   : 実行時パラメータ1
			VP_INT         par2)		16($sp)    : 実行時パラメータ2
 ************************************************/
				.global	_kernel_cre_ctx
				.ent	_kernel_cre_ctx
_kernel_cre_ctx:
				addiu	$5, $5, -40
				sw		$5, 0($4)
				
				lw		$8, 16($sp)
				sw		$7, 0($5)		/* $s0 = 実行時パラメータ1 */
				sw		$8, 4($5)		/* $s1 = 実行時パラメータ2 */
				sw		$6, 8($5)		/* $s2 = 実行アドレス */
				la		$8, ctx_entry
				jr		$ra
				sw		$8, 36($5)		/* $ra = エントリーアドレス */


/************************************************
  実行コンテキストエントリーアドレス
 ************************************************/
ctx_entry:
				move	$4, $16			/* $s0 : 実行時パラメータ1 */
				jr		$18
				move	$5, $17			/* $s0 : 実行時パラメータ1 */


				.end	_kernel_cre_ctx


/* end of file */

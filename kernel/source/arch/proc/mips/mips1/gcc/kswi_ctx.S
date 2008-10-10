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
  実行コンテキストの切替
  void _kernel_swi_ctx(
			_KERNEL_T_CTXCB *pk_ctxinf_nxt,	$4($a0) : 現在のコンテキストの保存先
			_KERNEL_T_CTXCB *pk_ctxinf_now)	$5($a1) : 切り替えるコンテキスト
 ************************************************/
				.global	_kernel_swi_ctx
				.ent	_kernel_swi_ctx
_kernel_swi_ctx:
				addiu	$sp, -40
				sw		$16, 0($sp)		/* $s0 */
				sw		$17, 4($sp)		/* $s1 */
				sw		$18, 8($sp)		/* $s2 */
				sw		$19, 12($sp)	/* $s3 */
				sw		$20, 16($sp)	/* $s4 */
				sw		$21, 20($sp)	/* $s5 */
				sw		$22, 24($sp)	/* $s6 */
				sw		$23, 28($sp)	/* $s7 */
				sw		$fp, 32($sp)
				sw		$ra, 36($sp)
				
				sw		$sp, 0($5)		/* sp保存 */
		/* --- そのまま _kernel_sta_ctx に続ける */

/************************************************
  実行コンテキストの開始
  void _kernel_sta_ctx(
			_KERNEL_T_CTXCB *pk_ctxcb)		$4($a0) : 実行を開始するコンテキスト
 ************************************************/
				.global	_kernel_sta_ctx
_kernel_sta_ctx:
				lw		$sp, 0($4)		/* sp復帰 */
				nop
				
				lw		$ra, 36($sp)
				lw		$fp, 32($sp)
				lw		$23, 28($sp)	/* $s7 */
				lw		$22, 24($sp)	/* $s6 */
				lw		$21, 20($sp)	/* $s5 */
				lw		$20, 16($sp)	/* $s4 */
				lw		$19, 12($sp)	/* $s3 */
				lw		$18, 8($sp)		/* $s2 */
				lw		$17, 4($sp)		/* $s1 */
				lw		$16, 0($sp)		/* $s0 */

				jr		$ra
				addiu	$sp, 40
				
				
				.end	_kernel_swi_ctx


/* end of file */

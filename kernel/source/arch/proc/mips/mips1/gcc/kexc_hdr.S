/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Advance                                       */
/*    MIPS-I Architecture                                                   */
/*                                                                          */
/*                                  Copyright (C) 1998-2008 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */



				.global	_kernel_ictxcb
				.global	_kernel_sta_inh
				.global	_kernel_end_inh
				.global	_kernel_exe_inh


				.text
				.set	noreorder
				.set	noat


/************************************************
   例外処理ハンドラ
 ************************************************/
				.global	_kernel_exc_hdr
				.ent	_kernel_exc_hdr
_kernel_exc_hdr:
			/* %jp{レジスタ退避}%en{register save} */
				addiu	$sp, -84
				sw		$1, 0($sp)
				sw		$2, 4($sp)
				sw		$3, 8($sp)
				sw		$4, 12($sp)
				sw		$5, 16($sp)
				sw		$6, 20($sp)
				sw		$7, 24($sp)
				sw		$8, 28($sp)
				sw		$9, 32($sp)
				sw		$10, 36($sp)
				sw		$11, 40($sp)
				sw		$12, 44($sp)
				sw		$13, 48($sp)
				sw		$14, 52($sp)
				sw		$15, 56($sp)
				sw		$24, 60($sp)
				sw		$25, 64($sp)
				sw		$ra, 68($sp)
				mfhi	$8
				mflo	$9
				mfc0	$10, $14			/* EPC */ 
				sw		$8, 72($sp)
				sw		$9, 76($sp)
				la		$26, _kernel_ictxcb
				lbu		$27, 0($26)
				sw		$10, 80($sp)
				
			/* %jp{多重割込み判定} */
				bne		$0, $27, multiple_int
				addiu	$27, 1
				sb		$27, 0($26)
				
			/* %jp{スタック入れ替え} */
				move	$27, $sp
				lw		$sp, 4($26)
				nop
				add		$sp, -4
				sw		$27, 0($sp)
				
			/* %jp{割込み開始処理} */
				jal		_kernel_sta_inh
				sw		$10, 76($sp)
				
			/* %jp{割込みハンドラ実行} */
				la		$4, 0
				jal		_kernel_exe_inh
				nop
				
			/* %jp{スタック復帰} */
				lw		$sp, 0($sp)
				la		$26, _kernel_ictxcb
				sb		$0, 0($26)
				
				
			/* %jp{割込み終了処理} */
				jal		_kernel_end_inh
				nop
				
				
ret_exc_hdr:
				mfc0	$26, $12			/* STATUS */ 
				ori		$26, $26, 0x04
				mtc0	$26, $12
				
				lw		$8, 72($sp)
				lw		$9, 76($sp)
				lw		$26, 80($sp)		/* EPC */ 
				mthi	$8
				mtlo	$9
				lw		$1, 0($sp)
				lw		$2, 4($sp)
				lw		$3, 8($sp)
				lw		$4, 12($sp)
				lw		$5, 16($sp)
				lw		$6, 20($sp)
				lw		$7, 24($sp)
				lw		$8, 28($sp)
				lw		$9, 32($sp)
				lw		$10, 36($sp)
				lw		$11, 40($sp)
				lw		$12, 44($sp)
				lw		$13, 48($sp)
				lw		$14, 52($sp)
				lw		$15, 56($sp)
				lw		$24, 60($sp)
				lw		$25, 64($sp)
				lw		$ra, 68($sp)
				addiu	$sp, 84
				jr		$26
				rfe


multiple_int:	
				sb		$27, 0($26)
				
			/* %jp{割込みハンドラ実行} */
				la		$4, 0
				jal		_kernel_exe_inh
				nop
				
				j		ret_exc_hdr
				
				
				.end	_kernel_exc_hdr


/* end of file */

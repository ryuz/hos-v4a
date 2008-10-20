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


/************************************************
   例外処理ハンドラ
 ************************************************/
				.global	_kernel_exc_hdr
				.ent	_kernel_exc_hdr
_kernel_exc_hdr:
			/* %jp{レジスタ退避}%en{register save} */
				addiu	$sp, -80
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
				mfhi	$8
				mflo	$9
				mfc0	$10, $14				/* EPC */ 
				sw		$8, 68($sp)
				sw		$9, 72($sp)
				sw		$10, 76($sp)
				
				jal		_kernel_sta_inh			/* %jp{割込み開始処理} */
				sw		$10, 76($sp)
				
				
				la		a0, 0
				jal		_kernel_exe_inh			/* %jp{割込みハンドラ実行} */
				nop
				
				
				jal		_kernel_end_inh			/* %jp{割込み終了処理} */
				nop
				
				
				mfc0	$26, $12		/* STATUS */ 
				ori		$26, $26, 0x04
				mtc0	$26, $12
				
				lw		$8, 68($sp)
				lw		$9, 72($sp)
				lw		$26, 76($sp)	/* EPC */ 
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
				addiu	$sp, 80
				jr		$26
				rfe
				
				
				.end	_kernel_exc_hdr


/* end of file */

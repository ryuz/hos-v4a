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
   割り込み禁止
   void _kernel_dis_int(void)
 ************************************************/
				.global	_kernel_dis_int
				.ent	_kernel_dis_int
_kernel_dis_int:
				mfc0	$8, $12				/* CP_0STATUS */
				la		$9, 0xf1fffff8		/* ERL=0, IE=0, EXL=0 */
				and		$8, $8, $9
				mtc0	$8, $12				/* CP0レジスタをストア */
				nop
				jr      $ra
				nop
				
				
				.end	_kernel_dis_int


/* end of file */

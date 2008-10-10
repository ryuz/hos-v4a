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
  割り込み許可
  void _kernel_ena_int(void)
 ************************************************/
				.global	_kernel_ena_int
				.ent	_kernel_ena_int
_kernel_ena_int:
				mfc0	$8, $12				/* CP0_STATUS */
				la		$9, 0xf1fffffb		/* ERL=0 */
				and		$8, $8, $9
				ori		$8, $8, 1			/* IE=1 */
				mtc0	$8, $12
				nop
				jr		$ra
				nop

				.end	_kernel_ena_int


/* end of file */

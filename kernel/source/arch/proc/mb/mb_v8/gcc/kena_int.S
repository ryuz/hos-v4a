/* ------------------------------------------------------------------------ */
/* Hyper Operating System V4 Advance                                        */
/*                                                                          */
/*                                  Copyright (C) 2011 by Project HOS       */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */



				.text


/************************************************
  割り込み許可
  void _kernel_ena_int(void)
 ************************************************/
				.align	2
				.global	_kernel_ena_int
_kernel_ena_int:
				mfs		r3, rmsr
				ori		r3, r3, 2
				mts		rmsr, r3
				rtsd	r15, 8
				nop


/* end of file */

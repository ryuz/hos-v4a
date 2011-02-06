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
				rtsd	r15, 8
				msrset	r3, 0x2000


/* end of file */

/* ------------------------------------------------------------------------ */
/* Hyper Operating System V4 Advance                                        */
/*                                                                          */
/*                                  Copyright (C) 1998-2006 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */



				.text


/************************************************
  割り込み禁止
  void _kernel_dis_int(void)
 ************************************************/
				.align	2
				.global	_kernel_dis_int
_kernel_dis_int:
				rtsd	r15, 8
				msrclr	r3, 0x2000



/* end of file */

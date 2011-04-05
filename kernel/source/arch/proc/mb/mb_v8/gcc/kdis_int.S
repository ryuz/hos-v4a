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
				mfs		r3, rmsr
				andi	r3, r3, -3
				mts		rmsr, r3
				rtsd	r15, 8
				nop



/* end of file */

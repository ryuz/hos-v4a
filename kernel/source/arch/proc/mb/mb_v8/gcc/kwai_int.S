/* ------------------------------------------------------------------------ */
/* Hyper Operating System V4 Advance                                        */
/*                                                                          */
/*                                  Copyright (C) 1998-2006 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */



				.text


/************************************************
 割り込み待ち
 void _kernel_wai_int(void)
************************************************/
				.align	2
				.global	_kernel_wai_int
_kernel_wai_int:
				bri		_kernel_wai_int
				nop


/* end of file */

/* ------------------------------------------------------------------------ */
/* Hyper Operating System V4 Advance                                        */
/*                                                                          */
/*                                  Copyright (C) 1998-2011 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


				.global	_kernel_brk_hdr


				.text


/************************************************
  Breakハンドラ
************************************************/
				.align	2
_kernel_brk_hdr:
				bri		_kernel_brk_hdr


/* end of file */

/* ------------------------------------------------------------------------ */
/* Hyper Operating System V4 Advance                                        */
/*                                                                          */
/*                                  Copyright (C) 1998-2011 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


				.global	_kernel_hwe_hdr


				.text


/************************************************
  ハードウェア例外ハンドラ
************************************************/
				.align	2
_kernel_hwe_hdr:
				bri		_kernel_hwe_hdr


/* end of file */

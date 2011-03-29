/** 
 *  Hyper Operating System V4 Advance
 *
 * Copyright (C) 1998-2011 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


				.syntax unified


				.text
				.align	2

/************************************************
  割り込み待ち(CPUのアイドル処理)
  void 	_kernel_wai_int(void);
 ************************************************/
				.global	_kernel_wai_int
				.thumb
				.thumb_func
				.type	_kernel_wai_int, %function
_kernel_wai_int:
											/* WaitForInterrupt */
				b		_kernel_wai_int
				.size	_kernel_wai_int, .-_kernel_wai_int


				.end


/* end of file */

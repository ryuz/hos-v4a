/** 
 *  Hyper Operating System V4 Advance
 *
 * Copyright (C) 1998-2011 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



				.text
				.align	2

/************************************************
  割り込み許可
  void _kernel_ena_int(void)
 ************************************************/
				.global	_kernel_ena_int
				.code	16
				.thumb_func
				.type	_kernel_ena_int, %function
_kernel_ena_int:
				cpsie	i			/* 割り込み許可 */
				bx		lr			/* リターン */
				.size	_kernel_ena_int, .-_kernel_ena_int


				.end


/* end of file */

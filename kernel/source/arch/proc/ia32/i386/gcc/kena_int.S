/** 
 *  Hyper Operating System V4 Advance
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



				.code32
				.text
				.align	2

/************************************************
  割り込み許可
  void _kernel_ena_int(void)
 ************************************************/
				.global	__kernel_ena_int
__kernel_ena_int:
				sti			/* 割込み許可 */
				ret


				.end


/* end of file */

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
   割り込み禁止
   void _kernel_dis_int(void)
 ************************************************/
				.global	_kernel_dis_int
				.thumb
				.thumb_func
				.type	_kernel_dis_int, %function
_kernel_dis_int:
				cpsid	i			/* 割り込み禁止 */
				bx		lr			/* リターン */
				.size	_kernel_dis_int, .-_kernel_dis_int

				.end


/* end of file */

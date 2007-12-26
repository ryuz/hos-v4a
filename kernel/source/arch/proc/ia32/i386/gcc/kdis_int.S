/** 
 *  Hyper Operating System V4 Advance
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



				.code32
				.text
				.align	2

/************************************************
   割り込み禁止
   void _kernel_dis_int(void)
 ************************************************/
				.global	_kernel_dis_int
_kernel_dis_int:
				cli			/* 割込み禁止 */
				ret


				.end


/* end of file */

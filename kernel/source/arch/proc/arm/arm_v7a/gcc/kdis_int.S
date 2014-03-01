/** 
 *  Hyper Operating System V4 Advance
 *
 * Copyright (C) 1998-2014 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "arm_v7a.inc"


				.text
				.align	2

/************************************************
   割り込み禁止
   void _kernel_dis_int(void)
 ************************************************/
				.global	_kernel_dis_int
_kernel_dis_int:
				cpsid	fi			/* 割り込み禁止 */
				bx		lr			/* リターン */


				.end


/* end of file */

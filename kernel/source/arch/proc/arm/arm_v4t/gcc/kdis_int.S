/** 
 *  Hyper Operating System V4 Advance
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "arm_v4t.inc"


				.text
				.align	2

/************************************************
   割り込み禁止
   void _kernel_dis_int(void)
 ************************************************/
				.global	_kernel_dis_int
 				.type	_kernel_dis_int, %function
_kernel_dis_int:
				mrs 	r0, cpsr					/*  cpsr取得 */
				orr		r0, r0, #(F_Bit | I_Bit)	/*  FビットとIビットを設定 */
				msr 	cpsr_c, r0					/*  cpsr設定 */
				bx		lr							/*  リターン */
				.size	_kernel_dis_int, .-_kernel_dis_int


				.end


/* end of file */

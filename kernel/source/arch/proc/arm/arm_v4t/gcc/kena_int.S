/** 
 *  Hyper Operating System V4 Advance
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "arm_v4t.inc"

				.code	32
				.text
				.align	2

/************************************************
  割り込み許可
  void _kernel_ena_int(void)
 ************************************************/
				.global	_kernel_ena_int
_kernel_ena_int:
				ldr		r1, =_kernel_ictxcb
				mrs 	r0, cpsr					/* cpsr取得 */
				ldrb	r1, [r1, #ICTXCB_IMSK]		/* 割込みマスク値取得 */
				bic		r0, r0, #(F_Bit | I_Bit)	/* FビットとIビットをクリア */
				orr		r0, r0, r1					/* 割込みマスク設定 */
				msr 	cpsr_c, r0					/* cpsr設定 */
				bx		lr							/* リターン */


				.end


/* end of file */

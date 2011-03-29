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
  CONTROLレジスタの取得
  int _kernel_ref_cpu_control(void)
 ************************************************/
				.global	_kernel_ref_cpu_control
				.thumb
				.thumb_func
				.type	_kernel_ref_cpu_control, %function
_kernel_ref_cpu_control:
				mrs		r0, CONTROL
				bx		lr
				.size	_kernel_ref_cpu_control, .-_kernel_ref_cpu_control

				.end


/* end of file */

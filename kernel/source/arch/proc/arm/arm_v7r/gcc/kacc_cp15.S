/** 
 *  Hyper Operating System V4 Advance
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "arm_v7r.inc"


				.text
				.align	2

/* Memory Barrier */
				.global	_kernel_arm_isb
				.code	16
				.thumb_func
				.type	_kernel_arm_isb, %function
_kernel_arm_isb:
				isb				/* そもそも分岐で呼び出してる時点で意味なしだがインライン機能のないコンパイラ用に一応作っておく */
				bx		lr

				.global	_kernel_arm_dsb
				.code	16
				.thumb_func
				.type	_kernel_arm_dsb, %function
_kernel_arm_dsb:
				dsb
				bx		lr


/* SCTLR CP15 Control Register */
				.global	_kernel_write_cp15_c1_c0_0
				.code	16
				.thumb_func
				.type	_kernel_write_cp15_c1_c0_0, %function
_kernel_write_cp15_c1_c0_0:
				dsb
				mcr		p15, 0, r0, c1, c0, 0
				isb
				bx		lr
				
				.global	_kernel_read_cp15_c1_c0_0
				.code	16
				.thumb_func
				.type	_kernel_read_cp15_c1_c0_0, %function
_kernel_read_cp15_c1_c0_0:
				mrc		p15, 0, r0, c1, c0, 0
				bx		lr


/* ACTLR */
				.global	_kernel_read_cp15_c1_c0_1
				.code	16
				.thumb_func
				.type	_kernel_read_cp15_c1_c0_1, %function
_kernel_write_cp15_c1_c0_1:
				mcr		p15, 0, r0, c1, c0, 1
				dsb
				bx		lr
				
				.global	_kernel_read_cp15_c1_c0_1
				.code	16
				.thumb_func
				.type	_kernel_read_cp15_c1_c0_1, %function
_kernel_read_cp15_c1_c0_1:
				mrc		p15, 0, r0, c1, c0, 1
				bx		lr


/* MPU Type Register */
				.global	_kernel_read_cp15_c0_c0_4
				.code	16
				.thumb_func
				.type	_kernel_read_cp15_c0_c0_4, %function
_kernel_read_cp15_c0_c0_4:
				mrc		p15, 0, r0, c0, c0, 4
				bx		lr


/* MPU Region Size and Enable Registers */
				.global	_kernel_write_cp15_c6_c1_0
				.code	16
				.thumb_func
				.type	_kernel_write_cp15_c6_c1_0, %function
_kernel_write_cp15_c6_c1_0:
				mcr     p15, 0, r0, c6, c1, 0
				bx		lr

				.global	_kernel_read_cp15_c6_c1_0
				.code	16
				.thumb_func
				.type	_kernel_read_cp15_c6_c1_0, %function
_kernel_read_cp15_c6_c1_0:
				mrc     p15, 0, r0, c6, c1, 0
				bx		lr


/* MPU Region Number Register */
				.global	_kernel_write_cp15_c6_c2_0
				.code	16
				.thumb_func
				.type	_kernel_write_cp15_c6_c2_0, %function
_kernel_write_cp15_c6_c2_0:
				mcr     p15, 0, r0, c6, c2, 0
				bx		lr

				.global	_kernel_read_cp15_c6_c2_0
				.code	16
				.thumb_func
				.type	_kernel_read_cp15_c6_c2_0, %function
_kernel_read_cp15_c6_c2_0:
				mrc     p15, 0, r0, c6, c2, 0
				bx		lr


/* MPU Region Access Control Register */
				.global	_kernel_write_cp15_c6_c1_4
				.code	16
				.thumb_func
				.type	_kernel_write_cp15_c6_c1_4, %function
_kernel_write_cp15_c6_c1_4:
				mcr     p15, 0, r0, c6, c1, 4
				bx		lr

				.global	_kernel_read_cp15_c6_c1_4
				.code	16
				.thumb_func
				.type	_kernel_read_cp15_c6_c1_4, %function
_kernel_read_cp15_c6_c1_4:
				mrc     p15, 0, r0, c6, c2, 0
				bx		lr


/* Data MPU Region Size and Enable Register */
				.global	_kernel_write_cp15_c6_c1_2
				.code	16
				.thumb_func
				.type	_kernel_write_cp15_c6_c1_2, %function
_kernel_write_cp15_c6_c1_2:
				mcr     p15, 0, r0, c6, c1, 2
				bx		lr

				.global	_kernel_read_cp15_c6_c1_2
				.code	16
				.thumb_func
				.type	_kernel_read_cp15_c6_c1_2, %function
_kernel_read_cp15_c6_c1_2:
				mrc     p15, 0, r0, c6, c2, 0
				bx		lr


/* end of file */

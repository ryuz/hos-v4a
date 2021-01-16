/** 
 *  Hyper Operating System V4 Advance
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "arm_v7r.inc"


				.text
				.align	2


/* MPU Type Register */
				.global	_kernel_ref_cp15c0c0_4
				.code	16
				.thumb_func
				.type	_kernel_ref_cp15c0c0_4, %function
_kernel_ref_cp15c0c0_4:
				mrc		p15, 0, r0, c0, c0, 4
				bx		lr


/* c6, MPU Region Size and Enable Registers */
				.global	_kernel_chg_cp15c6c1_0
				.code	16
				.thumb_func
				.type	_kernel_chg_cp15c6c1_0, %function
_kernel_chg_cp15c6c1_0:
				mcr     p15, 0, r0, c6, c1, 0
				bx		lr

				.global	_kernel_ref_cp15c6c1_0
				.code	16
				.thumb_func
				.type	_kernel_ref_cp15c6c1_0, %function
_kernel_ref_cp15c6c1_0:
				mrc     p15, 0, r0, c6, c1, 0
				bx		lr


/* c6, MPU Region Number Register */
				.global	_kernel_chg_cp15c6c2_0
				.code	16
				.thumb_func
				.type	_kernel_chg_cp15c6c2_0, %function
_kernel_chg_cp15c6c2_0:
				mcr     p15, 0, r0, c6, c2, 0
				bx		lr

				.global	_kernel_ref_cp15c6c2_0
				.code	16
				.thumb_func
				.type	_kernel_ref_cp15c6c2_0, %function
_kernel_ref_cp15c6c2_0:
				mrc     p15, 0, r0, c6, c2, 0
				bx		lr


/* MPU Region Access Control Register */
				.global	_kernel_chg_cp15c6c1_4
				.code	16
				.thumb_func
				.type	_kernel_chg_cp15c6c1_4, %function
_kernel_chg_cp15c6c1_4:
				mcr     p15, 0, r0, c6, c1, 4
				bx		lr

				.global	_kernel_ref_cp15c6c1_4
				.code	16
				.thumb_func
				.type	_kernel_ref_cp15c6c1_4, %function
_kernel_ref_cp15c6c1_4:
				mrc     p15, 0, r0, c6, c2, 0
				bx		lr


/* Data MPU Region Size and Enable Register */
				.global	_kernel_chg_cp15c6c1_2
				.code	16
				.thumb_func
				.type	_kernel_chg_cp15c6c1_2, %function
_kernel_chg_cp15c6c1_2:
				mcr     p15, 0, r0, c6, c1, 2
				bx		lr

				.global	_kernel_ref_cp15c6c1_2
				.code	16
				.thumb_func
				.type	_kernel_ref_cp15c6c1_2, %function
_kernel_ref_cp15c6c1_2:
				mrc     p15, 0, r0, c6, c2, 0
				bx		lr


/* end of file */

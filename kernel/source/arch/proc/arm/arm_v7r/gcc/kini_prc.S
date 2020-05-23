/** 
 *  Hyper Operating System V4 Advance
 *
 * Copyright (C) 1998-2020 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "arm_v7r.inc"


				.code	32
				.text
				.align	2


/************************************************
  initialize processor
 ************************************************/
				.global	_kernel_ini_prc
_kernel_ini_prc:
#ifdef _KERNEL_ARM_WITH_VFP
				mrc		p15, 0, r0, c1, c0, 2	/* CP アクセスレジスタを読み込む */
				orr		r0, r0, #0x00f00000		/* NEON/VFP（コプロセッサ 10 および 11）へのフルアクセス権を有効にする */
				mcr		p15, 0, r0, c1, c0, 2	/* CP アクセスレジスタを書き込む */
				isb
				mov 	r0, #0x40000000			/* VFP および NEON ハードウェアをオンにする */
 				vmsr 	fpexc, r0				/* FPEXC の EN ビットを設定する */
#endif
				bx		lr						/* リターン */

				.end


/* end of file */

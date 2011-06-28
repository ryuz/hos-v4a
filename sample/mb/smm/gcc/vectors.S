/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4  サンプルプログラム                           */
/*    ベクタテーブル                                                        */
/*                                                                          */
/*                                  Copyright (C) 1998-2011 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


		/* --- 外部定数宣言 */
				.global	_reset_handler
				.global	_kernel_exc_hdr
				.global	_kernel_int_hdr
				.global	_kernel_brk_hdr
				.global	_kernel_hwe_hdr


				.align	2

/* --------------------------------------- */
/*            ベクタ定義                   */
/* --------------------------------------- */

				.section	.vectors.reset, "ax"
				brai	_reset_handler

				.section	.vectors.sw_exception, "ax"
				bri		_kernel_exc_hdr

				.section	.vectors.interrupt, "ax"
				bri		_kernel_int_hdr

				.section	.vectors.hw_exception, "ax"
				bri		_kernel_hwe_hdr



/* end of file */

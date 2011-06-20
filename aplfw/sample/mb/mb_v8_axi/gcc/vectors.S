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


				.text
				.align	2

/* --------------------------------------- */
/*            ベクタ定義                   */
/* --------------------------------------- */
				bri		_reset_handler
				nop
				bri		_kernel_exc_hdr
				nop
				bri		_kernel_int_hdr
				nop
				bri		_kernel_brk_hdr
				nop
				bri		_kernel_hwe_hdr



/* end of file */

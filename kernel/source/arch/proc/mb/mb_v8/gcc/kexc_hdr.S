/* ------------------------------------------------------------------------ */
/* Hyper Operating System V4 Advance                                        */
/*                                                                          */
/*                                  Copyright (C) 1998-2011 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */

/*  %jp{例外番号マスク}                 */
#define ESR_EXC_MASK            0x0000001F

				.global	_kernel_exc_hdr
				.global	_kernel_exe_exc


				.text


/************************************************
  CPU例外ハンドラ
************************************************/
				.align	2
_kernel_exc_hdr:
		/* ---- レジスタ保存 */
				addik	r1, r1, -44
				swi		r15, r1, 0
				swi		r3, r1, 4
				swi		r4, r1, 8
				swi		r5, r1, 12
				swi		r6, r1, 16
				swi		r7, r1, 20
				swi		r8, r1, 24
				swi		r9, r1, 28
				swi		r10, r1, 32
				swi		r11, r1, 36
				swi		r12, r1, 40

		/* ---- %jp{例外番号を第1引数(r5)に設定} */
				mfs		r5, resr
				andi	r5, r5, ESR_EXC_MASK;

		/* ---- %jp{拡張情報(例外コンテキスト)を第2引数(r6)に設定} */
				addik   r6, r1, 0

		/* ---- %jp{例外ハンドラ実行, r5:例外番号, r6:拡張情報(例外コンテキスト)} */
				brlid	r15, _kernel_exe_exh
				addik	r3, r0, 0

		/* ---- レジスタ復帰 */
				lwi		r15, r1, 0
				lwi		r3, r1, 4
				lwi		r4, r1, 8
				lwi		r5, r1, 12
				lwi		r6, r1, 16
				lwi		r7, r1, 20
				lwi		r8, r1, 24
				lwi		r9, r1, 28
				lwi		r10, r1, 32
				lwi		r11, r1, 36
				lwi		r12, r1, 40
				rted	r17, 0
				addik	r1, r1, 44



/* end of file */

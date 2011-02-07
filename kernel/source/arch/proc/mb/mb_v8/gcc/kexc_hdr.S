/* ------------------------------------------------------------------------ */
/* Hyper Operating System V4 Advance                                        */
/*                                                                          */
/*                                  Copyright (C) 1998-2011 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


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
				
				
		/* ---- 例外処理実行処理呼び出し */
				brlid	r15, _kernel_exe_exc
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

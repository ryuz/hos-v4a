/* ------------------------------------------------------------------------ */
/* Hyper Operating System V4 Advance                                        */
/*                                                                          */
/*                                  Copyright (C) 1998-2011 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */

				.global	_kernel_int_hdr
				.global	_kernel_ictxcb
				.global	_kernel_sta_inh
				.global	_kernel_exe_inh
				.global	_kernel_end_inh


				.text


#define ICTXCB_ISP		0


/************************************************
  割込みハンドラ
 ************************************************/
				.align	2
_kernel_int_hdr:
		/* ---- レジスタ保存 */
				addik	r1, r1, -80
				swi		r14, r1, 0
				swi		r3, r1, 28
				swi		r4, r1, 32
				swi		r5, r1, 36
				swi		r6, r1, 40
				swi		r7, r1, 44
				swi		r8, r1, 48
				swi		r9, r1, 52
				swi		r10, r1, 56
				swi		r11, r1, 60
				swi		r12, r1, 64
				swi		r15, r1, 68
				swi		r18, r1, 72
				mfs		r3, rmsr
				swi		r3, r1, 76
				
		/* ---- スタック入れ替え */
				addik	r3, r1, 0
				addik	r4, r0, _kernel_ictxcb
				lwi		r1, r4, ICTXCB_ISP
				
		/* ---- 割り込み開始処理呼び出し */
				addik	r1, r1, -32
				brlid	r15, _kernel_sta_inh
				swi		r3, r1, 28					/* 旧スタックポインタ保存 */
				
		/* ---- 割り込み実行処理呼び出し */
				brlid	r15, _kernel_exe_inh
				addik	r5, r0, 0
				
				
		/* ---- 割込み終了処理呼び出し */
				brlid	r15, _kernel_end_inh
				lwi		r1, r1, 28					/* スタックの復帰 */
				
		/* ---- レジスタ復帰 */
				lwi		r3, r1, 76
				mts		rmsr, r3
				lwi		r14, r1, 0
				lwi		r3, r1, 28
				lwi		r4, r1, 32
				lwi		r5, r1, 36
				lwi		r6, r1, 40
				lwi		r7, r1, 44
				lwi		r8, r1, 48
				lwi		r9, r1, 52
				lwi		r10, r1, 56
				lwi		r11, r1, 60
				lwi		r12, r1, 64
				lwi		r15, r1, 68
				lwi		r18, r1, 72
 				rtid	r14, 0
				addik	r1, r1, 80


/* end of file */

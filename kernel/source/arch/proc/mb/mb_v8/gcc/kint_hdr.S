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
#define ICTXCB_INTCNT	4
#define ICTXCB_IMSK		6


/************************************************
  割込みハンドラ
 ************************************************/
				.align	2
_kernel_int_hdr:
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
				
		/* ---- スタック入れ替え */
				addik	r3, r1, 0
				addik	r4, r0, _kernel_ictxcb
				lwi		r1, r4, ICTXCB_ISP
				
		/* ---- 割り込み開始処理呼び出し */
				addik	r1, r1, -4
				brlid	r15, _kernel_sta_inh
				swi		r3, r1, 0					/* 旧スタックポインタ保存 */
				
		/* ---- 割り込み実行処理呼び出し */
				brlid	r15, _kernel_exe_inh
				addik	r3, r0, 0
				
				
		/* ---- 割込み終了処理呼び出し */
				brlid	r15, _kernel_end_inh
				lwi		r1, r1, 0					/* スタックの復帰 */
				
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
				rtid	r14, 0
				addik	r1, r1, 44


/* end of file */

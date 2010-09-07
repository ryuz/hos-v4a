/****************************************************************************
  Hyper Operating System V4 Advance
  %jp{割り込みハンドラ(MN1030シリーズ用}%en{MN1030}

  Copyright (C) 1998-2007 by Project HOS
  http://sourceforge.jp/projects/hos/
****************************************************************************/


				.global	__kernel_int_hdr
				.global	__kernel_ictxcb
				.global	__kernel_sta_inh
				.global	__kernel_end_inh
				.global	__kernel_exe_inh


				.text
				.align	2


/************************************************
  Interrupt Handler
 ************************************************/
__kernel_int_hdr:
			/* ---- レジスタ退避 ---- */
				movm	[other], (sp)							/* レジスタ退避 */
				add		-8, sp
				
			/* ---- 多重割込み判定 ---- */
				mov		__kernel_ictxcb, a0
				movbu	(4, a0), d0
				add		1, d0
				movbu	d0, (4, a0)
				cmp		1, d0
				bne		multiple_int
				
			/* ---- 割り込み用スタックに入れ替え ---- */
				mov		(0, a0), a1
				mov		sp, a0									/* タスクのSPを保存 */
				mov		a1, sp
				add		-16, sp
				mov		a0, (12, sp)
				
			/* ---- 割り込み処理 ---- */
				call	__kernel_sta_inh, [], 0					/* 割り込み開始 */
				
			/* ---- 割り込みハンドラ実行 ---- */
				clr		d0
				call	__kernel_exe_inh, [], 0
				
			/* ---- 割り込み処理の終了設定 ---- */
				mov		(12, sp), a0
				clr		d0
				movbu	d0, (__kernel_ictxcb+4)					/* ネストカウンタクリア */
				mov		a0, sp									/* スタック復帰 */
				
			/* ---- 割込みマスクレベルの復帰 ---- */
				mov		(40, sp), d0
				and		0x0700, d0
				mov		d0, psw
				
			/* ---- 遅延ディスパッチ処理 ---- */
				call	__kernel_end_inh, [], 0					/* 割り込み終了処理 */
				
			/* ---- 復帰処理 ---- */
return_int:
				add		8, sp
				movm	(sp), [other]							/* レジスタ退避 */
				rti

			/* ---- 多重割り込み処理 ---- */
multiple_int:
			/* ---- 割り込みハンドラ実行 ---- */
				clr		d0
				call	__kernel_exe_inh, [], 0
				
			/* ---- 割り込みカウンタ復帰 ---- */
				movbu	(__kernel_ictxcb+4), d0
				add		-1, d0
				movbu	d0, (__kernel_ictxcb+4)
				
				bra		return_int								/* 復帰処理 */


				.end


/* end of file */

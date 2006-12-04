/* ------------------------------------------------------------------------ */
/* Hyper Operating System V4 Advance                                        */
/*                                                                          */
/*                                  Copyright (C) 1998-2006 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */

				.h8300h


				.global	__kernel_int_hdr
				.global	__kernel_ictxcb			/* 割込みコンテキスト制御情報 */


				.text


/************************************************
  割り込み処理

  割り込み発生時は er0 を push した後、er0 に
  割り込み番号をセットして、ここにジャンプする
************************************************/
__kernel_int_hdr:
		/* ---- レジスタ保存 ---- */
				push.l	er1
				push.l	er2
				push.l	er3
				
		/* ---- 割り込みをマスク ---- */
				stc.b	ccr, r1l						/* ccr保存 */
				orc		#0xc0, ccr						/* 割込み全マスク */
				and.b	#0xc0, r1l
				
		/* ---- 多重割り込みの判別 ---- */
				mov.b	@(__kernel_ictxcb + 1), r1h		/* 割込みネストカウンタ取得 */
				bne		multiple_int
				
		/* ======== 最初の割り込み ======== */
		/* ---- 割込みマスク値を設定 ---- */
				mov.b	@(__kernel_ictxcb + 0), r0h		/* 古い割込みマスク値を保存 */
				mov.b	r1l, @(__kernel_ictxcb + 0)		/* 新しいマスク値を設定 */
				
		/* ---- 割り込みネストカウンタ設定 ---- */
				mov.b	#1, r1h
				mov.b	r1h, @(__kernel_ictxcb + 1)		/* 割込みネストカウンタ設定 */
				
		/* ---- スタックポインタの入れ替え ---- */
				mov.l	er7, er1
				mov.l	@(__kernel_ictxcb + 4), er7
				push.l	er1								/* 直前のスタックポインタを保存 */
		
		/* ---- 古い割込みマスク値(r0h)と割込み番号(r0l)の保存 ---- */
				push.w	r0

		/* ---- 割り込み処理の開始 ---- */
				jsr		@__kernel_sta_inh
				
		/* ---- 割り込みハンドラの処理 ---- */
				mov.b	@(1, er7), r0l					/* スタックから割込み番号を取り出す */
				extu.w	r0
				extu.l	er0
				jsr		@__kernel_exe_inh

		/* ---- 古い割込みマスク値(r0h)と割込み番号(r0l)の復帰 ---- */
				pop.w	r0
				
		/* ---- スタックポインタ復帰 ---- */
				mov.l	@er7, er7
				
		/* ---- 割り込みネストカウンタクリア ---- */
				xor.b	r1l, r1l
				mov.b	r1l, @(__kernel_ictxcb + 1)
				
		/* ---- 割り込みマスク値の復帰 ---- */
				mov.b	@(16, er7), r1l
				and.b	#0xc0, r1l
				mov.b	r1l, @(__kernel_ictxcb + 0)		/* 割込み前の値に戻す */
				cmp.b	r1l, r0h
				bne		return_int						/* 割込み前処理中の多重割り込みなら後処理をカット */
				
		/* ---- コンテキストスイッチ実施 ---- */
				jsr		@__kernel_end_inh
		
		/* ---- コンテキストスイッチの後処理 ---- */
				mov.b	@(__kernel_ictxcb + 0), r0l		/* マスク値取り出し */
				mov.b	@(16, er7), r1l
				and.b	#0x3f, r1l
				or.b	r0l, r1l
				mov.b	r1l, @(16, er7)					/* スタック上のCCRを更新 */

return_int:
		/* ---- 復帰 ---- */
				pop.l	er3
				pop.l	er2
				pop.l	er1
				pop.l	er0
				rte


		/* ======== 多重割り込み ======== */
multiple_int:
		/* ---- 割り込みネストカウンタ加算 ---- */
				add.b	#1, r1h
				mov.b	r1h, @(__kernel_ictxcb + 1)

		/* ---- 割込みマスク値を設定 ---- */
				mov.b	r1l, @(__kernel_ictxcb + 0)		/* 新しいマスク値を設定 */
				
		/* ---- 割り込みハンドラ呼び出し ---- */
				jsr		@__kernel_exe_inh
				
		/* ---- 割り込みネストカウンタ減算 ---- */
				mov.b	@(__kernel_ictxcb + 1), r1h
				dec.b	r1h
				mov.b	r1h, @(__kernel_ictxcb + 1)
				
		/* ---- 復帰 ---- */
				bra		return_int


				.end


/* end of file */

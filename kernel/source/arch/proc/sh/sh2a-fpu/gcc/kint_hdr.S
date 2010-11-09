/* ------------------------------------------------------------------------ */
/* Hyper Operating System V4 Advance                                        */
/*                                                                          */
/*                                  Copyright (C) 1998-2010 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


				.global	__kernel_int_hdr
				.global	__kernel_ictxcb
				.global	__kernel_sta_inh
				.global	__kernel_exe_inh
				.global	__kernel_end_inh


				.text


#define ICTXCB_IMSK		0
#define ICTXCB_INTCNT	2
#define ICTXCB_ISP		4


/************************************************
  割込みハンドラ

  レジスタバンク数以上の多重割込みネストは無いと
 ものとする。
 ************************************************/
				.align	2
__kernel_int_hdr:
		/* ---- 多重割込みをマスク */
				stc		sr, r0
		/*		mov		r0, r8			*/			/* r8 に sr 保存 */
				or		#0xf0, r0
				ldc		r0, sr						/* 全割込みマスク */
				
		/* ---- 割込み番号取得 */
				mov.l	addr_ibnr, r0
				mov.l	@r0, r0
				and		#0x0f, r0
				shll8	r0
				shlr	r0
				add		#-64, r0
				ldbank	@r0, r0
				shlr2	r0
				mov		r0, r9						/* r9に割り込み番号 */
				
		/* ---- 割込みマスク値の設定＆多重割込み判定 */
				mov.l	addr_ictxcb, r10
				mov.b	@(ICTXCB_INTCNT, r10), r0	/* 割込みネストカウンタ取り出し */
				cmp/eq	#0, r0						/* 初回割込み判定 */
				mov.w	@r0, r11					/* r11に古い割込みマスク値格納 */
				add		#1, r0						/* 割込みネストカウンタ加算 */
				mov.w	r0, @(ICTXCB_IMSK, r10)		/* 新しい割込みマスク値設定 */
				bf/s	multiple_int				/* 多重割込み処理へ分岐 */
				mov.b	r0, @(ICTXCB_INTCNT, r10)	/* 割込みネスト値を設定(遅延スロット) */
				
		/* ==== 初回割込みの処理 */
				
		/* ---- スタック入れ替え */
				mov		r15, r12					/* r12に現在のスタックを退避 */
				mov.l	@(ICTXCB_ISP, r10), r15		/* 割込み用スタックを設定 */
				
		/* ---- 割込み開始処理呼び出し */
				mov.l	addr_sta_inh, r1
				jsr		@r1
				
		/* ---- 割込み実行処理呼び出し */
				mov.l	addr_exe_inh, r1
				jsr		@r1
				mov		r9, r4						/* 割込み番号を引数とする(遅延スロット) */
				
		/* ---- スタックの復帰 */
				mov		r12, r15
				
		/* ---- 割込みカウンタのクリア */
				xor		r0, r0
				mov.b	r0, @(ICTXCB_INTCNT, r10)
				
		/* ---- 割込みマスク値復帰 */
				mov.l	@(4, r15), r0				/* 割込み前の sr を取り出し */
				and		#0xf0, r0					/* 割込みマスク値取り出し */
				cmp/eq	r0, r11						/* 古い割込みマスク値と比較 */
				bf/s	return_int					/* 不一致なら既に割込み処理中とみなす */
				mov.w	r3, @(ICTXCB_IMSK, r10)		/* 割込み前の状態に割込みマスク値を設定(遅延スロット) */
				
		/* ---- 割込み終了処理呼び出し */
				resbank
				mov.l	r0, @-r15
				mov.l	r1, @-r15
				mov.l	r2, @-r15
				mov.l	r3, @-r15
				mov.l	r4, @-r15
				mov.l	r5, @-r15
				mov.l	r6, @-r15
				mov.l	r7, @-r15
				sts.l	pr, @-r15
				sts.l	fpscr, @-r15
				sts.l	fpul, @-r15
				fmov.d	dr0, @-r15
				fmov.d	dr2, @-r15
				fmov.d	dr4, @-r15
				fmov.d	dr6, @-r15
				fmov.d	dr8, @-r15
				fmov.d	dr10, @-r15
				
				mov.l	addr_end_inh, r2
				jsr		@r2
				
		/* ---- 復帰時割込みマスクの設定 */
				mov.l	@(96, r15), r0		/* 割込み前の sr を取り出し */
				or		#0xf0, r0			/* 割込みマスク部分クリアの前処理(一旦ビットを立てる) */
				mov.l	addr_ictxcb, r1
				xor		#0xf0, r0			/* 割込みマスク部分クリア(立てといて反転させる) */
				mov.w	@r1, r1				/* マスク値取得 */
				or		r1, r0				/* マスク値を設定 */
				mov.l	r0, @(96, r15)		/* 復帰時SRの設定 */
				
				fmov.d	@r15+, dr0
				fmov.d	@r15+, dr2
				fmov.d	@r15+, dr4
				fmov.d	@r15+, dr6
				fmov.d	@r15+, dr8
				fmov.d	@r15+, dr10
				lds.l	@r15+, fpul
				lds.l	@r15+, fpscr
				lds.l	@r15+, pr
				mov.l	@r15+, r7
				mov.l	@r15+, r6
				mov.l	@r15+, r5
				mov.l	@r15+, r4
				mov.l	@r15+, r3
				mov.l	@r15+, r2
				mov.l	@r15+, r1
				mov.l	@r15+, r0
				
				rte
				nop
				
				
		/* ---- 復帰 */
return_int:
				resbank
				rte
				nop



		/* ==== 多重割込みの処理 */
				.ALIGN	4
multiple_int:
		/* ---- 割込み実行処理呼び出し */
				mov.l	addr_exe_inh, r1
				jsr		@r1					/* 割込み番号(r4)を引数とする */
				mov.l	r3, @-r15			/* 古いマスク値を保存 */
				
		/* ---- 割込みカウンタの減算 */
				mov.l	addr_ictxcb, r1
				mov.b	@(ICTXCB_INTCNT, r1), r0
				add		#-1, r0
				mov.b	r0, @(ICTXCB_INTCNT, r1)
				
		/* ---- 割込みマスク値の復帰 */
				mov.l	@r15+, r3			/* 古いマスク値を復帰 */
				bra		return_int
				mov.w	r3, @r1


				.align	2
addr_ictxcb:
				.long	__kernel_ictxcb			/* 割込みコンテキスト制御ブロック */

addr_sta_inh:
				.long	__kernel_sta_inh		/* 割込み開始処理 */

addr_exe_inh:
				.long	__kernel_exe_inh		/* 割込み実行処理 */

addr_end_inh:
				.long	__kernel_end_inh		/* 割込み終了処理 */

addr_ibnr:
				.long	0xfffe080e				/* IBNR */


				.end


/* end of file */

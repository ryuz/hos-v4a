/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4  μITRON4.0仕様 Real-Time OS                  */
/*    プロセッサ抽象化コンポーネント (日立 SH2用)                           */
/*                                                                          */
/*                                  Copyright (C) 1998-2002 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */



				.global	__kernel_dis_int		/* 割り込み禁止 */
				.global	__kernel_ena_int		/* 割り込み許可 */
				.global	__hospac_cre_ctx		/* 実行コンテキストの作成 */
				.global	__hospac_swi_ctx		/* 実行コンテキストの切替 */
				.global	__kernel_sta_ctx		/* 実行コンテキストの開始 */
				.global	__kernel_sh_imsk		/* 割り込みマスクの値 */


				.text


/************************************************
  割り込み禁止
  void _kernel_dis_int(void)
************************************************/
				.align	2
__kernel_dis_int:
				stc		sr, r0
				or		#0xf0, r0			/* 全割り込みマスク */
				rts
				ldc		r0, sr



/************************************************
  割り込み許可
  void _kernel_ena_int(void)
************************************************/
				.text
				.align	2
_kernel_ena_int:
				mov		#0xf0, r1			/* 0x00f0 を反転させて 0xff0f を作成 */
				not		r1, r1
				stc		sr, r0
				and		r1, r0				/* 割り込みマスク値以外を取得 */
				mov.l	imsk_addr, r1
				mov.l	@r1, r1
				or		r1, r0				/* 割り込みマスクの値を設定 */
				rts
				ldc		r0, sr

				.align	2
imsk_addr:
				.long	__kernel_sh_imsk	/* 割り込みマスク */



/************************************************
  実行コンテキストの作成
  _kernel_cre_ctx(
		_KERNEL_T_CTXCB *pk_ctxcb,		作成するコンテキスト [r4]
		VP              isp,			初期スタックポインタ [r5]
		FP              entry,			実行アドレス         [r6]
		VP_INT          par1,			実行時パラメータ1    [r7]
		VP_INT          par2)			実行時パラメータ2    [@(4, r15)]
************************************************/
				.align 2
__kernel_cre_ctx:
				mov.l	@(4, r15), r0		/* 実行時パラメータ2を取り出し */
				add 	#-16, r5			/* r8-r11用領域分空ける */
				mov.l	r6, @-r5			/* 実行アドレスを      r12 の領域に設定 */
				mov.l	r7, @-r5			/* 実行時パラメータ1を r13 の領域に設定 */
				mov.l	r0, @-r5			/* 実行時パラメータ2を r14 の領域に設定 */
				mov.l	ctx_entry, r0
				mov.l	r0, @-r5			/* 実行エントリポイントをリターンアドレスに設定 */
				rts
				mov.l	r5, @(0, r4) 		/* スタックポインタを保存(遅延スロット) */


/************************************************
  実行コンテキストエントリーアドレス
************************************************/
ctx_entry:	 	
				mov		r13, r4				/* 実行時パラメータ1を設定 */
				jmp		@r12				/* 実行開始アドレスに分岐 */
				mov		r14, r5				/* 実行時パラメータ2を設定(遅延スロット) */



/************************************************
 実行コンテキストの切替
 void _kernel_swi_ctx(
		_KERNEL_T_CTXCB *pk_ctxcb_nxt,	切り替え先のコンテキスト [r4]
		_KERNEL_T_CTXCB *pk_ctxcb_now)	現在のコンテキスト       [r5]
************************************************/
				.align 2
__kernel_swi_ctx:
				mov.l	 r8, @-r15		/* 8-r14,prを退避 */
				mov.l	 r9, @-r15
				mov.l	 r10, @-r15
				mov.l	 r11, @-r15
				mov.l	 r12, @-r15
				mov.l	 r13, @-r15
				mov.l	 r14, @-r15
				sts.l	 pr, @-r15
				mov.l	 r15, @(0, r5)	/* スタックポインタ保存 */
		/* ---- このまま _kernel_sta_ctx に続ける ---- */

/************************************************
 実行コンテキストの開始
 void _kernel_sta_ctx(
		_KERNEL_T_CTXCB *pk_ctxcb)		開始するコンテキスト [r4]
************************************************/
__kernel_sta_ctx:
				mov.l	 @(0, r4), r15	/* スタックポインタ復帰 */
				lds.l	 @r15+, pr		/* r8-r14,prを復帰 */
				mov.l	 @r15+, r14
				mov.l	 @r15+, r13
				mov.l	 @r15+, r12
				mov.l	 @r15+, r11
				mov.l	 @r15+, r10
				mov.l	 @r15+, r9
				rts
				mov.l	 @r15+, r8


				.end


/* end of file */

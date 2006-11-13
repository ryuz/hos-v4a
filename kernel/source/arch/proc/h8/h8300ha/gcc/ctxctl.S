/* ------------------------------------------------------------------------ */
/* Hyper Operating System V4 Advance                                        */
/*                                                                          */
/*                                  Copyright (C) 1998-2006 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


				.h8300h


				.global	__kernel_dis_int		/* 割り込み禁止 */
				.global	__kernel_ena_int		/* 割り込み許可 */
				.global	__kernel_wai_int		/* 割り込み待ち */
				.global	__kernel_cre_ctx		/* 実行コンテキストの作成 */
				.global	__kernel_swi_ctx		/* 実行コンテキストの切替 */
				.global	__kernel_sta_ctx		/* 実行コンテキストの開始 */
				.global	__kernel_rst_ctx		/* 実行コンテキストのリスタート */
				.global	__kernel_h83_imsk		/* 割り込みマスク */


				.text


/************************************************
 割り込み禁止
 void _kernel_dis_int(void)
************************************************/
__kernel_dis_int:
				orc		#h'c0, ccr				/* 割り込みの禁止 */
				rts


/************************************************
  割り込み許可
  void _kernel_ena_int(void)
************************************************/
__kernel_ena_int:
				mov.b	@__kernel_h83_imsk, r0l
				ldc.b	r0l, ccr				/* 割り込みの許可 */
				rts

/************************************************
 割り込み待ち
 void _kernel_wai_int(void)
************************************************/
__kernel_wai_int:
	/*			sleep	*/
				jmp		@__kernel_wai_int



/************************************************
/*  実行コンテキストエントリーアドレス
************************************************/
ctx_entry:	
				mov.l	er3, er0				/* 実行時パラメータを第一引数に設定 */
				mov.l	er4, er1				/* 実行時パラメータを第一引数に設定 */
				jmp		@er2					/* 実行アドレスにジャンプ */


/************************************************
  実行コンテキストの作成
  _kernel_cre_ctx(
		_KERNEL_T_CTXCB *pk_ctxcb,				作成するコンテキスト [er0]
		VP              isp,					初期スタックポインタ [er1]
		FP              entry,					実行アドレス         [@(4, er7)]
		VP_INT          par1,					実行時パラメータ1    [@(8, er7)]
		VP_INT          par2)					実行時パラメータ2    [@(12, er7)]
************************************************/
__kernel_cre_ctx:
				sub.l	#24, er1				/* エントリーポイント+er2〜er6 までの退避分 */
				mov.l	er1, @(0, er0)			/* スタックポインタの格納 */
				mov.l	#ctx_entry, er0
				mov.l	er0, @(20, er1)			/* 実行エントリーポイントの設定 */
				mov.l	@(4, er7), er0
				mov.l	er0, @(16, er1)			/* 実行アドレスの格納(er2部分) */
				mov.l	@(8, er7), er0
				mov.l	er0, @(12, er1)			/* 実行時パラメータ1の格納(er3部分) */
				mov.l	@(12, er7), er0
				mov.l	er0, @(8, er1)			/* 実行時パラメータ1の格納(er4部分) */
				rts


/************************************************
  実行コンテキストの切替
  void _kernel_swi_ctx(
		_KERNEL_T_CTXCB *pk_ctxcb_nxt,			切り替え先のコンテキスト [er0]
		_KERNEL_T_CTXCB *pk_ctxcb_now)			現在のコンテキスト       [er1]
************************************************/
__kernel_swi_ctx:
				push.l	er2
				push.l	er3
				push.l	er4
				push.l	er5
				push.l	er6
				mov.l	er7,@(0, er1)			/* スタックポインタ保存 */
		/* ---- このまま _kernel_sta_ctx に続ける ---- */

/************************************************
  実行コンテキストの開始
  void _kernel_sta_ctx(
		_KERNEL_T_CTXCB *pk_ctxcb)				開始するコンテキスト [er0]
************************************************/
__kernel_sta_ctx:
				mov.l	@(0, er0), er7			/* スタックポインタ復帰 */
				pop.l	er6
				pop.l	er5
				pop.l	er4
				pop.l	er3
				pop.l	er2
				rts


/************************************************
 実行コンテキストのリスタート
 void _kernel_rst_ctx(
		VP_INT par1,							実行時パラメータ1    [er0]
		VP_INT par2,							実行時パラメータ2    [er1]
		VP     isp,								初期スタックポインタ [@(4, er7)]
		FP     entry)							実行アドレス         [@(8, er7)]
************************************************/
__kernel_rst_ctx:
				mov.l	@(4, er7), er3			/* 初期スタックポインタ */
				mov.l	@(8, er7), er4			/* 実行アドレス取り出し */
				mov.l	er3, er7				/* スタックポインタリセット */
				jmp		@er4					/* 実行アドレスに分岐 */


				.comm	__kernel_h83_imsk,1


				.end


/* end of file */

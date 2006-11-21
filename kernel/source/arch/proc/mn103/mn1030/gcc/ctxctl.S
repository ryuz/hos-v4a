/****************************************************************************
  Hyper Operating System V4 Advance

  Copyright (C) 1998-2006 by Project HOS
  http://sourceforge.jp/projects/hos/
****************************************************************************/



				.global	__kernel_ena_int			/* 割り込み許可 */
				.global	__kernel_dis_int			/* 割り込み禁止 */
				.global	__kernel_wai_int			/* CPUのアイドル処理 */
				.global	__kernel_cre_ctx			/* 実行コンテキストの作成 */
				.global	__kernel_sta_ctx			/* 実行コンテキストの開始 */
				.global	__kernel_rst_ctx			/* 実行コンテキストのリスタート */
				.global	__kernel_swi_ctx			/* 実行コンテキストの切替 */


				.text
				.align	2

/************************************************
  割り込み許可
   void _kernel_ena_int(void)
 ************************************************/
 				.type	__kernel_ena_int, %function
__kernel_ena_int:
				or		0x0800, psw					/* IEビットセット */
				rets								/* リターン */
				.size	__kernel_ena_int, .-__kernel_ena_int


/************************************************
  割り込み禁止
   void _kernel_dis_int(void)
 ************************************************/
 				.type	__kernel_dis_int, %function
__kernel_dis_int:
				and		0xf7ff, psw					/* IEビットクリア */
				rets								/* リターン */
				.size	__kernel_dis_int, .-__kernel_dis_int


/************************************************
 割り込み待ち(CPUのアイドル処理)
   void __kernel_wai_int(void);
*************************************************/
 				.type	_kernel_wai_int, %function
__kernel_wai_int:
				jmp		__kernel_wai_int
				.size	_kernel_wai_int, .-_kernel_wai_int



/************************************************
  実行コンテキストの作成
  void _kernel_cre_ctx(
			VP_INT          par1,		実行時パラメータ1    [d0]
			VP_INT          par2,		実行時パラメータ2    [d1]
			_KERNEL_T_CTXCB *pk_ctxcb,	作成するコンテキスト [(12, sp)]
			VP              isp,		スタックポインタ     [(16, sp)]
			FP              entry)		実行アドレス         [(20, sp)]
*************************************************/
 				.type	__kernel_cre_ctx, %function
__kernel_cre_ctx:
				mov		(12, sp), a0	/* コンテキストアドレス取り出し */
				mov		(16, sp), a1	/* 初期スタックポインタ取り出し */
				add		-20, a1			/* スタック領域を確保 */
				mov		a1, (a0)		/* スタックポインタ保存 */
				mov		d0, (12, a1)	/* 実行時パラメータ1設定 */
				mov		d1, (8, a1)		/* 実行時パラメータ2設定 */
				mov		(20, sp), a0	/* 実行アドレス取り出し */
				mov		a0, (0, a1)		/* 実行アドレス設定 */
				mov		ctx_entry, a0	
				mov		a0, (16, a1)	/* エントリーアドレス設定 */
				rets
				.size	__kernel_cre_ctx, .-__kernel_cre_ctx


/************************************************
  実行コンテキストエントリーアドレス
*************************************************/
 				.type	ctx_entry, %function
ctx_entry:
				mov		d2, d0			/* par1を設定 */
				mov		d3, d1			/* par2を設定 */
				jmp		(a2)			/* entry を実行 */
				.size	ctx_entry, .-ctx_entry



/************************************************
  実行コンテキストのリスタート
  void _kernel_rst_ctx(
			VP_INT         par1,		実行時パラメータ     [d0]
			VP_INT         par2,		実行時パラメータ     [d1]
			FP             entry,		実行アドレス         [(12, sp)]
			VP             isp)			初期スタックポインタ [(16, sp)]
*************************************************/
 				.type	__kernel_rst_ctx, %function
__kernel_rst_ctx:
				mov		(12, sp), a0		/* 初期スタックポインタ取り出し */
				mov		(16, sp), a1		/* 実行アドレス取り出し */
				mov		a1, sp				/* スタックを初期値にリセット */
				jmp		(a0)				/* 実行アドレスから再開始 */
				.size	__kernel_rst_ctx, .-_kernel_rst_ctx





/************************************************
  実行コンテキストの切替
  void _kernel_swi_ctx(
			_KERNEL_T_CTXCB *pk_ctxinf_nxt,		実行を開始するコンテキスト [d0]
			_KERNEL_T_CTXCB *pk_ctxinf_now)		現在のコンテキストの保存先 [d1]
*************************************************/
 				.type	__kernel_swi_ctx, %function
__kernel_swi_ctx:
				movm	[d2,d3,a2,a3], (sp)
				mov		d1, a0
				mov		sp, a1
				mov		d1, (a0)					/* スタックポインタ保存 */
		/* ---- そのまま _kernel_sta_ctx に続ける ---- */


/************************************************
  実行コンテキストの開始
  void _kernel_sta_ctx(
			_KERNEL_T_CTXCB *pk_ctxcb)			実行を開始するコンテキスト [d0]
*************************************************/
 				.type	__kernel_sta_ctx, %function
__kernel_sta_ctx:
				mov		d0, a0
				mov		(a0), a0
				mov		a0, sp
				ret		[d2,d3,a2,a3], 16

				.size	__kernel_swi_ctx, .-__kernel_swi_ctx
				.size	__kernel_sta_ctx, .-__kernel_sta_ctx


				.END


/* end of file */

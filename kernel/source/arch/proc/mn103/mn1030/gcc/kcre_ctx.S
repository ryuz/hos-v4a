/****************************************************************************
  Hyper Operating System V4 Advance
  %jp{コンテキスト制御(MN1030シリーズ用}%en{MN1030}

  Copyright (C) 1998-2007 by Project HOS
  http://sourceforge.jp/projects/hos/
****************************************************************************/



				.text
				.align	2



/************************************************
  実行コンテキストの作成
  void _kernel_cre_ctx(
			VP_INT          par1,		実行時パラメータ1    [d0]
			VP_INT          par2,		実行時パラメータ2    [d1]
			_KERNEL_T_CTXCB *pk_ctxcb,	作成するコンテキスト [(12, sp)]
			VP              isp,		スタックポインタ     [(16, sp)]
			FP              entry)		実行アドレス         [(20, sp)]
*************************************************/
				.global	__kernel_cre_ctx
 				.type	__kernel_cre_ctx, %function
__kernel_cre_ctx:
				mov		(12, sp), a0	/* コンテキストアドレス取り出し */
				mov		(16, sp), a1	/* 初期スタックポインタ取り出し */
				add		-24, a1			/* スタック領域を確保 */
				mov		a1, (a0)		/* スタックポインタ保存 */
				mov		d0, (12, a1)	/* 実行時パラメータ1設定(d2) */
				mov		d1, (8, a1)		/* 実行時パラメータ2設定(d3) */
				mov		(20, sp), a0	/* 実行アドレス取り出し */
				mov		a0, (0, a1)		/* 実行アドレス設定(a3) */
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
				add		-12, sp
				jmp		(a3)			/* entry を実行 */
				.size	ctx_entry, .-ctx_entry



				.END


/* end of file */

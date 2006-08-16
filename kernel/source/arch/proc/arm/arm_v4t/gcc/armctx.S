/****************************************************************************
  Hyper Operating System V4 Advance

  @file  armctx.s
  @brief %en{コンテキスト制御(ARM v4t アーキテクチャ)}%jp{ARM v4t}
 
  @version $Id: armctx.S,v 1.1 2006-08-16 16:27:03 ryuz Exp $

  Copyright (C) 1998-2006 by Project HOS
  http://sourceforge.jp/projects/hos/
****************************************************************************/



/* ---- プロセッサモード定義 ---- */
#define Mode_USR		0x10		/* USR モード */
#define Mode_FIQ		0x11		/* FIQ モード */
#define Mode_IRQ		0x12		/* IRQ モード */
#define Mode_SVC		0x13		/* SVC モード */
#define Mode_ABT		0x17		/* ABT モード */
#define Mode_UND		0x1b		/* UND モード */
#define Mode_SYS		0x1f		/* SYS モード */
#define Mode_MASK		0x1f		/* モードビットマスク */


/* ---- フラグ定義 ---- */
#define T_Bit			0x20		/* T ビット */
#define F_Bit			0x40		/* F ビット */
#define I_Bit			0x80		/* I ビット */



				.global	_kernel_ena_int				/* 割り込み許可 */
				.global	_kernel_dis_int				/* 割り込み禁止 */
				.global	_kernel_wai_int				/* CPUのアイドル処理 */
				.global	_kernel_cre_ctx				/* 実行コンテキストの作成 */
				.global	_kernel_sta_ctx				/* 実行コンテキストの開始 */
				.global	_kernel_rst_ctx				/* 実行コンテキストのリスタート */
				.global	_kernel_swi_ctx				/* 実行コンテキストの切替 */


				.text
				.align	2

/************************************************
  割り込み許可
   void _kernel_ena_int(void)
 ************************************************/
 				.type	_kernel_ena_int, %function
_kernel_ena_int:
				mrs 	r0, cpsr					/* cpsr取得 */
				bic		r0, r0, #(F_Bit | I_Bit)	/* FビットとIビットをクリア */
				msr 	cpsr_c, r0					/* cpsr設定 */
				bx		lr							/* リターン */
				.size	_kernel_ena_int, .-_kernel_ena_int


/************************************************
  割り込み禁止
   void _kernel_dis_int(void)
 ************************************************/
 				.type	_kernel_dis_int, %function
_kernel_dis_int:
				mrs 	r0, cpsr					/*  cpsr取得 */
				orr		r0, r0, #(F_Bit | I_Bit)	/*  FビットとIビットを設定 */
				msr 	cpsr_c, r0					/*  cpsr設定 */
				bx		lr							/*  リターン */
				.size	_kernel_dis_int, .-_kernel_dis_int


/************************************************
 割り込み待ち(CPUのアイドル処理)
   void _kernel_wai_int(void);
*************************************************/
 				.type	_kernel_wai_int, %function
_kernel_wai_int:
				mov 	r0, #0
/*				mcr		p15, 0, r0, c7, c0, 4	*/	/* WaitForInterrupt */
				b		_kernel_wai_int
				.size	_kernel_wai_int, .-_kernel_wai_int

				
				.code 16

/************************************************
  実行コンテキストの作成
  void _kernel_cre_ctx(
			_KERNEL_T_CTXCB *pk_ctxcb,	作成するコンテキスト (r0)
			VP             isp,			スタックポインタ     (r1)
			FP             entry,		実行アドレス         (r2)
			VP_INT         par1,		実行時パラメータ     (r3)
			VP_INT         par2)		実行時パラメータ     (sp[0])
*************************************************/
 				.thumb_func
 				.type	_kernel_cre_ctx, %function
_kernel_cre_ctx:
				sub		r1, #36						/* スタックを確保 */
				str		r2, [r1, #0]				/* r4 部分にentryを設定 */
				str		r3, [r1, #4]				/* r5 部分にpar1を設定 */
				ldr		r2, [sp, #0]				/* par2を取り出し */
				str		r2, [r1, #8]				/* r6 部分にpar2を設定 */
				adr		r2, ctx_entry				/* エントリーアドレス設定 */
				add		r2, #1						/* Thumbモードアドレスとして設定 */
				str		r2, [r1, #32]				/* lr 部分にエントリーアドレスを設定 */
				str		r1, [r0]					/* ctxcb に新 sp を保存 */
				bx		lr							/* リターン */
				.size	_kernel_cre_ctx, .-_kernel_cre_ctx


/************************************************
  実行コンテキストエントリーアドレス
*************************************************/
 				.thumb_func
 				.type	ctx_entry, %function
ctx_entry:
				mov		r0, r5						/* par1を設定 */
				mov		r1, r6						/* par2を設定 */
				bx		r4							/* entry を実行 */
				.size	ctx_entry, .-ctx_entry



/************************************************
  実行コンテキストのリスタート
  void _kernel_rst_ctx(
			VP_INT         par1,		実行時パラメータ (r0)
			VP_INT         par2,		実行時パラメータ (r1)
			FP             entry,		実行アドレス     (r2)
			VP             isp)			スタックポインタ (r3)
*************************************************/
 				.thumb_func
 				.type	_kernel_rst_ctx, %function
_kernel_rst_ctx:
				mov		sp, r3						/* スタックを初期値にリセット */
				bx		r2							/* エントリーアドレスから再開始 */
				.size	_kernel_rst_ctx, .-_kernel_rst_ctx



				.align	2
				.code	32


/************************************************
  実行コンテキストの切替
  void _kernel_swi_ctx(
			_KERNEL_T_CTXCB *pk_ctxinf_nxt,		現在のコンテキストの保存先 (r0)
			_KERNEL_T_CTXCB *pk_ctxinf_now)		切り替えるコンテキスト     (r1)
*************************************************/
 				.type	_kernel_swi_ctx, %function
_kernel_swi_ctx:
				stmfd	sp!, {r4-r11, lr}			/* レジスタ保存 */
				str		sp, [r1]					/* スタックポインタ保存 */
		/* ---- そのまま _kernel_sta_ctx に続ける ---- */


/************************************************
  実行コンテキストの開始
  void _kernel_sta_ctx(
			_KERNEL_T_CTXCB *pk_ctxcb)			実行を開始するコンテキスト (r0)
*************************************************/
 				.type	_kernel_sta_ctx, %function
_kernel_sta_ctx:
				ldr		sp, [r0]					/* スタックポインタ復帰 */
				ldmfd	sp!, {r4-r11, pc}			/* レジスタ復帰 */

				.size	_kernel_swi_ctx, .-_kernel_swi_ctx
				.size	_kernel_sta_ctx, .-_kernel_sta_ctx


				.END


/* end of file */

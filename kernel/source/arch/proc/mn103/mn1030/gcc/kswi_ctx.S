/****************************************************************************
  Hyper Operating System V4 Advance
  %jp{コンテキスト制御(MN1030シリーズ用}%en{MN1030}

  Copyright (C) 1998-2007 by Project HOS
  http://sourceforge.jp/projects/hos/
****************************************************************************/



				.text
				.align	2



/************************************************
  実行コンテキストの切替
  void _kernel_swi_ctx(
			_KERNEL_T_CTXCB *pk_ctxinf_nxt,		実行を開始するコンテキスト [d0]
			_KERNEL_T_CTXCB *pk_ctxinf_now)		現在のコンテキストの保存先 [d1]
*************************************************/
				.global	__kernel_swi_ctx
 				.type	__kernel_swi_ctx, %function
__kernel_swi_ctx:
				movm	[d2,d3,a2,a3], (sp)
				mov		d1, a0
				mov		sp, a1
				mov		a1, (a0)					/* スタックポインタ保存 */
		/* ---- そのまま _kernel_sta_ctx に続ける ---- */


/************************************************
  実行コンテキストの開始
  void _kernel_sta_ctx(
			_KERNEL_T_CTXCB *pk_ctxcb)			実行を開始するコンテキスト [d0]
*************************************************/
				.global	__kernel_sta_ctx
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

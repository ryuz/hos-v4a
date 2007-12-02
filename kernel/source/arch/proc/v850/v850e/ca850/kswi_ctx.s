# ---------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#
#                                     Copyright (C) 2007 by Project HOS
#                                     http://sourceforge.jp/projects/hos/
# ---------------------------------------------------------------------------


				.text


# ------------------------------------------------
#  実行コンテキストの切替
#  void _kernel_swi_ctx(
# 		_KERNEL_T_CTXCB *pk_ctxcb_nxt,			切り替え先のコンテキスト [r6]
# 		_KERNEL_T_CTXCB *pk_ctxcb_now)			現在のコンテキスト       [r7]
# ------------------------------------------------
				.align	4
				.frame	__kernel_swi_ctx, 48
				.globl	__kernel_swi_ctx
__kernel_swi_ctx:
				prepare	r20, r21, r22, r23, r24, r25, r26, r27, r28, r29, r30, r31, 0
				st.w	sp, [r7]


# ------------------------------------------------
#  実行コンテキストの開始
#  void _kernel_sta_ctx(
# 		_KERNEL_T_CTXCB *pk_ctxcb)				開始するコンテキスト [r6]
# ------------------------------------------------
				.frame	__kernel_sta_ctx, 0
				.globl	__kernel_sta_ctx
__kernel_sta_ctx:
				ld.w	[r6], sp
				dispose	0, r20, r21, r22, r23, r24, r25, r26, r27, r28, r29, r30, r31, lp


# end of file

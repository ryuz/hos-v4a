# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#
#                                    Copyright (C) 1998-2007 by Project HOS
#                                    http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------



				.text


# --------------------------------------------------
# 実行コンテキストの切替
# void _kernel_swi_ctx(
#		_KERNEL_T_CTXCB *pk_ctxcb_nxt,		切り替え先のコンテキスト [r6]
#		_KERNEL_T_CTXCB *pk_ctxcb_now)		現在のコンテキスト       [r7]
# --------------------------------------------------
				.globl	__kernel_swi_ctx
__kernel_swi_ctx:
				pushm	r20, r21, r22, r23, r24, r25, r26, r27, r28, r29, lp	-- レジスタを退避
				st.w	sp, [r7]												-- スタックポインタ保存
		-- このまま _kernel_sta_ctx に続ける

# -------------------------------------------------
# 実行コンテキストの開始
# void _kernel_sta_ctx(
#		_KERNEL_T_CTXCB *pk_ctxcb)			開始するコンテキスト [r6]
# -------------------------------------------------
				.globl	__kernel_sta_ctx
__kernel_sta_ctx:
				ld.w	[r6], sp												-- スタックポインタ復帰
				popm	r20, r21, r22, r23, r24, r25, r26, r27, r28, r29, lp	-- レジスタを復帰
				jmp		[lp]



# end of file

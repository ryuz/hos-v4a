# ---------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#
#                                     Copyright (C) 2007 by Project HOS
#                                     http://sourceforge.jp/projects/hos/
# ---------------------------------------------------------------------------


				.text


# ------------------------------------------------
#  実行コンテキストの作成
#  _kernel_cre_ctx(
#		_KERNEL_T_CTXCB *pk_ctxcb,				作成するコンテキスト (r6)
#		VP              isp,					初期スタックポインタ (r7)
#		FP              entry,					実行アドレス         (r8)
#		VP_INT          par1,					実行時パラメータ1    (r9)
#		VP_INT          par2)					実行時パラメータ2    (0[sp])
# ------------------------------------------------
				.align	4
				.frame	__kernel_cre_ctx, 0
				.globl	__kernel_cre_ctx
__kernel_cre_ctx:
				add		-48, r7
				st.w	r30, 4[r7]		-- r30 EP
				st.w	r8, 8[r7]		-- r29 実行アドレス
				st.w	r9, 12[r7]		-- r28 実行時パラメータ1 
				ld.w	0[sp], r8
				st.w	r8, 12[r7]		-- r27 実行時パラメータ2
				mov32	ctx_entry, r8
				st.w	r8, 0[r7]		-- r31 LP
				st.w	r7, 0[r6]
				jmp		[lp]


# ------------------------------------------------
#  実行コンテキストエントリーアドレス
# ------------------------------------------------
ctx_entry:	 	
				mov		r28, r6			-- 実行時パラメータ1を設定
				mov		r27, r7			-- 実行時パラメータ2を設定
				jmp		[r29]


# end of file

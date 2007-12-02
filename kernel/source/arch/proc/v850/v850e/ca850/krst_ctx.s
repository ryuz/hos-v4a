# ---------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#
#                                     Copyright (C) 2007 by Project HOS
#                                     http://sourceforge.jp/projects/hos/
# ---------------------------------------------------------------------------


				.text


# ------------------------------------------------
#  実行コンテキストのリスタート
#  void _kernel_rst_ctx(
#		VP_INT par1,							実行時パラメータ1    [r6]
#		VP_INT par2,							実行時パラメータ2    [r7]
#		VP     isp,								初期スタックポインタ [r8]
#		FP     entry)							実行アドレス         [r9]
# ------------------------------------------------
				.align	4
				.frame	__kernel_rst_ctx, 0
				.globl	__kernel_rst_ctx
__kernel_rst_ctx:
				jmp		[r9]


# end of file

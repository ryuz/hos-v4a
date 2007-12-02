# ---------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#
#                                     Copyright (C) 2007 by Project HOS
#                                     http://sourceforge.jp/projects/hos/
# ---------------------------------------------------------------------------


				.text


# ------------------------------------------------
#  割り込み許可
#  void _kernel_ena_int(void)
# ------------------------------------------------
				.align	4
				.frame	__kernel_ena_int, 0
				.globl	__kernel_ena_int
__kernel_ena_int:
				ei
				jmp		[lp]


# end of file

# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#
#                                    Copyright (C) 1998-2007 by Project HOS
#                                    http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


				.text


# --------------------------------------------------
# 割り込み禁止
# void _kernel_dis_int(void)
# --------------------------------------------------
				.globl	__kernel_dis_int
__kernel_dis_int:
				di
				jmp		[lp]



# end of file

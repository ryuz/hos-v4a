# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#
#                                    Copyright (C) 1998-2007 by Project HOS
#                                    http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


				.text


# --------------------------------------------------
# 割り込み許可
# void _kernel_ena_int(void)
# --------------------------------------------------
				.globl	__kernel_ena_int
__kernel_ena_int:
				ei
				jmp		[lp]



# end of file

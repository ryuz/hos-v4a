# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#
#                                    Copyright (C) 1998-2007 by Project HOS
#                                    http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


				.text


# --------------------------------------------------
# 割り込み待ち
# void _kernel_wai_int(void)
# --------------------------------------------------
				.globl	__kernel_wai_int
__kernel_wai_int:
		;		halt
				jbr		__kernel_wai_int



# end of file

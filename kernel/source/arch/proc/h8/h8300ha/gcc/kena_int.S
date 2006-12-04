/* ------------------------------------------------------------------------ */
/* Hyper Operating System V4 Advance                                        */
/*                                                                          */
/*                                  Copyright (C) 1998-2006 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


				.h8300h

				.global	__kernel_ictxcb

				.text


/************************************************
  割り込み許可
  void _kernel_ena_int(void)
************************************************/
				.global	__kernel_ena_int
__kernel_ena_int:
				mov.b	@(__kernel_ictxcb + 0), r0l
				ldc.b	r0l, ccr
				rts


				.end


/* end of file */

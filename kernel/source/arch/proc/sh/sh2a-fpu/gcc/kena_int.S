/* ------------------------------------------------------------------------ */
/* Hyper Operating System V4 Advance                                        */
/*                                                                          */
/*                                  Copyright (C) 1998-2006 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */



				.text


/************************************************
  割り込み許可
  void _kernel_ena_int(void)
 ************************************************/
				.align	2
				.global	__kernel_ena_int
__kernel_ena_int:
				mov.l	addr_ictxcb, r2
				stc		sr, r0
				mov.w	@r2, r1
				or		#0xf0, r0
				xor		#0xf0, r0
				or		r1, r0
				ldc		r0, sr
				rts
				nop


				.align	2
addr_ictxcb:
				.long	__kernel_ictxcb


				.end


/* end of file */

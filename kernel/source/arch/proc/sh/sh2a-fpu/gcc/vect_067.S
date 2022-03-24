/* ------------------------------------------------------------------------ */
/* Hyper Operating System V4 Advance                                        */
/*                                                                          */
/*                                  Copyright (C) 1998-2006 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


				.global	__kernel_vector_067
				.global	__kernel_int_hdr


				.text

__kernel_vector_067:
				mov.l	r4, @-r15
				mov.l	addr_int_hdr, r4
				jmp		@r4
				mov		#67, r4


				.ALIGN	4
addr_int_hdr:
				.long	__kernel_int_hdr



/* end of file */

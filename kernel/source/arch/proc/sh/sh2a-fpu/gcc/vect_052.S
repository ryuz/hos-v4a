/* ------------------------------------------------------------------------ */
/* Hyper Operating System V4 Advance                                        */
/*                                                                          */
/*                                  Copyright (C) 1998-2006 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


				.global	__kernel_vector_052
				.global	__kernel_exc_hdr


				.text

__kernel_vector_052:
				mov.l	r4, @-r15
				mov.l	addr_exc_hdr, r4
				jmp		@r4
				mov		#52, r4


				.ALIGN	4
addr_exc_hdr:
				.long	__kernel_exc_hdr



/* end of file */

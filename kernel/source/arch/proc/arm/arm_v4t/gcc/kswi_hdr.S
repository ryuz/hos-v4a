/** 
 *  Hyper Operating System V4 Advance
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "arm_v4t.inc"


				.code	32
				.text
				.align	2

				.global	_kernel_ictxcb
				.global	_kernel_sta_inh
				.global	_kernel_end_inh
				.global	_kernel_exe_inh


/************************************************
  SWI handler
 ************************************************/
				.global	_kernel_swi_hdr
_kernel_swi_hdr:
				movs	pc, r14

				.end


/* end of file */

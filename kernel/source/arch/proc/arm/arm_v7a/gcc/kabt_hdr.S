/** 
 *  Hyper Operating System V4 Advance
 *
 * Copyright (C) 1998-2020 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "arm_v7a.inc"


				.code	32
				.text
				.align	2


/************************************************
  Data abort handler
 ************************************************/
				.global	_kernel_abt_hdr
_kernel_abt_hdr:
				b		_kernel_abt_hdr

				.end


/* end of file */

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


/************************************************
  Prefetch abort handler
 ************************************************/
				.global	_kernel_pre_hdr
_kernel_pre_hdr:
				b		_kernel_pre_hdr

				.end


/* end of file */

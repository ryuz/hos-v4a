/** 
 *  Hyper Operating System V4 Advance
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "arm_v4t.inc"

				.text
				.align	2

/************************************************
  割り込み待ち(CPUのアイドル処理)
  void 	_kernel_wai_int(void);
 ************************************************/
				.global	_kernel_wai_int
_kernel_wai_int:
		/*		mcr		p15, 0, r0, c7, c0, 4	*/	/* WaitForInterrupt */
				b		_kernel_wai_int


				.end


/* end of file */

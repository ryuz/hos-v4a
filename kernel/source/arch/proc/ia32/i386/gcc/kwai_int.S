/** 
 *  Hyper Operating System V4 Advance
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



				.code32
				.text

/************************************************
  割り込み待ち(CPUのアイドル処理)
  void 	_kernel_wai_int(void);
 ************************************************/
				.global	__kernel_wai_int
__kernel_wai_int:
				hlt
				jmp		__kernel_wai_int


				.end


/* end of file */

/****************************************************************************
  Hyper Operating System V4 Advance
  %jp{コンテキスト制御(MN1030シリーズ用}%en{MN1030}

  Copyright (C) 1998-2007 by Project HOS
  http://sourceforge.jp/projects/hos/
****************************************************************************/



				.text
				.align	2



/************************************************
 割り込み待ち(CPUのアイドル処理)
   void __kernel_wai_int(void);
*************************************************/
				.global	__kernel_wai_int
 				.type	_kernel_wai_int, %function
__kernel_wai_int:
				jmp		__kernel_wai_int
				.size	_kernel_wai_int, .-_kernel_wai_int



				.END


/* end of file */

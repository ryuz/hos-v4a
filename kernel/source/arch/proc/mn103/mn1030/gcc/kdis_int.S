/****************************************************************************
  Hyper Operating System V4 Advance
  %jp{コンテキスト制御(MN1030シリーズ用}%en{MN1030}

  Copyright (C) 1998-2007 by Project HOS
  http://sourceforge.jp/projects/hos/
****************************************************************************/



				.text
				.align	2



/************************************************
  割り込み禁止
   void _kernel_dis_int(void)
 ************************************************/
				.global	__kernel_dis_int
 				.type	__kernel_dis_int, %function
__kernel_dis_int:
				and		0xf7ff, psw					/* IEビットクリア */
				rets								/* リターン */
				.size	__kernel_dis_int, .-__kernel_dis_int



				.END


/* end of file */

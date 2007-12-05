/****************************************************************************
  Hyper Operating System V4 Advance
  %jp{コンテキスト制御(MN1030シリーズ用}%en{MN1030}

  Copyright (C) 1998-2007 by Project HOS
  http://sourceforge.jp/projects/hos/
****************************************************************************/



				.text
				.align	2


/************************************************
  割り込み許可
   void _kernel_ena_int(void)
 ************************************************/
				.global	__kernel_ena_int
 				.type	__kernel_ena_int, %function
__kernel_ena_int:
				or		0x0800, psw					/* IEビットセット */
				rets								/* リターン */
				.size	__kernel_ena_int, .-__kernel_ena_int



				.END


/* end of file */

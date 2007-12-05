/****************************************************************************
  Hyper Operating System V4 Advance
  %jp{コンテキスト制御(MN1030シリーズ用}%en{MN1030}

  Copyright (C) 1998-2007 by Project HOS
  http://sourceforge.jp/projects/hos/
****************************************************************************/



				.text
				.align	2



/************************************************
  プロセッサ固有の初期化
  void _kernel_ini_prc(void)
 ************************************************/
				.global	__kernel_ini_prc
 				.type	__kernel_ini_prc, %function
__kernel_ini_prc:
				and		0x0700, psw		/* IMビット以外クリア */
				or		0x0700, psw		/* IMビットセット */
				rets					/* リターン */
				.size	__kernel_ini_prc, .-__kernel_ini_prc



				.END


/* end of file */

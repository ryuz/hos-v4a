/** 
 *  Hyper Operating System V4 Advance
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



				.code32
				.text


/***********************************************************************
  %jp{CPU 例外ハンドラ edi: 例外番号 esi:例外コンテキストの先頭アドレス}
 ***********************************************************************/
				.global	_kernel_exc_hdr
_kernel_exc_hdr:

				pushl	%esi	 /* %jp{第2引数:例外コンテキスト} */
				pushl	%edi	 /* %jp{第1引数:例外番号} */

				sti  /* %jp{割込み許可} */
				call	_kernel_exe_exh /* %jp{CPU例外処理呼び出し} */
				cli  /* %jp{割込み禁止} */

				addl	$8, %esp /* %jp{引数領域を解放} */

				ret


				.end


/* end of file */

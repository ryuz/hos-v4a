/** 
 *  Hyper Operating System V4 Advance
 *
 * Copyright (C) 1998-2005 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


				.code32
				.text


/************************************************
  実行コンテキストのリスタート
  void _kernel_rst_ctx(
			VP_INT         par1,	4(%esp) : 実行時パラメータ
			VP_INT         par2,	8(%esp) : 実行時パラメータ
			FP             entry,	12(%esp) : 実行アドレス
			VP             isp)		16(%esp) : スタックポインタ
 ************************************************/
				.global	_kernel_rst_ctx
_kernel_rst_ctx:
				mov		4(%esp), %eax
				mov		8(%esp), %ebx
				mov		12(%esp), %ecx
				mov		16(%esp), %esp
				push	%ebx
				push	%eax
				call	*%ecx


				.end


/* end of file */

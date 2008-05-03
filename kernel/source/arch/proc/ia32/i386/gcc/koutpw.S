/** 
 *  Hyper Operating System V4 Advance
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



				.code32
				.text


/************************************************
  IOポート 32bit出力
  void _kernel_outpw(
			UH		port,		4(%esp) : ポート番号
			UW		data)		8(%esp) : 出力データ
 ************************************************/
				.global	_kernel_outpw
_kernel_outpw:
				movl	4(%esp), %edx
				movl	8(%esp), %eax
				outb	%eax, %dx
				ret


				.end


; end of file


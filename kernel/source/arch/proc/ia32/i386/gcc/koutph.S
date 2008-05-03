/** 
 *  Hyper Operating System V4 Advance
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



				.code32
				.text


/************************************************
  IOポート 16bit出力
  void _kernel_outpb(
			UH		port,		4(%esp) : ポート番号
			UH		data)		8(%esp) : 出力データ
 ************************************************/
				.global	_kernel_outph
_kernel_outph:
				movl	4(%esp), %edx
				movl	8(%esp), %eax
				outw	%ax, %dx
				ret


				.end


; end of file


/** 
 *  Hyper Operating System V4 Advance
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



				.code32
				.text


/************************************************
  IOポート 16bit入力
  UH _kernel_inph(
			UH		port)		4(%esp) : ポート番号
 ************************************************/
				.global	_kernel_inph
_kernel_inph:
				movl	4(%esp), %edx
				xor		%eax, %eax
				inw		%dx, %ax
				ret


				.end


; end of file


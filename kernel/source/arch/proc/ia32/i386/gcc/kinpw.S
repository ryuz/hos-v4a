/** 
 *  Hyper Operating System V4 Advance
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



				.code32
				.text


/************************************************
  IOポート 32bit入力
  UW _kernel_inpb(
			UH		port)		4(%esp) : ポート番号
 ************************************************/
				.global	_kernel_inpw
_kernel_inpw:
				movl	4(%esp), %edx
				xorl	%eax, %eax
				inl		%dx, %eax
				ret


				.end


; end of file


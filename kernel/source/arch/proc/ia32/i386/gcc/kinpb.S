/** 
 *  Hyper Operating System V4 Advance
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



				.code32
				.text


/************************************************
  IOポート 8bit入力
  UB _kernel_inpb(
			UH		port)		4(%esp) : ポート番号
 ************************************************/
				.global	__kernel_inpb
__kernel_inpb:
				movl	4(%esp), %edx
				xor		%eax, %eax
				inb		%dx, %al
				ret


				.end


; end of file


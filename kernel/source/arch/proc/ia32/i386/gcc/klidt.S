/** 
 *  Hyper Operating System V4 Advance
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



				.code32
				.text


/************************************************
  LIDT命令
  void _kernel_lidt(
			VP		idt)		4(%esp) : ポート番号
 ************************************************/
				.global	__kernel_lidt
__kernel_lidt:
				movl	4(%esp), %eax
				lidt	(%eax)
				ret


				.end


; end of file


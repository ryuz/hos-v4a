/** 
 * Hyper Operating System V4 Advance
 *
 *  Sample program for PC/AT
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



				.extern		_main
				.extern		__kernel_int_isp
				.extern		_BSS_START
				.extern		_BSS_END

				.global		_boot_handler
				.global		___main


				.text
				.align	4

/************************************************
  起動ハンドラ
************************************************/
_boot_handler:	
				movl	$0x8000, %esp
				jmp		_main


___main:
				ret			/* 何もしない */

				.global		__alloca
__alloca:
				pop		%edx
				sub		%eax, %esp
				jmp		%edx

				.end


/* end of file */

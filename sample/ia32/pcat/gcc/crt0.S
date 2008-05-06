/** 
 * Hyper Operating System V4 Advance
 *
 *  Sample program for PC/AT
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



				.extern		main
				.extern		_kernel_int_isp
				.extern		___bss
				.extern		___bss_end

				.global		_boot_handler
				.global		__main


				.text
				.align	4

/************************************************
  起動ハンドラ
************************************************/
_boot_handler:	
				movl	(_kernel_int_isp), %esp
				
			/* BSS clear */
				movl	$___bss_end, %ecx
				subl	$___bss, %ecx
				movl	$___bss, %edi
				xorl	%eax, %eax
				cld
				rep		stosb
				
				
				call	main
				
_end_main:
				hlt
				jmp		*_end_main

__main:
				ret			/* 何もしない */


				
				.global	_debug_on
_debug_on:		
				pushfl
				popl	%eax
				orl		$0x0100, %eax
				pushl	%eax
				popfl
				ret

				.global	_debug_getflag
_debug_getflag:
				pushfl
				popl	%eax
				ret



				.end


/* end of file */

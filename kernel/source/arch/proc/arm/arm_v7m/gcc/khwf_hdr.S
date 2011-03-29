/** 
 *  Hyper Operating System V4 Advance
 *
 * Copyright (C) 1998-2011 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


				.syntax unified


				.text
				.align	2


/************************************************
  リセットハンドラ
 ************************************************/
				.global	_kernel_hw_fault_handler
				.thumb
				.thumb_func
				.type	_kernel_hw_fault_handler, %function
_kernel_hw_fault_handler:
				b		_kernel_hw_fault_handler
				
				.size	_kernel_hw_fault_handler, .-_kernel_hw_fault_handler


				.end


; end of file


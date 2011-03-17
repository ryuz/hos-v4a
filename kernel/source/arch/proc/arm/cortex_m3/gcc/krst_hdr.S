/** 
 *  Hyper Operating System V4 Advance
 *
 * Copyright (C) 1998-2011 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



				.text
				.align	2

				.global	main

/************************************************
  リセットハンドラ
 ************************************************/
				.global	_kernel_reset_handler
				.thumb
				.thumb_func
				.type	_kernel_reset_handler, %function
_kernel_reset_handler:
				blx		main
				
				.size	_kernel_reset_handler, .-_kernel_reset_handler


				.end


; end of file


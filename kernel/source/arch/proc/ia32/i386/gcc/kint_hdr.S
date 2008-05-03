/** 
 *  Hyper Operating System V4 Advance
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



				.code32
				.text


/************************************************
  割込みハンドラ
 ************************************************/
				.global	_kernel_int_hdr
_kernel_int_hdr:
				ret




				.global	_kernel_vector_032
_kernel_vector_032:
				pushal
				movb	$32, %al
				call	_kernel_int_hdr
				popal
				iret

				.global	_kernel_vector_033
_kernel_vector_033:
				pushal
				movb	$33, %al
				call	_kernel_int_hdr
				popal
				iret

				.global	_kernel_vector_034
_kernel_vector_034:
				pushal
				movb	$34, %al
				call	_kernel_int_hdr
				popal
				iret

				.global	_kernel_vector_035
_kernel_vector_035:
				pushal
				movb	$35, %al
				call	_kernel_int_hdr
				popal
				iret

				.global	_kernel_vector_036
_kernel_vector_036:
				pushal
				movb	$36, %al
				call	_kernel_int_hdr
				popal
				iret

				.global	_kernel_vector_037
_kernel_vector_037:
				pushal
				movb	$37, %al
				call	_kernel_int_hdr
				popal
				iret

				.global	_kernel_vector_038
_kernel_vector_038:
				pushal
				movb	$38, %al
				call	_kernel_int_hdr
				popal
				iret

				.global	_kernel_vector_039
_kernel_vector_039:
				pushal
				movb	$39, %al
				call	_kernel_int_hdr
				popal
				iret

				.global	_kernel_vector_040
_kernel_vector_040:
				pushal
				movb	$40, %al
				call	_kernel_int_hdr
				popal
				iret

				.global	_kernel_vector_041
_kernel_vector_041:
				pushal
				movb	$41, %al
				call	_kernel_int_hdr
				popal
				iret

				.global	_kernel_vector_042
_kernel_vector_042:
				pushal
				movb	$42, %al
				call	_kernel_int_hdr
				popal
				iret

				.global	_kernel_vector_043
_kernel_vector_043:
				pushal
				movb	$43, %al
				call	_kernel_int_hdr
				popal
				iret

				.global	_kernel_vector_044
_kernel_vector_044:
				pushal
				movb	$44, %al
				call	_kernel_int_hdr
				popal
				iret

				.global	_kernel_vector_045
_kernel_vector_045:
				pushal
				movb	$45, %al
				call	_kernel_int_hdr
				popal
				iret

				.global	_kernel_vector_046
_kernel_vector_046:
				pushal
				movb	$46, %al
				call	_kernel_int_hdr
				popal
				iret

				.global	_kernel_vector_047
_kernel_vector_047:
				pushal
				movb	$47, %al
				call	_kernel_int_hdr
				popal
				iret



				.end


/* end of file */

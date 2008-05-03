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
				.global	__kernel_int_hdr
__kernel_int_hdr:
				ret




				.global	__kernel_vector_032
__kernel_vector_032:
				pushal
				movb	$32, %al
				call	__kernel_int_hdr
				popal
				iret

				.global	__kernel_vector_033
__kernel_vector_033:
				pushal
				movb	$33, %al
				call	__kernel_int_hdr
				popal
				iret

				.global	__kernel_vector_034
__kernel_vector_034:
				pushal
				movb	$34, %al
				call	__kernel_int_hdr
				popal
				iret

				.global	__kernel_vector_035
__kernel_vector_035:
				pushal
				movb	$35, %al
				call	__kernel_int_hdr
				popal
				iret

				.global	__kernel_vector_036
__kernel_vector_036:
				pushal
				movb	$36, %al
				call	__kernel_int_hdr
				popal
				iret

				.global	__kernel_vector_037
__kernel_vector_037:
				pushal
				movb	$37, %al
				call	__kernel_int_hdr
				popal
				iret

				.global	__kernel_vector_038
__kernel_vector_038:
				pushal
				movb	$38, %al
				call	__kernel_int_hdr
				popal
				iret

				.global	__kernel_vector_039
__kernel_vector_039:
				pushal
				movb	$39, %al
				call	__kernel_int_hdr
				popal
				iret

				.global	__kernel_vector_040
__kernel_vector_040:
				pushal
				movb	$40, %al
				call	__kernel_int_hdr
				popal
				iret

				.global	__kernel_vector_041
__kernel_vector_041:
				pushal
				movb	$41, %al
				call	__kernel_int_hdr
				popal
				iret

				.global	__kernel_vector_042
__kernel_vector_042:
				pushal
				movb	$42, %al
				call	__kernel_int_hdr
				popal
				iret

				.global	__kernel_vector_043
__kernel_vector_043:
				pushal
				movb	$43, %al
				call	__kernel_int_hdr
				popal
				iret

				.global	__kernel_vector_044
__kernel_vector_044:
				pushal
				movb	$44, %al
				call	__kernel_int_hdr
				popal
				iret

				.global	__kernel_vector_045
__kernel_vector_045:
				pushal
				movb	$45, %al
				call	__kernel_int_hdr
				popal
				iret

				.global	__kernel_vector_046
__kernel_vector_046:
				pushal
				movb	$46, %al
				call	__kernel_int_hdr
				popal
				iret

				.global	__kernel_vector_047
__kernel_vector_047:
				pushal
				movb	$47, %al
				call	__kernel_int_hdr
				popal
				iret



				.end


/* end of file */

/** 
 *  Hyper Operating System V4 Advance
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


				.extern	_kernel_sta_inh
				.extern	_kernel_exe_inh
				.extern	_kernel_end_inh


				.code32
				.text


/************************************************
  割込みハンドラ
 ************************************************/
				.global	_kernel_int_hdr
_kernel_int_hdr:
				push	%eax
				call	_kernel_sta_inh
				call	_kernel_exe_inh
				call	_kernel_end_inh
				add		$4, %esp
				ret



				.global	_kernel_vector_032
_kernel_vector_032:
				pushal
				movl	$32, %eax
				call	_kernel_int_hdr
				popal
				iret

				.global	_kernel_vector_033
_kernel_vector_033:
				pushal
				movl	$33, %eax
				call	_kernel_int_hdr
				popal
				iret

				.global	_kernel_vector_034
_kernel_vector_034:
				pushal
				movl	$34, %eax
				call	_kernel_int_hdr
				popal
				iret

				.global	_kernel_vector_035
_kernel_vector_035:
				pushal
				movl	$35, %eax
				call	_kernel_int_hdr
				popal
				iret

				.global	_kernel_vector_036
_kernel_vector_036:
				pushal
				movl	$36, %eax
				call	_kernel_int_hdr
				popal
				iret

				.global	_kernel_vector_037
_kernel_vector_037:
				pushal
				movl	$37, %eax
				call	_kernel_int_hdr
				popal
				iret

				.global	_kernel_vector_038
_kernel_vector_038:
				pushal
				movl	$38, %eax
				call	_kernel_int_hdr
				popal
				iret

				.global	_kernel_vector_039
_kernel_vector_039:
				pushal
				movl	$39, %eax
				call	_kernel_int_hdr
				popal
				iret

				.global	_kernel_vector_040
_kernel_vector_040:
				pushal
				movl	$40, %eax
				call	_kernel_int_hdr
				popal
				iret

				.global	_kernel_vector_041
_kernel_vector_041:
				pushal
				movl	$41, %eax
				call	_kernel_int_hdr
				popal
				iret

				.global	_kernel_vector_042
_kernel_vector_042:
				pushal
				movl	$42, %eax
				call	_kernel_int_hdr
				popal
				iret

				.global	_kernel_vector_043
_kernel_vector_043:
				pushal
				movl	$43, %eax
				call	_kernel_int_hdr
				popal
				iret

				.global	_kernel_vector_044
_kernel_vector_044:
				pushal
				movl	$44, %eax
				call	_kernel_int_hdr
				popal
				iret

				.global	_kernel_vector_045
_kernel_vector_045:
				pushal
				movl	$45, %eax
				call	_kernel_int_hdr
				popal
				iret

				.global	_kernel_vector_046
_kernel_vector_046:
				pushal
				movl	$46, %eax
				call	_kernel_int_hdr
				popal
				iret

				.global	_kernel_vector_047
_kernel_vector_047:
				pushal
				movl	$47, %eax
				call	_kernel_int_hdr
				popal
				iret



				.end


/* end of file */

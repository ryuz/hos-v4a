/** 
 *  Hyper Operating System V4 Advance
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



				.code32
				.text


/************************************************
  CPU 例外ハンドラ
 ************************************************/
				.global	_kernel_exc_hdr
_kernel_exc_hdr:
				ret





/* 0除算 */
				.global	_kernel_vector_000
_kernel_vector_000:
				pushal
				movb	$0, %al
				call	_kernel_exc_hdr
				popal
				iret


				.extern	Debug_PutHex
				.extern	Debug_PutChar

/* デバッガ */
				.global	_kernel_vector_001
_kernel_vector_001:
				pushal
				movb	$1, %al
				call	_kernel_exc_hdr
				popal
				iret

/* NMI */
				.global	_kernel_vector_002
_kernel_vector_002:
				pushal
				movb	$2, %al
				call	_kernel_exc_hdr
				popal
				iret

/* break point */
				.global	_kernel_vector_003
_kernel_vector_003:
				pushal
				movb	$3, %al
				call	_kernel_exc_hdr
				popal
				iret

/* over flow */
				.global	_kernel_vector_004
_kernel_vector_004:
				pushal
				movb	$4, %al
				call	_kernel_exc_hdr
				popal
				iret

/* bound check */
				.global	_kernel_vector_005
_kernel_vector_005:
				pushal
				movb	$5, %al
				call	_kernel_exc_hdr
				popal
				iret

/* 無効オペコード */
				.global	_kernel_vector_006
_kernel_vector_006:
				pushal
				movb	$6, %al
				call	_kernel_exc_hdr
				popal
				iret

				.global	_kernel_vector_007
_kernel_vector_007:
				pushal
				movb	$7, %al
				call	_kernel_exc_hdr
				popal
				iret

/* ダブル・フォールト */
				.global	_kernel_vector_008
_kernel_vector_008:
				pushal
				movb	$8, %al
				movl	32(%esp), %ebx		/* erro code */
				call	_kernel_exc_hdr
				popal
				add		$4, %esp
				iret


				.global	_kernel_vector_009
_kernel_vector_009:
				pushal
				movb	$9, %al
				call	_kernel_exc_hdr
				popal
				iret


				.global	_kernel_vector_010
_kernel_vector_010:
				pushal
				movb	$10, %al
				movl	32(%esp), %ebx		/* erro code */
				call	_kernel_exc_hdr
				popal
				add		$4, %esp
				iret


				.global	_kernel_vector_011
_kernel_vector_011:
				pushal
				movb	$11, %al
				movl	32(%esp), %ebx		/* erro code */
				call	_kernel_exc_hdr
				popal
				add		$4, %esp
				iret


				.global	_kernel_vector_012
_kernel_vector_012:
				pushal
				movb	$12, %al
				movl	32(%esp), %ebx		/* erro code */
				call	_kernel_exc_hdr
				popal
				add		$4, %esp
				iret

/* 一般保護例外 */
				.global	_kernel_vector_013
_kernel_vector_013:
				pushal
				movl	32(%esp), %ebx		/* erro code */
				movb	$13, %al
				call	_kernel_exc_hdr
				popal
				add		$4, %esp
				iret


				.global	_kernel_vector_014
_kernel_vector_014:
				pushal
				movb	$14, %al
				movl	32(%esp), %ebx		/* erro code */
				call	_kernel_exc_hdr
				popal
				add		$4, %esp
				iret

/* 予約 */
				.global	_kernel_vector_015
_kernel_vector_015:
				pushal
				movb	$15, %al
				call	_kernel_exc_hdr
				popal
				iret

/* コプロセッサ・エラー */
				.global	_kernel_vector_016
_kernel_vector_016:
				pushal
				movb	$16, %al
				call	_kernel_exc_hdr
				popal
				iret



				.end


/* end of file */

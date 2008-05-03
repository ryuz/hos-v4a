/** 
 *  Hyper Operating System V4 Advance
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



				.code32
				.text


/************************************************
  CPU 例外ハンドラ
 ************************************************/
				.global	__kernel_exc_hdr
__kernel_exc_hdr:
				ret





/* 0除算 */
				.global	__kernel_vector_000
__kernel_vector_000:
				pushal
				movb	$0, %al
				call	__kernel_exc_hdr
				popal
				iret


/* デバッガ */
				.global	__kernel_vector_001
__kernel_vector_001:
				pushal
				movb	$1, %al
				call	__kernel_exc_hdr
				popal
				iret

/* NMI */
				.global	__kernel_vector_002
__kernel_vector_002:
				pushal
				movb	$2, %al
				call	__kernel_exc_hdr
				popal
				iret

/* break point */
				.global	__kernel_vector_003
__kernel_vector_003:
				pushal
				movb	$3, %al
				call	__kernel_exc_hdr
				popal
				iret

/* over flow */
				.global	__kernel_vector_004
__kernel_vector_004:
				pushal
				movb	$4, %al
				call	__kernel_exc_hdr
				popal
				iret

/* bound check */
				.global	__kernel_vector_005
__kernel_vector_005:
				pushal
				movb	$5, %al
				call	__kernel_exc_hdr
				popal
				iret

/* 無効オペコード */
				.global	__kernel_vector_006
__kernel_vector_006:
				pushal
				movb	$6, %al
				call	__kernel_exc_hdr
				popal
				iret

				.global	__kernel_vector_007
__kernel_vector_007:
				pushal
				movb	$7, %al
				call	__kernel_exc_hdr
				popal
				iret

/* ダブル・フォールト */
				.global	__kernel_vector_008
__kernel_vector_008:
				pushal
				movb	$8, %al
				movl	32(%esp), %ebx		/* erro code */
				call	__kernel_exc_hdr
				popal
				add		$4, %esp
				iret


				.global	__kernel_vector_009
__kernel_vector_009:
				pushal
				movb	$9, %al
				call	__kernel_exc_hdr
				popal
				iret


				.global	__kernel_vector_010
__kernel_vector_010:
				pushal
				movb	$10, %al
				movl	32(%esp), %ebx		/* erro code */
				call	__kernel_exc_hdr
				popal
				add		$4, %esp
				iret


				.global	__kernel_vector_011
__kernel_vector_011:
				pushal
				movb	$11, %al
				movl	32(%esp), %ebx		/* erro code */
				call	__kernel_exc_hdr
				popal
				add		$4, %esp
				iret


				.global	__kernel_vector_012
__kernel_vector_012:
				pushal
				movb	$12, %al
				movl	32(%esp), %ebx		/* erro code */
				call	__kernel_exc_hdr
				popal
				add		$4, %esp
				iret

/* 一般保護例外 */
				.global	__kernel_vector_013
__kernel_vector_013:
				pushal
				movl	32(%esp), %ebx		/* erro code */
				movb	$13, %al
				call	__kernel_exc_hdr
				popal
				add		$4, %esp
				iret


				.global	__kernel_vector_014
__kernel_vector_014:
				pushal
				movb	$14, %al
				movl	32(%esp), %ebx		/* erro code */
				call	__kernel_exc_hdr
				popal
				add		$4, %esp
				iret

				.global	__kernel_vector_015
__kernel_vector_015:
				pushal
				movb	$15, %al
				call	__kernel_exc_hdr
				popal
				iret

				.global	__kernel_vector_016
__kernel_vector_016:
				pushal
				movb	$16, %al
				call	__kernel_exc_hdr
				popal
				iret



				.end


/* end of file */

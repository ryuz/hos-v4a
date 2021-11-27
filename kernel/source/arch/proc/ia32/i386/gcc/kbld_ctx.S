/**
 *  Hyper Operating System V4 Advance
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#define _MACRO_ONLY
#include "procatr.h"
#include "irc.h"

				.extern	_kernel_int_hdr
				.extern _kernel_exc_hdr

				.global	_kernel_ia32_build_trap_context
				.global	_kernel_ia32_return_from_trap

				.code32
				.text

/****************************************************
  %jp{例外/割込みコンテキストの作成(例外要因共通部)}
  void _kernel_ia32_build_trap_context(void)
 ****************************************************/
_kernel_ia32_build_trap_context:

			/* %jp{割込みコンテキスト保存域を確保} */
			subl	$_KERNEL_IA32_PROC_ICTX_ALCSIZE, %esp

			/*
			 * %jp{汎用レジスタを退避}
			 */
			movl	%eax, _KERNEL_IA32_PROC_ICTX_EAX(%esp)
			movl	%ebp, _KERNEL_IA32_PROC_ICTX_EBP(%esp)
			movl	%edi, _KERNEL_IA32_PROC_ICTX_EDI(%esp)
			movl	%esi, _KERNEL_IA32_PROC_ICTX_ESI(%esp)
			movl	%edx, _KERNEL_IA32_PROC_ICTX_EDX(%esp)
			movl	%ecx, _KERNEL_IA32_PROC_ICTX_ECX(%esp)
			movl	%ebx, _KERNEL_IA32_PROC_ICTX_EBX(%esp)

			/*
			 * %jp{例外/割込み処理呼び出し}
			 */
			/*  %jp{callee-savedレジスタ(edi)に例外番号をセット} */
			movl	_KERNEL_IA32_PROC_ICTX_EXCNO(%esp), %edi
			/* %jp{callee-savedレジスタ(esi)に例外コンテキストをセット} */
			movl	%esp, %esi
			/*  %jp{外部割込みの場合は, _kernel_int_hdrを呼び出し,
				例外の場合は, _kernel_exc_hdrを呼び出す。
				_kernel_int_hdr, _kernel_exc_hdr内でcallee-saved
				レジスタを破壊するためcallee-savedレジスタが
				呼び出し後に保存されることを前提にはできない}
			*/
			cmpl	$_KERNEL_IRC_PIC1_VECT, %edi
			jl	call_exc_hdr
			call	_kernel_int_hdr  /* %jp{割込み処理実行} */
			jmp	ret_from_trap
call_exc_hdr:
			call	_kernel_exc_hdr  /* %jp{CPU例外処理実行} */
ret_from_trap:
			/* %jp{例外/割込み出口処理を継続実行} */


/************************************************
  %jp{例外/割込み出口処理}
  void _kernel_ia32_return_from_trap(void)
 ************************************************/
_kernel_ia32_return_from_trap:

			/*
			 * %jp{汎用レジスタを復元}
			 */
			movl	_KERNEL_IA32_PROC_ICTX_EBX(%esp), %ebx
			movl	_KERNEL_IA32_PROC_ICTX_ECX(%esp), %ecx
			movl	_KERNEL_IA32_PROC_ICTX_EDX(%esp), %edx
			movl	_KERNEL_IA32_PROC_ICTX_ESI(%esp), %esi
			movl	_KERNEL_IA32_PROC_ICTX_EDI(%esp), %edi
			movl	_KERNEL_IA32_PROC_ICTX_EBP(%esp), %ebp
			movl	_KERNEL_IA32_PROC_ICTX_EAX(%esp), %eax

			/* %jp{例外番号/エラーコードを含めコンテキスト保存域を解放} */
			addl	$_KERNEL_IA32_PROC_ICTX_RELSIZE, %esp

			iret  /* %jp{例外から復帰} */



			.end


/* end of file */

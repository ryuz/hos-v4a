/** 
 *  Hyper Operating System V4 Advance
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



				.code32
				.text


/************************************************
  実行コンテキストの切替
  void _kernel_swi_ctx(
			_KERNEL_T_CTXCB *pk_ctxinf_nxt,		4(%esp) : 切り替えるコンテキスト
			_KERNEL_T_CTXCB *pk_ctxinf_now)		8(%esp) : 現在のコンテキストの保存先
 ************************************************/
				.global	_kernel_swi_ctx
_kernel_swi_ctx:
				movl	4(%esp), %eax
				movl	8(%esp), %ecx
				pushl	%ebx
				pushl	%esi
				pushl	%edi
				pushl	%ebp
				movl	%esp, 0(%ecx)
				
				movl	0(%eax), %esp
				popl	%ebp
				popl	%edi
				popl	%esi
				popl	%ebx
				ret


				.end


; end of file


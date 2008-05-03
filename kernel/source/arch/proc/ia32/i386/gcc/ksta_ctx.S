/** 
 *  Hyper Operating System V4 Advance
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



				.code32
				.text


/************************************************
  実行コンテキストの開始
  void _kernel_sta_ctx(
			_KERNEL_T_CTXCB *pk_ctxcb)			4(%esp) : 現在のコンテキストの保存先
 ************************************************/
				.global	_kernel_sta_ctx
_kernel_sta_ctx:
				movl	4(%esp), %eax
				movl	0(%eax), %esp
				popl	%ebp
				popl	%edi
				popl	%esi
				popl	%ebx
				ret


				.end


; end of file


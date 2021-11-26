/** 
 *  Hyper Operating System V4 Advance
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#define _MACRO_ONLY
#include "procatr.h"

				.code32
				.text


/************************************************
  %jp{実行コンテキストの作成}
  void _kernel_cre_ctx(
			_KERNEL_T_CTXCB *pk_ctxcb,	4(%esp)   : %jp{作成するコンテキスト}
			VP             isp,		8(%esp)   : %jp{スタックポインタ}
			FP             entry,		12(%esp)  : %jp{実行アドレス}
			VP_INT         par1,		16(%esp)  : %jp{実行時パラメータ1}
			VP_INT         par2)		20(%esp)  : %jp{実行時パラメータ2}
 ************************************************/
				.global	_kernel_cre_ctx
_kernel_cre_ctx:
				movl	8(%esp), %eax	/* %jp{スタックを取り出し} */
				/* %jp{スタック上にコンテキスト保存領域を確保} */
				subl	$_KERNEL_IA32_PROC_TSKCTX_SIZE, %eax

				/* %jp{eflags} */
				movl	$_KERNEL_IA32_INITIAL_EFLAGS, %ecx
				movl	%ecx, _KERNEL_IA32_PROC_TSKCTX_EFLAGS(%eax)

				/* %jp{リターンアドレス} */
				movl	$ctx_entry, %ecx
				movl	%ecx, _KERNEL_IA32_PROC_TSKCTX_RETADDR(%eax)

				/* %jp{実行アドレス(ebx)} */
				movl	12(%esp), %ecx
				movl	%ecx, _KERNEL_IA32_PROC_TSKCTX_EBX(%eax)

				/* %jp{実行時パラメータ1(esi)} */
				movl	16(%esp), %ecx
				movl	%ecx, _KERNEL_IA32_PROC_TSKCTX_ESI(%eax)

				/* %jp{実行時パラメータ2(edi)} */
				movl	20(%esp), %ecx
				movl	%ecx, _KERNEL_IA32_PROC_TSKCTX_EDI(%eax)

				/* %jp{作成するコンテキスト} */
				movl	4(%esp), %ecx
				movl	%eax, 0(%ecx)

				ret


/************************************************
  %jp{実行コンテキストエントリーアドレス}
 ************************************************/
ctx_entry:
				pushl	%edi		/* %jp{実行時パラメータ2} */
				pushl	%esi		/* %jp{実行時パラメータ1} */
				call	*%ebx


				.end


/* end of file */

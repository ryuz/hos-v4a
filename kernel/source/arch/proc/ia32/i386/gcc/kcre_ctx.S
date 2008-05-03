/** 
 *  Hyper Operating System V4 Advance
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


				.code32
				.text


/************************************************
  実行コンテキストの作成
  void _kernel_cre_ctx(
			_KERNEL_T_CTXCB *pk_ctxcb,	4(%esp)   : 作成するコンテキスト
			VP             isp,			8(%esp)   : スタックポインタ
			FP             entry,		12(%esp)  : 実行アドレス
			VP_INT         par1,		16(%esp)  : 実行時パラメータ1
			VP_INT         par2)		20(%esp)  : 実行時パラメータ2
 ************************************************/
				.global	_kernel_cre_ctx
_kernel_cre_ctx:
				movl	8(%esp), %eax		/* スタックを取り出し */
				subl	$20, %eax
				movl	$ctx_entry, %ecx	/* リターンアドレス */
				movl	%ecx, 16(%eax)		/* ret */
				movl	12(%esp), %ecx		/* 実行アドレス */
				movl	%ecx, 12(%eax)		/* ebx */
				movl	16(%esp), %ecx		/* 実行時パラメータ1 */
				movl	%ecx, 8(%eax)		/* esi */
				movl	20(%esp), %ecx		/* 実行時パラメータ2 */
				movl	%ecx, 4(%eax)		/* edi */
				movl	4(%esp), %ecx		/* 作成するコンテキスト */
				movl	%eax, 0(%ecx)
				ret


/************************************************
  実行コンテキストエントリーアドレス
 ************************************************/
ctx_entry:
				pushl	%edi				/* 実行時パラメータ2 */
				pushl	%esi				/* 実行時パラメータ1 */
				call	*%ebx


				.end


/* end of file */

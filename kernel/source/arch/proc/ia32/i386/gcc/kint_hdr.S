/**
 *  Hyper Operating System V4 Advance
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#define _MACRO_ONLY
#include "procatr.h"

				.extern	_kernel_sta_inh
				.extern	_kernel_exe_inh
				.extern	_kernel_end_inh


				.code32
				.text


/********************************************************************
%jp{割込みハンドラ eax: 例外番号 4(%esp):例外コンテキストの先頭アドレス}
 ********************************************************************/
				.global	_kernel_int_hdr
_kernel_int_hdr:

				/*
				 * %jp{多重割込み判定}
				 */
				/* %jp{レジスタ使用用途
				       eax: 割込みコンテキスト制御ブロック
					    例外番号取得, 例外番号格納
				       edx: intcnt(割込み多重度)
				       ecx: _kernel_int_hdrエントリ時スタックアドレス}
				*/

				movl	%esp, %ecx /* %jp{スタック値保存} */

				/* %jp{割込みコンテキスト制御ブロック} */
				movl	$_kernel_ictxcb, %eax
				/* %jp{intcnt読込み} */
				movl	_KERNEL_IA32_PROC_ICTXCB_INTCNT(%eax), %edx
				cmpl	$0, %edx
				/* %jp{多重割込みの場合は, multiple_int にジャンプ} */
				jne	multiple_int

				/*
				 * %jp{スタック入れ替え}
				 */

				/* %jp{割込みスタックロード} */
				movl	_KERNEL_IA32_PROC_ICTXCB_ISP(%eax), %esp
				/* %jp{割込みスタックの底にタスクスタックポインタ保存} */
				pushl	%ecx

				/* %jp{割込み開始(非タスクコンテキストへの遷移)処理} */
				call	_kernel_sta_inh

				movl	0(%esp), %ecx  /* %jp{タスクスタック値取得} */

multiple_int:
				/* %jp{割込みコンテキスト制御ブロック} */
				movl	$_kernel_ictxcb, %eax
				/* %jp{intcnt読込み} */
				movl	_KERNEL_IA32_PROC_ICTXCB_INTCNT(%eax), %edx
				addl	$1, %edx /* %jp{intcntインクリメント} */
				/* %jp{intcnt更新} */
				movl	%edx, _KERNEL_IA32_PROC_ICTXCB_INTCNT(%eax)

				/* %jp{%ecxは本サブルーチンエントリ時の
					スタックポインタを指す}
				 */
				movl	4(%ecx), %eax  /* %jp{割込みコンテキスト取得} */
				/* %jp{例外番号取得} */
				movl	_KERNEL_IA32_PROC_ICTX_EXCNO(%eax), %eax

				/* %jp{割込みハンドラ実行, 第1引数:例外番号} */
				pushl	%eax /* %jp{例外番号をスタックに保存} */
				call	_kernel_exe_inh
				addl	$4, %esp  /* %jp{引数を除去} */

				/*
				 * %jp{割込み出口処理での多重割込み判定}
				 */

				/* %jp{割込み多重度を減算} */
				/*
				   %jp{	callee-savedレジスタに保存しているので
					割込みコンテキスト制御ブロックからintcntを
					読み直す必要は無い}
				 */
				/* %jp{割込みコンテキスト制御ブロック} */
				movl	$_kernel_ictxcb, %eax
				/* %jp{intcnt読込み} */
				movl	_KERNEL_IA32_PROC_ICTXCB_INTCNT(%eax), %edx
				subl	$1, %edx /* %jp{intcntデクリメント} */
				/* %jp{intcnt更新} */
				movl	%edx, _KERNEL_IA32_PROC_ICTXCB_INTCNT(%eax)

				/* %jp{多重割込みの場合は, finish_int_hdr にジャンプ} */
				cmpl	$0, %edx
				jne	finish_int_hdr

				/* %jp{割込みスタックからタスクスタックポインタ復元} */
				popl	%esp

				/* %jp{割込み終了(タスクコンテキストへの遷移)処理} */
				call	_kernel_end_inh

finish_int_hdr:

				ret  /* %jp{例外/割込み出口処理に移行} */



				.end


/* end of file */

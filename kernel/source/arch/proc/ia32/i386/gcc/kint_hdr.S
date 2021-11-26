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
%jp{割込みハンドラ edi: 例外番号 esi:例外コンテキストの先頭アドレス}
 ********************************************************************/
				.global	_kernel_int_hdr
_kernel_int_hdr:

				/*
				 * %jp{多重割込み判定}
				 */
				/* %jp{レジスタ使用用途
				       edi: 例外番号
				       ebx: 割込みコンテキスト制御ブロック
				       esi: intcnt(割込み多重度)
				       ecx: 初回割込み時のタスクスタック}
				 */
				/* %jp{割込みコンテキスト制御ブロック} */
				movl	$_kernel_ictxcb, %ebx
				/* %jp{intcnt読込み} */
				movl	_KERNEL_IA32_PROC_ICTXCB_INTCNT(%ebx), %esi
				cmpl	$0, %esi
				/* %jp{多重割込みの場合は, multiple_int にジャンプ} */
				jne	multiple_int

				/*
				 * %jp{スタック入れ替え}
				 */
				movl	%esp, %ecx /* %jp{タスクスタック値保存} */
				/* %jp{割込みスタックロード} */
				movl	_KERNEL_IA32_PROC_ICTXCB_ISP(%ebx), %esp
				/* %jp{割込みスタックの底にタスクスタックポインタ保存} */
				pushl	%ecx

				/* %jp{割込み開始(非タスクコンテキストへの遷移)処理} */
				call	_kernel_sta_inh

multiple_int:
				addl	$1, %esi /* %jp{intcntインクリメント} */
				/* %jp{intcnt更新} */
				movl	%esi, _KERNEL_IA32_PROC_ICTXCB_INTCNT(%ebx)

				/* %jp{割込みハンドラ実行, 第1引数:割込み要因} */
				pushl	%edi /* %jp{例外番号をスタックに保存} */
				call	_kernel_exe_inh
				add	$4, %esp  /* %jp{引数を除去} */

				/*
				 * %jp{割込み出口処理での多重割込み判定}
				 */

				/* %jp{割込み多重度を減算} */
				/*
				   %jp{	callee-savedレジスタに保存しているので
					割込みコンテキスト制御ブロックからintcntを
					読み直す必要は無い}
				 */
				subl	$1, %esi /* %jp{intcntデクリメント} */
				/* %jp{intcnt更新} */
				movl	%esi, _KERNEL_IA32_PROC_ICTXCB_INTCNT(%ebx)

				/* %jp{多重割込みの場合は, finish_int_hdr にジャンプ} */
				cmpl	$0, %esi
				jne	finish_int_hdr

				/* %jp{割込みスタックからタスクスタックポインタ復元} */
				popl	%esp

				/* %jp{割込み終了(タスクコンテキストへの遷移)処理} */
				call	_kernel_end_inh

finish_int_hdr:

				ret  /* %jp{例外/割込み出口処理に移行} */



				.end


/* end of file */

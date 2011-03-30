/**
 *  Hyper Operating System V4 Advance
 *
 * Copyright (C) 1998-2011 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


				.text
				.align	2

				.global	_kernel_dsp_tsk

/************************************************
  PendSV ハンドラ
 ************************************************/
				.global	_kernel_pendsv_handler
				.code	16
				.thumb_func
				.type	_kernel_pendsv_handler, %function
_kernel_pendsv_handler:
				/* 割り込み禁止 */
				cpsid	i

				/* リターンアドレス変更 */
				mrs		r0, psp
				ldr		r1, [r0, #24]
				ldr		r2, =pendsv_ret_addr
				str		r1, [r2]

				ldr		r1, =_kernel_pendsv_proc
				str		r1, [r0, #24]

				/* スレッドモードへの復帰 */
				bx		lr

				.size	_kernel_pendsv_handler, .-_kernel_pendsv_handler


				.thumb_func
				.type	_kernel_pendsv_proc, %function
_kernel_pendsv_proc:
				push	{r0, r1}
				mrs		r0, apsr
				push	{r0, r1, r2, r3}
				mov		r0, r12
				push	{r0, lr}

				/* リターンアドレス格納 */
				ldr		r0, =pendsv_ret_addr
				ldr		r1, [r0]
				add		r1, r1, #1
				str		r1, [sp, #28]

				/* 遅延ディスパッチ */
				blx		_kernel_dsp_tsk

				cpsie	i

				pop		{r0, r1}
				mov		r12, r0
				mov		lr, r1
				pop		{r0, r1, r2, r3}
				msr		apsr, r0
				pop		{r0, pc}

				.size	_kernel_pendsv_proc, .-_kernel_pendsv_proc


				.comm	pendsv_ret_addr, 4, 4

				.end


; end of file


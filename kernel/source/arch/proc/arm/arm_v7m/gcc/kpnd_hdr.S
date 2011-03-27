/**
 *  Hyper Operating System V4 Advance
 *
 * Copyright (C) 1998-2011 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


				.syntax unified

				.text
				.align	2

				.global	_kernel_dsp_tsk

/************************************************
  PendSV ハンドラ
 ************************************************/
				.global	_kernel_pendsv_handler
				.thumb
				.thumb_func
				.type	_kernel_pendsv_handler, %function
_kernel_pendsv_handler:
				/* 割り込み禁止 */
				cpsid	i

				/* スレッドモードへ */
				mrs		r0, control
				bic		r0, r0, #1
				msr		control, r0
				isb

				/* 遅延ディスパッチ */
				blx		_kernel_dsp_tsk

				/* ハンドラモードへ */
				mrs		r0, control
				orr		r0, r0, #1
				msr		control, r0
				isb

				/* 割り込み許可 */
				cpsie	i

				/* スレッドモードへの復帰 */
				movw	lr, #0xfffd
				movt	lr, #0xffff
				bx		lr

				.size	_kernel_pendsv_handler, .-_kernel_pendsv_handler


				.end


; end of file


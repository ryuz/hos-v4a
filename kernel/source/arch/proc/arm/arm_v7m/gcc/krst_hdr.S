/**
 *  Hyper Operating System V4 Advance
 *
 * Copyright (C) 1998-2011 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

				.syntax unified

				.text
				.align	2

				.extern		___data
				.extern		___data_end
				.extern		___bss
				.extern		___bss_end
				.extern		main
				.global		main

/************************************************
  リセットハンドラ
 ************************************************/
				.global	_kernel_reset_handler
				.thumb
				.thumb_func
				.type	_kernel_reset_handler, %function
_kernel_reset_handler:
				/* PSPへ切り替え */
				mov		r1, sp
				mrs		r0, control
				orr		r0, r0, #2
				msr		control, r0
				isb
				mov		sp, r1

				/* PendSV 優先度設定 */
				movw	r0, #0xed20
				movt	r0, #0xe000
				ldr		r1, [r0]
				orr		r1, r1, #0x00ff0000
				str		r1, [r0]

				/* DATA領域のコピー */
				movw	r0, #:lower16:___data_rom
				movt	r0, #:upper16:___data_rom
				movw	r1, #:lower16:___data
				movt	r1, #:upper16:___data
				movw	r2, #:lower16:___data_end
				movt	r2, #:upper16:___data_end

data_loop:
				ldr		r3, [r0]
				add		r0, r0, #4
				str		r3, [r1]
				add		r1, r1, #4
				cmp		r1, r2
				bcc		data_loop

				/* BSS領域の初期化 */
				movw	r0, #:lower16:___bss
				movt	r0, #:upper16:___bss
				movw	r1, #:lower16:___bss_end
				movt	r1, #:upper16:___bss_end
				mov		r2, #0
bss_loop:
				str		r2, [r0]
				add		r0, r0, #4
				cmp		r0, r1
				bcc		bss_loop

				/* main関数の呼び出し */
				blx		main
end_loop:
				b		end_loop


				.size	_kernel_reset_handler, .-_kernel_reset_handler


				.end


; end of file


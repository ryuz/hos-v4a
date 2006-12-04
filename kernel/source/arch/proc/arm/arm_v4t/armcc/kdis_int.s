; --------------------------------------------------------------------------- 
;  Hyper Operating System V4 Advance
;   %jp{コンテキスト制御(ARM v4t アーキテクチャ)}%en{ARM v4t}
;
;  Copyright (C) 1998-2006 by Project HOS
;  http://sourceforge.jp/projects/hos/
; --------------------------------------------------------------------------- 



				INCLUDE	arm_v4t.inc



				PRESERVE8
				AREA	code, CODE, READONLY

				ALIGN
				CODE32

; -----------------------------------------------
;  割り込み禁止
;  void _kernel_dis_int(void)
; -----------------------------------------------
				EXPORT	_kernel_dis_int
_kernel_dis_int
				mrs 	r0, cpsr					; cpsr取得
				orr		r0, r0, #F_Bit:OR:I_Bit		; FビットとIビットを設定
				msr 	cpsr_c, r0					; cpsr設定
				bx		lr							; リターン


				END


; end of file

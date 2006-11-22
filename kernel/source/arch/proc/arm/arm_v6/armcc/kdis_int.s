; --------------------------------------------------------------------------- 
;  Hyper Operating System V4 Advance
;   %en{コンテキスト制御(ARM v4t アーキテクチャ)}%jp{ARM v4t}
;
;  Copyright (C) 1998-2006 by Project HOS
;  http://sourceforge.jp/projects/hos/
; --------------------------------------------------------------------------- 



F_Bit			EQU 	0x40		; F ビット
I_Bit			EQU 	0x80		; I ビット

				
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
				cpsid	fi							; 割り込み禁止
				bx		lr							; リターン


				END


; end of file

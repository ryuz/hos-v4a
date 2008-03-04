; ---------------------------------------------------------------------------
;  Hyper Operating System V4 Advance
;   %jp{割り込みハンドラ(MN1030シリーズ用}%en{MN1030}
;
;  Copyright (C) 1998-2007 by Project HOS
;  http://sourceforge.jp/projects/hos/
; ---------------------------------------------------------------------------



				GLOBAL	__kernel_ictxcb
				GLOBAL	_0_kernel_sta_inh
				GLOBAL	_0_kernel_end_inh
				GLOBAL	_0_kernel_exe_inh
 

.text			SECTION	"ax", PROGBITS, PUBLIC

; --------------------------------------
;  Interrupt Handler
; --------------------------------------
				GLOBAL	__kernel_int_hdr
__kernel_int_hdr:
		; ---- レジスタ退避
				movm	[other], (sp)					; レジスタ退避
				
		; ---- 多重割込み判定
				mov		__kernel_ictxcb, a0
				movbu	(4, a0), d0
				add		-4, sp
				add		1, d0
				movbu	d0, (4, a0)
				cmp		1, d0
				bne		multiple_int
				
		; ---- 割り込み用スタックに入れ替え
				mov		(0, a0), a1
				mov		sp, a0 							; タスクのSPを保存
				mov		a1, sp
				add		-8, sp
				mov		a0, (4, sp)
				
		; ---- 割り込み処理
				call	_0_kernel_sta_inh				; 割り込み開始
				
		; ---- 割り込みハンドラ実行
				clr		d0
				call	_0_kernel_exe_inh
				
		; ---- 割り込み処理の終了設定
				mov		(4, sp), a0
				clr		d0
				mov		a0, sp							; スタック復帰
				movbu	d0, (__kernel_ictxcb+4)			; ネストカウンタクリア
				
		; ---- 割込みマスクレベルの復帰
				mov		(36, sp), d0
				and		0x0700, d0
				mov		d0, psw
				
		; ---- 遅延ディスパッチ処理
				call	_0_kernel_end_inh				; 割り込み終了処理
				
		; ---- 復帰処理
return_int:
				add		4, sp
				movm	(sp), [other]					; レジスタ退避
				rti


		; ---- 多重割り込み処理
multiple_int:
		; ---- 割り込みハンドラ実行
				clr		d0
				call	_0_kernel_exe_inh
				
		; ---- 割り込みカウンタ復帰
				movbu	(__kernel_ictxcb+4), d0
				add		-1, d0
				movbu	d0, (__kernel_ictxcb+4)

				bra		return_int						; 復帰処理


				END


; end of file

; --------------------------------------------------------------------------- 
;  Hyper Operating System V4 Advance
;   %jp{IRQハンドラ(ARM V4T アーキテクチャ用)}%en{IRQ handler for ARM V4T}
;
;  Copyright (C) 1998-2006 by Project HOS
;  http://sourceforge.jp/projects/hos/
; --------------------------------------------------------------------------- 


				INCLUDE	arm_v4t.inc


				IMPORT	_kernel_ictxcb
				IMPORT	_kernel_sta_inh
				IMPORT	_kernel_end_inh
				IMPORT	_kernel_exe_inh
				EXPORT	_kernel_irq_hdr						; IRQハンドラ


				PRESERVE8
				AREA	code, CODE, READONLY
				CODE32

; ----------------------------------------------
;  IRQ ハンドラ
; ----------------------------------------------
_kernel_irq_hdr
			; ---- レジスタ退避
				msr		cpsr_c, #Mode_SYS:OR:F_Bit:OR:I_Bit		; SYSモードに移行
				stmfd	sp!, {r0-r3, r12, lr}					; SYSモードの汎用レジスタ退避
				msr		cpsr_c, #Mode_IRQ:OR:F_Bit:OR:I_Bit		; IRQモードに移行
				mov		r0, lr									; lr_irq 取り出し
				mrs		r1, spsr								; spsr_irq 取り出し
				msr		cpsr_c, #Mode_SYS:OR:F_Bit:OR:I_Bit		; SYSモードに移行
				stmfd	sp!, {r0, r1}							; lr_irq, spsr_irq退避
				
			; ---- 割込みマスク設定
				ldr		r0, =_kernel_ictxcb
				ldr		r3, [r0, #ICTXCB_IMSK]					; 古いimsk値を取り出し
				orr		r1, r3, #I_Bit							; 割込みマスク
				strb	r1, [r0, #ICTXCB_IMSK]					; imsk値を設定
				
			; ---- 多重割込み判定
				ldrb	r1, [r0, #ICTXCB_INTCNT]				; 割り込みネストカウンタ値取得
				add		r1, r1, #1								; 割り込みネストカウンタインクリメント
				strb	r1, [r0, #ICTXCB_INTCNT]				; 割り込みネストカウンタ設定
				cmp		r1, #1
				bne		multiple_int							; 多重割り込みなら分岐
				
			; ---- SPを割込みコンテキストのものに切替え
				mov		r1, sp									; タスクのSPを保存
				ldr		sp, [r0, #ICTXCB_ISP]					; 割り込み用スタックに切り替え
				stmfd	sp!, {r1, r3}							; タスクのSPと旧imask保存
				
			; ---- 割込み開始処理
				bl		_kernel_sta_inh							; 割り込み開始
				
			; ---- 割込みハンドラ実行
				mov		r0, #INHNO_IRQ
				bl		_kernel_exe_inh
				
			; ---- 割込み処理の終了設定
				ldmfd	sp!, {r1, r3}							; 汎用レジスタ復帰
				mov		sp, r1									; SPを元のコンテキストのものに戻す
				ldr		r0, =_kernel_ictxcb						; 割り込みネストカウンタのアドレス取得
				mov		r1, #0									; 割り込みネストカウンタを0に戻す
				strb	r1, [r0, #ICTXCB_INTCNT]				; 割り込みネストカウンタ値設定
				
			; ---- 割込みマスク値復帰処理
				strb	r3, [r0, #ICTXCB_IMSK]					; マスク値復帰
				
			; ---- 割込み終了処理
				bl		_kernel_end_inh							; 割り込み終了処理
			
			; ---- 復帰先割込みマスク設定
				ldr		r0, =_kernel_ictxcb
				ldr		r1, [sp, #4]							; spsr_irq 値取り出し
				tst		r1, #I_Bit								; 割禁と同時にIRQが入る場合があるのでケア
				ldrbeq	r0, [r0, #ICTXCB_IMSK]					; この時点でのimsk値取り出し
				biceq	r1, r1, #F_Bit:OR:I_Bit
				orreq	r1, r1, r0
				streq	r1, [sp, #4]							; spsr_irq にimsk値反映

return_int
			; ---- 復帰処理
				ldmfd	sp!, {r0, r1}							; lr_irq, spsr_irq 復帰
				msr		cpsr_c, #Mode_IRQ:OR:F_Bit:OR:I_Bit		; IRQモードに移行
				mov		lr, r0									; lr_irq 復帰
				msr		spsr_csxf, r1 							; spsr_irq 復帰
				msr		cpsr_c, #Mode_SYS:OR:F_Bit:OR:I_Bit		; SYSモードに移行
				ldmfd	sp!, {r0-r3, r12, lr}					; SYSモードの汎用レジスタ復帰
				msr		cpsr_c, #Mode_IRQ:OR:F_Bit:OR:I_Bit		; IRQモードに移行
				subs	pc, lr, #4								; 割込み復帰


			; ---- 多重割り込み処理
multiple_int
			; ---- スタックを8バイトアライメントに移動
				mov		r1,  sp									; 割り込み発生時のSYSモードのSPに8の倍数の保証されないので
				bic		sp, sp, #0x7
				stmfd	sp!, {r0, r1}							; タスクのSPを割り込み用スタックに保存(8の倍数になるようにr1も)
				
			; ---- 割り込みハンドラ実行
				mov		r0, #INHNO_IRQ
				bl		_kernel_exe_inh

			; ---- スタックアライメント復帰
				ldmfd	sp!, {r0, r1}							; 汎用レジスタ復帰
				mov		sp, r1
				
			; ---- 割り込みカウンタ復帰
				ldrb	r1, [r0, #ICTXCB_INTCNT]
				add		r1, r1, #1
				strb	r1, [r0, #ICTXCB_INTCNT]
				b		return_int								; 復帰処理


				END


;  end of file

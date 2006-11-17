
; ---- プロセッサモード定義 ----
Mode_USR		EQU 	0x10		; USR モード
Mode_FIQ		EQU		0x11		; FIQ モード
Mode_IRQ		EQU 	0x12		; IRQ モード
Mode_SVC		EQU		0x13		; SVC モード
Mode_ABT		EQU		0x17		; ABT モード
Mode_UND		EQU		0x1b		; UND モード
Mode_SYS		EQU 	0x1f		; SYS モード
Mode_MASK		EQU 	0x1f		; モードビットマスク

; ---- フラグ定義 ----
T_Bit			EQU		0x20		; T ビット
F_Bit			EQU 	0x40		; F ビット
I_Bit			EQU 	0x80		; I ビット


; ---- 割り込みハンドラ番号 ----
INHNO_IRQ		EQU 	0
INHNO_FIQ		EQU 	1


				IMPORT	_kernel_int_isp
				IMPORT	_kernel_sta_inh
				IMPORT	_kernel_end_inh
				IMPORT	_kernel_exe_inh
				EXPORT	_kernel_int_armirq						; IRQハンドラ


				PRESERVE8
				AREA	inthdr_code, CODE, READONLY
				CODE32

; ----------------------------------------------
;  IRQ ハンドラ
; ----------------------------------------------
_kernel_int_armirq
			; ---- レジスタ退避
				msr		cpsr_c, #Mode_SYS:OR:F_Bit:OR:I_Bit		; SYSモードに移行
				stmfd	sp!, {r0-r3, r12, lr}					; SYSモードの汎用レジスタ退避
				msr		cpsr_c, #Mode_IRQ:OR:F_Bit:OR:I_Bit		; IRQモードに移行
				mov		r0, lr									; lr_irq 取り出し
				mrs		r1, spsr								; spsr_irq 取り出し
				msr		cpsr_c, #Mode_SYS:OR:F_Bit:OR:I_Bit		; SYSモードに移行
				stmfd	sp!, {r0, r1}							; lr_irq, spsr_irq退避
				
			; ---- 多重割込み判定
				ldr		r0, =_kernel_int_nst_cnt				; 割り込みネストカウンタのアドレス取得
				ldrb	r1, [r0]								; 割り込みネストカウンタ値取得
				subs	r1, r1, #1								; カウンタ減算(0判定が楽なのでマイナス方向にカウント)
				strb	r1, [r0]								; 割り込みネストカウンタ値設定
				bcs		multiple_int							; 多重割り込みなら分岐
				
			; ---- 割り込み用スタックに入れ替え
				ldr		r2, =_kernel_int_isp					; 割り込み用スタックの初期値アドレスを取得
				mov		r1, sp									; タスクのSPを保存
				ldr		sp, [r2]								; 割り込み用スタックに切り替え
				stmfd	sp!, {r0, r1}							; タスクのSPを割り込み用スタックに保存(8の倍数になるようにr1も)
				
			; ---- 割り込み処理
				bl		_kernel_sta_inh							; 割り込み開始
				
			; ---- 割り込みハンドラ実行
				mov		r0, #INHNO_IRQ
				bl		_kernel_exe_inh
				
			; ---- 割り込み処理の終了設定
				ldmfd	sp!, {r0, r1}							; 汎用レジスタ復帰
				mov		sp, r1									; スタックを戻す

				mov		r1, #0									; 割り込みネストカウンタを0に戻す
				strb	r1, [r0]								; 割り込みネストカウンタ値設定

			; ---- 遅延ディスパッチ処理
				bl		_kernel_end_inh							; 割り込み終了処理

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
				ldrb	r1, [r0]
				add		r1, r1, #1
				strb	r1, [r0]

				b		return_int								; 復帰処理



		        AREA data, DATA, ALIGN=0
_kernel_int_nst_cnt
		        DCB      0x00


				END


; --------------------------------------------------------------------------- 
;  End of file
; --------------------------------------------------------------------------- 

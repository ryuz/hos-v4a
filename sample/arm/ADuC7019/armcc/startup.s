
				EXPORT	Reset_Handler
				EXPORT	Undefined_Handler
				EXPORT	Swi_Handler
				EXPORT	Prefetch_Handler
				EXPORT	Abort_Handler
				IMPORT	_kernel_int_isp



; %jp{プロセッサモード定義}
Mode_USR		EQU 	0x10		; USR モード
Mode_FIQ		EQU		0x11		; FIQ モード
Mode_IRQ		EQU 	0x12		; IRQ モード
Mode_SVC		EQU		0x13		; SVC モード
Mode_ABT		EQU		0x17		; ABT モード
Mode_UND		EQU		0x1b		; UND モード
Mode_SYS		EQU 	0x1f		; SYS モード
Mode_MASK		EQU 	0x1f		; モードビットマスク

; %jp{フラグ定義}
T_Bit			EQU		0x20		; T ビット
F_Bit			EQU 	0x40		; F ビット
I_Bit			EQU 	0x80		; I ビット



				CODE32

				PRESERVE8
				AREA	Init, CODE, READONLY


; リセットハンドラ
Reset_Handler
		; --- SYSモード移行
				msr		cpsr_c, #Mode_SYS:OR:F_Bit:OR:I_Bit

		; --- スタック仮設定
				ldr		r0, =_kernel_int_isp
				ldr 	sp, [r0]
				
		; --- C言語コードにジャンプ
				IMPORT	__main
				bl		__main
end_loop
				b		end_loop




;  SWIハンドラ
Swi_Handler
				movs	pc, lr


;  Undefined ハンドラ
Undefined_Handler
				b		Undefined_Handler


;  Prefetch ハンドラ
Prefetch_Handler
				b		Prefetch_Handler


;  Abort ハンドラ
Abort_Handler
				b		Abort_Handler



				END


; end of file                                            

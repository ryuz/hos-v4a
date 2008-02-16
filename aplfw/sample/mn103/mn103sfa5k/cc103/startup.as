; ----------------------------------------------------------------------------
;  Hyper Operating System V4 Advance
;
;  Copyright (C) 2008 by Project HOS
; http://sourceforge.jp/projects/hos/
; ----------------------------------------------------------------------------



.text			SECTION	"ax", PROGBITS, PUBLIC
.rodata			SECTION	"a", PROGBITS, PUBLIC
				align	4
.MN.data		SECTION	"aw", NOBITS, PUBLIC
				align	4
.MN.romdata		SECTION	"a", PROGBITS, PUBLIC
				align	4
.MN.romdataend	SECTION	"a", NOBITS, PUBLIC
				align	4
.bss			SECTION	"aw", NOBITS, PUBLIC
				align	4
.MN.bssend		SECTION	"aw", NOBITS, PUBLIC
				align	4


stack			equ		0x00002000

IVAR0			equ		0x00008000
IVAR1			equ		0x00008004
IVAR2			equ		0x00008008
IVAR3			equ		0x0000800C
IVAR4			equ		0x00008010
IVAR5			equ		0x00008014
IVAR6			equ		0x00008018
IAGR			equ		0x00008a00



.text			SECTION

				global	_main, _0main
				global	__kernel_int_hdr

		; --- リセットハンドラ
reset_hdr
				mov		startup, a0
				jmp		(A0)

		; --- NMI ハンドラ
nmi_hdr
				bra		nmi_hdr
				nop
				nop
				nop
				nop

		; --- 割込みハンドラ
int_hdr
				jmp		__kernel_int_hdr


		; --- スタートアップ
startup
				mov		stack, a0
				mov		a0, sp
				
		; ---- 割り込みハンドラ登録
				mov		int_hdr, d0
				movhu	d0, (IVAR0)
				movhu	d0, (IVAR1)
				movhu	d0, (IVAR2)
				movhu	d0, (IVAR3)
				movhu	d0, (IVAR4)
				movhu	d0, (IVAR5)
				movhu	d0, (IVAR6)

		; ---- BSSクリア
				mov		.MN.bssend - .bss, d1
				cmp		0, d1
				ble		bss_clear_end
				mov		.bss, a0
				clr		d0
bss_clear_loop
				mov		d0, (a0) 
				inc4	a0
				add		-4, d1
				bgt		bss_clear_loop
bss_clear_end


		; ---- DATAコピー
				mov		.MN.romdataend - .MN.romdata, d1
				cmp		0, d1
				ble		data_copy_end
				mov		.MN.romdata, a0
				mov		.MN.data, a1
data_copy_loop
				mov		(a0), d0
				inc4	a0
				mov		d0, (a1)
				inc4	a1
				add		-4, d1
				bne		data_copy_loop
data_copy_end


		; ---- main関数コール
				call	_0main

_exit_loop		
				bra		_exit_loop
				nop
				nop
				nop
				nop


				END


; end of file

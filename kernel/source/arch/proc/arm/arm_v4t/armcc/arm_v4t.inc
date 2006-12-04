; --------------------------------------------------------------------------- 
;  Hyper Operating System V4 Advance
;   %jp{共通インクルードファイル(ARM V4T)}%en{ARM V4T}
;
;  Copyright (C) 1998-2006 by Project HOS
;  http://sourceforge.jp/projects/hos/
; --------------------------------------------------------------------------- 


; %jp{割込みハンドラ番号}%en{interruput handler number}
INHNO_IRQ		EQU 	0
INHNO_FIQ		EQU 	1


; %jp{_KERNEL_T_ICTXCB構造体オフセット}
ICTXCB_IMSK		EQU		0
ICTXCB_INTCNT	EQU		1
ICTXCB_ISP		EQU		4


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


				END

;  end of file

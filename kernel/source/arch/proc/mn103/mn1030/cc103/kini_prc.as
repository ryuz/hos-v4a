; ---------------------------------------------------------------------------
;  Hyper Operating System V4 Advance
;   %jp{コンテキスト制御(MN1030シリーズ用}%en{MN1030}
;
;  Copyright (C) 1998-2007 by Project HOS
;  http://sourceforge.jp/projects/hos/
; ---------------------------------------------------------------------------


.text			SECTION


; ----------------------------------------------------------------
;  %jp{プロセッサ固有の初期化}
;   void _kernel_ini_prc(void)
; ----------------------------------------------------------------
				GLOBAL	__kernel_ini_prc
				GLOBAL	_0_kernel_ini_prc
__kernel_ini_prc

_0_kernel_ini_prc	FUNCINFO __kernel_ini_prc, 0, []
				and		0x0700, psw		; IMビット以外クリア
				or		0x0700, psw		; IMビットセット
				retf



				END


; end of file

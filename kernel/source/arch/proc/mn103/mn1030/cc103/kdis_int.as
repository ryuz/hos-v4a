; ---------------------------------------------------------------------------
;  Hyper Operating System V4 Advance
;   %jp{コンテキスト制御(MN1030シリーズ用}%en{MN1030}
;
;  Copyright (C) 1998-2007 by Project HOS
;  http://sourceforge.jp/projects/hos/
; ---------------------------------------------------------------------------


.text			SECTION



; ----------------------------------------------------------------
;  割り込み禁止
;   void _kernel_dis_int(void)
; ----------------------------------------------------------------
				GLOBAL	__kernel_dis_int
				GLOBAL	_0_kernel_dis_int
__kernel_dis_int
_0_kernel_dis_int	FUNCINFO __kernel_dis_int, 0, []
				and		0xf7ff, psw		; IEビットクリア
				retf



				END


; end of file

; ---------------------------------------------------------------------------
;  Hyper Operating System V4 Advance
;   %jp{コンテキスト制御(MN1030シリーズ用}%en{MN1030}
;
;  Copyright (C) 1998-2007 by Project HOS
;  http://sourceforge.jp/projects/hos/
; ---------------------------------------------------------------------------


.text			SECTION



; ----------------------------------------------------------------
;  割り込み許可
;   void _kernel_ena_int(void)
; ----------------------------------------------------------------
				GLOBAL	__kernel_ena_int
				GLOBAL	_0_kernel_ena_int
__kernel_ena_int

_0_kernel_ena_int	FUNCINFO __kernel_ena_int, 0, []
				or		0x0800, psw		; IEビットセット
				retf



				END


; end of file

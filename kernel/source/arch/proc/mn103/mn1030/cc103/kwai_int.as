; ---------------------------------------------------------------------------
;  Hyper Operating System V4 Advance
;   %jp{コンテキスト制御(MN1030シリーズ用}%en{MN1030}
;
;  Copyright (C) 1998-2007 by Project HOS
;  http://sourceforge.jp/projects/hos/
; ---------------------------------------------------------------------------


.text			SECTION



; ----------------------------------------------------------------
; 割り込み待ち(CPUのアイドル処理)
;   void _kernel_wai_int(void);
; ----------------------------------------------------------------
				GLOBAL	__kernel_wai_int
				GLOBAL	_0_kernel_wai_int
__kernel_wai_int
_0_kernel_wai_int	FUNCINFO __kernel_wai_int, 0, []
				bra		_0_kernel_wai_int



				END


; end of file

; ---------------------------------------------------------------------------
;  Hyper Operating System V4 Advance
;   %jp{コンテキスト制御(MN1030シリーズ用}%en{MN1030}
;
;  Copyright (C) 1998-2007 by Project HOS
;  http://sourceforge.jp/projects/hos/
; ---------------------------------------------------------------------------


.text			SECTION



; ----------------------------------------------------------------
;  実行コンテキストのリスタート
;  void _kernel_rst_ctx(
;			UW             par1,		実行時パラメータ     [d0]
;			UW             par2,		実行時パラメータ     [d1]
;			FP             entry,		実行アドレス         [a0]
;			VP             isp)			初期スタックポインタ [a1]
; ----------------------------------------------------------------
				GLOBAL	__kernel_rst_ctx
				GLOBAL	_0_kernel_rst_ctx
__kernel_rst_ctx
_0_kernel_rst_ctx	FUNCINFO __kernel_rst_ctx, 0, []
				mov		a0, sp
				jmp		(a1)



				END


; end of file

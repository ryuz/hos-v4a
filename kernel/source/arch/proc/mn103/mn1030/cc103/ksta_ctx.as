; ---------------------------------------------------------------------------
;  Hyper Operating System V4 Advance
;   %jp{コンテキスト制御(MN1030シリーズ用}%en{MN1030}
;
;  Copyright (C) 1998-2007 by Project HOS
;  http://sourceforge.jp/projects/hos/
; ---------------------------------------------------------------------------


.text			SECTION



; ----------------------------------------------------------------
;  実行コンテキストの開始
;  void _kernel_sta_ctx(
;			_KERNEL_T_CTXCB *pk_ctxcb)			実行を開始するコンテキスト [a0]
; ----------------------------------------------------------------
				GLOBAL	__kernel_sta_ctx
				GLOBAL	_0_kernel_sta_ctx
__kernel_sta_ctx
_0_kernel_sta_ctx	FUNCINFO __kernel_sta_ctx, 16, [d2,d3,a2,a3]
				mov		(a0), a0		; %jp{次のsp取得}
				mov		a0, sp
				ret



				END


; end of file

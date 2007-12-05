; ---------------------------------------------------------------------------
;  Hyper Operating System V4 Advance
;   %jp{コンテキスト制御(MN1030シリーズ用}%en{MN1030}
;
;  Copyright (C) 1998-2007 by Project HOS
;  http://sourceforge.jp/projects/hos/
; ---------------------------------------------------------------------------


.text			SECTION



; ----------------------------------------------------------------
;  実行コンテキストの切替
;  void _kernel_swi_ctx(
;			_KERNEL_T_CTXCB *pk_ctxinf_nxt,		実行を開始するコンテキスト [a0]
;			_KERNEL_T_CTXCB *pk_ctxinf_now)		現在のコンテキストの保存先 [a1]
; ----------------------------------------------------------------
				GLOBAL	__kernel_swi_ctx
				GLOBAL	_0_kernel_swi_ctx
__kernel_swi_ctx
				movm	[d2,d3,a2,a3], (SP)
_0_kernel_swi_ctx	FUNCINFO __kernel_swi_ctx, 16, [d2,d3,a2,a3]
				mov		(a0), a3		; %jp{次のsp取得}
				mov		sp, a2
				mov		a2, (a1)		; %jp{現在のsp保存}
				mov		a3, sp
				ret



				END


; end of file

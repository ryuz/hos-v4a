; ---------------------------------------------------------------------------
;  Hyper Operating System V4 Advance
;   %jp{コンテキスト制御(MN1030シリーズ用}%en{MN1030}
;
;  Copyright (C) 1998-2007 by Project HOS
;  http://sourceforge.jp/projects/hos/
; ---------------------------------------------------------------------------


.text			SECTION



; ----------------------------------------------------------------
;  実行コンテキストエントリーアドレス
; ----------------------------------------------------------------
ctx_entry
				mov		d2, d0			; par1を設定
				mov		d3, d1			; par2を設定
				jmp		(a2)			; entry を実行


; ----------------------------------------------------------------
; 実行コンテキストの作成
; void _kernel_cre_ctx(
;			UW              par1,		実行時パラメータ1    [d0]
;			UW              par2,		実行時パラメータ2    [d1]
;			_KERNEL_T_CTXCB *pk_ctxcb,	作成するコンテキスト [a0]
;			VP              isp,		スタックポインタ     [a1]
;			FP              entry)		実行アドレス         [(4, sp)]
; ----------------------------------------------------------------
				GLOBAL	__kernel_cre_ctx
				GLOBAL	_0_kernel_cre_ctx
__kernel_cre_ctx
_0_kernel_cre_ctx	FUNCINFO __kernel_cre_ctx, 0, []
					add		-20, a1
					mov		a1, (a0)
					mov		(4, sp), a0				; entry取り出し
					mov		d0, (12, a1)			; d2位置にpar1格納
					mov		d1, (8, a1)				; d3位置にpar2格納
					mov		a0, (4, a1)				; a2位置にentry格納
					mov		ctx_entry, d0
					mov		d0, (16, a1)			; リターンアドレスにctx_entry格納
					retf



				END


; end of file

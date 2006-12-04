; --------------------------------------------------------------------------- 
;  Hyper Operating System V4 Advance
;   %jp{コンテキスト制御(ARM v4t アーキテクチャ)}%en{ARM v4t}
;
;  Copyright (C) 1998-2006 by Project HOS
;  http://sourceforge.jp/projects/hos/
; --------------------------------------------------------------------------- 


				PRESERVE8
				AREA	code, CODE, READONLY

				ALIGN
				CODE16

; -----------------------------------------------
;  実行コンテキストの作成
;  void _kernel_cre_ctx(
;			_KERNEL_T_CTXCB *pk_ctxcb,			/* r0   :作成するコンテキスト */
;			VP             isp,					/* r1   :スタックポインタ */
;			FP             entry,				/* r2   :実行アドレス */
;			VP_INT         par1,				/* r3   :実行時パラメータ */
;			VP_INT         par2)				/* sp[0]:実行時パラメータ */
; -----------------------------------------------
				EXPORT	_kernel_cre_ctx
_kernel_cre_ctx
				sub		r1, #36						; スタックを確保
				str		r2, [r1, #0]				; r4 部分にentryを設定
				str		r3, [r1, #4]				; r5 部分にpar1を設定
				ldr		r2, [sp, #0]				; par2を取り出し
				str		r2, [r1, #8]				; r6 部分にpar2を設定
				adr		r2, ctx_entry				; エントリーアドレス設定
				add		r2, #1						; Thumbモードアドレスとして設定
				str		r2, [r1, #32]				; lr 部分にエントリーアドレスを設定
				str		r1, [r0]					; ctxcb に新 sp を保存
				bx		lr							; リターン


; -----------------------------------------------
;  実行コンテキストエントリーアドレス
; -----------------------------------------------
ctx_entry	
				mov		r0, r5						; par1を設定
				mov		r1, r6						; par2を設定
				bx		r4							; entry を実行


				END


; end of file

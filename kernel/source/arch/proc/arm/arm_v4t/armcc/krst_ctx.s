; --------------------------------------------------------------------------- 
;  Hyper Operating System V4 Advance
;   %en{コンテキスト制御(ARM v4t アーキテクチャ)}%jp{ARM v4t}
;
;  Copyright (C) 1998-2006 by Project HOS
;  http://sourceforge.jp/projects/hos/
; --------------------------------------------------------------------------- 


				PRESERVE8
				AREA	code, CODE, READONLY

				ALIGN
				CODE32

; -----------------------------------------------
;  実行コンテキストのリスタート
;  void _kernel_rst_ctx(
;			VP_INT         par1,				/* r0   :実行時パラメータ */
;			VP_INT         par2,				/* r1   :実行時パラメータ */
;			FP             entry,				/* r2   :実行アドレス */
;			VP             isp)					/* r3   :スタックポインタ */
; -----------------------------------------------
				EXPORT	_kernel_rst_ctx
_kernel_rst_ctx
				mov		sp, r3						; スタックを初期値にリセット
				bx		r2							; エントリーアドレスから再開始


				END


; end of file

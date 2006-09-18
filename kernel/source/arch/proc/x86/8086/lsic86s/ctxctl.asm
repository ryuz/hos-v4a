; ---------------------------------------------------------------------------
;  HOS-V4 Advance
;     Intel 8086 LSI-C86 Small Model
;
;                                     Copyright (C) 1998-2006 by Project HOS
;                                     http://sourceforge.jp/projects/hos/
; ---------------------------------------------------------------------------


TEXT			CSEG


; -----------------------------------------------
;  %jp{割り込み禁止}
;  void _kernel_dis_int(void)
; -----------------------------------------------
_kernel_dis_int_::
				cli					; 割り込み禁止
				ret


; -----------------------------------------------
;  %jp{割り込み許可}
;  void _kernel_ena_int(void)
; -----------------------------------------------
_kernel_ena_int_::
				sti					; 割り込み許可
				ret


; -----------------------------------------------
;  Entry point
; -----------------------------------------------
ctx_entry:		
				mov		ax, dx		; 実行時パラメータ1を設定
				mov		bx, bp		; 実行時パラメータ2を設定
				jmp		cx			; 実行アドレスに分岐

; -----------------------------------------------
;  %jp{実行コンテキストの作成}
;  _kernel_cre_ctx(
;		_KERNEL_T_CTXCB *pk_ctxcb,		作成するコンテキスト (ax)
;		VP              isp,			初期スタックポインタ (bx)
;		FP              entry,			実行アドレス         (cx)
;		VP_INT          par1,			実行時パラメータ1    (dx)
;		VP_INT          par2)			実行時パラメータ2    ([sp+2].w)
; -----------------------------------------------
_kernel_cre_ctx_::
				sub		bx, 12
				mov		[bx], cx				; 実行アドレス      [cx]
				mov		[bx+2], dx				; 実行時パラメータ1 [dx]
				mov		dx, [sp+2]
				mov		[bx+4], dx				; 実行時パラメータ2 [bp]
				mov		[bx+10].w, ctx_entry	; リターンアドレス
				xchg	ax, bx
				mov		[bx], ax
				ret


; -----------------------------------------------
;  %jp{実行コンテキストの切替}
;  void _kernel_swi_ctx(
;		_KERNEL_T_CTXCB *pk_ctxcb_nxt,			切り替え先のコンテキスト [ax]
;		_KERNEL_T_CTXCB *pk_ctxcb_now)			現在のコンテキスト       [bx]
; -----------------------------------------------
_kernel_swi_ctx_::
				push	di
				push	si
				push	bp
				push	dx
				push	cx
				mov		[bx], sp
		; ---- このまま _kernel_sta_ctx に続ける

; -----------------------------------------------
;  %jp{実行コンテキストの開始}
;  void _kernel_sta_ctx(
;		_KERNEL_T_CTXCB *pk_ctxcb)				開始するコンテキスト [ax]
; -----------------------------------------------
_kernel_sta_ctx_::
				mov		bx, ax
				mov		sp, [bx]
				pop		cx
				pop		dx
				pop		bp
				pop		si
				pop		di
				ret


; end of file

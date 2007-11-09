

.text			SECTION


; ----------------------------------------------------------------
;  %jp{プロセッサ固有の初期化}
;   void _kernel_ini_prc(void)
; ----------------------------------------------------------------
				GLOBAL	__kernel_ini_prc
				GLOBAL	_0_kernel_ini_prc
__kernel_ini_prc

_0_kernel_ini_prc	FUNCINFO __kernel_ini_prc, 0, []
				and		0x0700, psw		; IMビット以外クリア
				or		0x0700, psw		; IMビットセット
				retf


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


; ----------------------------------------------------------------
; 割り込み待ち(CPUのアイドル処理)
;   void _kernel_wai_int(void);
; ----------------------------------------------------------------
				GLOBAL	__kernel_wai_int
				GLOBAL	_0_kernel_wai_int
__kernel_wai_int
_0_kernel_wai_int	FUNCINFO __kernel_wai_int, 0, []
				bra		_0_kernel_wai_int



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

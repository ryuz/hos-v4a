


				.global	_kernel_int_isp
				.global	_kernel_sta_inh
				.global	_kernel_end_inh
				.global	_kernel_exe_inh
				.global	_kernel_int
				

				.text
				.align	2


/************************************************
  IRQ ハンドラ
 ************************************************/
_kernel_int_irq:
			/* ---- レジスタ退避 ---- */
				movm	[other], (sp)							/* レジスタ退避 */
				
			/* ---- 多重割込み判定 ---- */
				mov		__kernel_int_cnt, a0
				movbu	(a0), d0
				extb	d0
				add		-1, d0
				movbu	d0, (a0)
				bcs		multiple_int
				
			/* ---- 割り込み用スタックに入れ替え ---- */
				mov		sp, a0 									/* タスクのSPを保存 */
				mov		(_kernel_int_isp), a1
				mov		a1, sp
				add		-8, sp
				mov		a0, (4, sp)
				
			/* ---- 割り込み処理 ---- */
				call	__kernel_sta_inh,[],0					/* 割り込み開始 */
				
			/* ---- 割り込みハンドラ実行 ---- */
				clr		d0
				call	__kernel_exe_inh,[],0
				
			/* ---- 割り込み処理の終了設定 ---- */
				mov		(4, sp), a0
				mov		a0, sp
				
				clr		d0
				mov		d0, (__kernel_int_cnt)
		
			/* ---- 遅延ディスパッチ処理 ---- */
				call	_kernel_end_inh,[],0					/* 割り込み終了処理 */
				
return_int:
			/* ---- 復帰処理 ---- */
				movm	(sp), [other]							/* レジスタ退避 */
				rti

			/* ---- 多重割り込み処理 ---- */
multiple_int:
			/* ---- 割り込みハンドラ実行 ---- */
				add		-4, sp
				clr		d0
				call	_kernel_exe_inh,[],0
				
			/* ---- 割り込みカウンタ復帰 ---- */
				mov		__kernel_int_cnt, a0
				movbu	(a0), d0
				add		1, d0
				movbu	d0, (a0)

				jmp		return_int								/* 復帰処理 */



				.comm	__kernel_int_cnt,1,1


				.END


/* end of file */

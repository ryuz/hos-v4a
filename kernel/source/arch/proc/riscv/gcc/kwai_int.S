/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Advance                                       */
/*    RISC-V Architecture                                                   */
/*                                                                          */
/*                                  Copyright (C) 1998-2008 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */

/**  %jp{mstatusレジスタ割込みマスク} */
#define MSTATUS_MIE_ENABLE_MASK                     (0x8)
#define MSTATUS_MIE_DISABLE_MASK             (0xfffffff7)
				.text


/************************************************
  %jp{割り込み待ち(CPUのアイドル処理)
  void 	_kernel_wai_int(void);}
 ************************************************/
				.global	_kernel_wai_int
_kernel_wai_int:
				/* %jp{mstatusによる割込み無効化} */

				csrr	t0, mstatus /* %jp{mstatusの内容を取得}  */

				/* %jp{割込み無効化マスク取得} */
				li	t1, MSTATUS_MIE_DISABLE_MASK
				and	t0, t0, t1 /* %jp{割込み無効化} */

				csrw	mstatus, t0 /* %jp{mstatusレジスタを更新} */

				/* %jp{割込み待ち合わせ} */

				fence   /* %jp{メモリへの書き込みを待ち合わせる}   */
				wfi     /* %jp{割込み待合せ, mstatusのマスク解除}  */
				nop     /* %jp{念のためwfi復帰先にnopを入れておく} */

				csrr	t0, mstatus /* %jp{mstatusの内容を取得}  */

				/* %jp{割込み有効化マスク取得} */
				li	t1, MSTATUS_MIE_ENABLE_MASK
				or	t0, t0, t1 /* %jp{割込み無効化} */

				csrw	mstatus, t0 /* %jp{mstatusレジスタを更新} */


				jr ra

/* end of file */

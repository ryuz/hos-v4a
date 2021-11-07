/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Advance                                       */
/*    RISC-V Architecture                                                   */
/*                                                                          */
/*                                  Copyright (C) 1998-2008 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */

/**  %jp{mstatusレジスタ割込み有効化} */
#define MSTATUS_MIE_ENABLE_MASK             (0x8)

				.text


/************************************************
  %jp{割り込み許可
  void _kernel_ena_int(void)}
 ************************************************/
				.global	_kernel_ena_int
_kernel_ena_int:

				/* %jp{mstatusによる割込み有効化} */

				csrr	t0, mstatus /* %jp{mstatusの内容を取得}  */

				/* %jp{割込み有効化マスク取得} */
				li	t1, MSTATUS_MIE_ENABLE_MASK
				or	t0, t0, t1 /* %jp{割込み有効化} */

				csrw	mstatus, t0 /* %jp{mstatusレジスタを更新} */


				jr	ra

/* end of file */

/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Advance                                       */
/*    RISC-V Architecture                                                   */
/*                                                                          */
/*                                  Copyright (C) 1998-2008 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */

#define _MACRO_ONLY

/**  %jp{mstatusレジスタ割込みマスク} */
#define MSTATUS_MIE_DISABLE_MASK             (0xfffffff7)

				.text

/************************************************
   %jp{割り込み禁止
   void _kernel_dis_int(void)}
 ************************************************/
				.global	_kernel_dis_int
_kernel_dis_int:
				/* %jp{mstatusによる割込み無効化} */

				csrr	t0, mstatus /* %jp{mstatusの内容を取得}  */

				/* %jp{割込み無効化マスク取得} */
				li	t1, MSTATUS_MIE_DISABLE_MASK
				and	t0, t0, t1 /* %jp{割込み無効化} */

				csrw	mstatus, t0 /* %jp{mstatusレジスタを更新} */


				jr	ra

/* end of file */

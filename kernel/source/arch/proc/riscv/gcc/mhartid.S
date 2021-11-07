/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Advance                                       */
/*    RISC-V Architecture                                                   */
/*                                                                          */
/*                                  Copyright (C) 1998-2008 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


				.text


/************************************************
  %jp{Hardware Thread IDの取得
  UD _kernel_riscv_get_hartid(void)}
 ************************************************/
				.global	_kernel_riscv_get_hartid
_kernel_riscv_get_hartid:
				csrr	a0, mhartid /* %jp{mhartidの内容を取得}  */
				jr	ra          /*  呼び出し元に戻る         */


/* end of file */

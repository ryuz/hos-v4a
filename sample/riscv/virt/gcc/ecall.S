/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Advance                                       */
/*    RISC-V Architecture                                                   */
/*                                                                          */
/*                                  Copyright (C) 1998-2008 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


				.text


/************************************************
  %jp{Environment call 発行
UD _riscv_ecall(void)}
 ************************************************/
				.global	_riscv_ecall
_riscv_ecall:
				ecall		    /* %jp{Environment call発行} */
				jr	ra          /* %jp{呼び出し元に戻る}     */

/* end of file */

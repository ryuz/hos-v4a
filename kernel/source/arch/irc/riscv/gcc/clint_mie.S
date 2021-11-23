/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Advance                                       */
/*    RISC-V Architecture                                                   */
/*                                                                          */
/*                                  Copyright (C) 1998-2008 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */

#define _MACRO_ONLY

				.text


/************************************************
  %jp{Machine Interrupt Enableレジスタの読み取り
  uint64_t _kernel_riscv_irc_read_mie(void)}
 ************************************************/
				.global	_kernel_riscv_irc_read_mie
_kernel_riscv_irc_read_mie:
				csrr	a0, mie /* %jp{mieの内容を取得}  */
				jr	ra      /*  呼び出し元に戻る   */


/************************************************
  %jp{Machine Interrupt Enableレジスタの書込み
  void _kernel_riscv_irc_write_mie(UD reg)} reg 更新する値
 ************************************************/
				.global	_kernel_riscv_irc_write_mie
_kernel_riscv_irc_write_mie:
				csrw	mie, a0 /* %jp{mipの内容を更新}  */
				jr	ra

/* end of file */

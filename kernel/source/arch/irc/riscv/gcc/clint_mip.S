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
  %jp{Machine Interrupt Pendingレジスタの読み取り
  UD _kernel_riscv_irc_read_mip(void)}
 ************************************************/
				.global	_kernel_riscv_irc_read_mip
_kernel_riscv_irc_read_mip:
				csrr	a0, mip /* %jp{mipの内容を取得}  */
				jr	ra

/************************************************
  %jp{Machine Interrupt Pendingレジスタの書込み
  void _kernel_riscv_irc_write_mip(UD reg)} reg 更新する値
 ************************************************/
				.global	_kernel_riscv_irc_write_mip
_kernel_riscv_irc_write_mip:
				csrw	mip, a0 /* %jp{mipの内容を更新}  */
				jr	ra

/* end of file */

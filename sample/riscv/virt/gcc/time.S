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
  %jp{timeレジスタの値獲得
  UD _riscv_get_time(void)}
 ************************************************/
				.global	_riscv_get_time
_riscv_get_time:
#if __riscv_xlen == 32
				rdtime	a0 /* %jp{timeの内容を取得}  */
				rdtimeh	a1 /* %jp{timehの内容を取得}  */
#elif  __riscv_xlen == 64
				csrr    a0, time /* %jp{timeの内容を取得}  */
#endif  /*  __riscv_xlen == 32 */

				jr	ra       /* %jp{呼び出し元に戻る}  */


/* end of file */

/* ------------------------------------------------------------------------ */
/* Hyper Operating System V4 Advance                                        */
/*                                                                          */
/*                                  Copyright (C) 1998-2006 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


				.h8300h


				.text


/************************************************
  割り込み禁止
  void _kernel_dis_int(void)
************************************************/
				.global	__kernel_dis_int
__kernel_dis_int:
				orc		#0xc0, ccr				/* 割り込みの禁止 */
				rts


				.end


/* end of file */

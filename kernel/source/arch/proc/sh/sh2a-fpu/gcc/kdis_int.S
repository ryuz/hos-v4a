/* ------------------------------------------------------------------------ */
/* Hyper Operating System V4 Advance                                        */
/*                                                                          */
/*                                  Copyright (C) 1998-2006 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */



				.text


/************************************************
  割り込み禁止
  void _kernel_dis_int(void)
 ************************************************/
				.align	2
				.global	__kernel_dis_int
__kernel_dis_int:
				stc		sr, r0
				or		#0xf0, r0		/* 全割り込みマスク */
				ldc		r0, sr
				rts
				nop



				.end


/* end of file */

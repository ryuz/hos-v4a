/* ------------------------------------------------------------------------ */
/* Hyper Operating System V4 Advance                                        */
/*                                                                          */
/*                                  Copyright (C) 1998-2006 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


				.h8300h


				.text


/************************************************
  プロセッサの初期化
  void _kernel_ini_prc(void)
************************************************/
				.global	__kernel_ini_prc
__kernel_ini_prc:
				orc		#0xc0, ccr				/* 割り込みの禁止 */
				rts


				.end


/* end of file */

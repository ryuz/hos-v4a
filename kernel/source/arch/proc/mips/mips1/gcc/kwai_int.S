/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4 Advance                                       */
/*    MIPS-I Architecture                                                   */
/*                                                                          */
/*                                  Copyright (C) 1998-2008 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */



				.text
				.set	noreorder


/************************************************
  割り込み待ち(CPUのアイドル処理)
  void 	_kernel_wai_int(void);
 ************************************************/
				.global	_kernel_wai_int
				.ent	_kernel_wai_int
_kernel_wai_int:
		/*		wait	*/
				b		_kernel_wai_int
				nop

				.end	_kernel_wai_int


/* end of file */

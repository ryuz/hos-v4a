/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  krst_ctx.c
 * @brief %jp{コンテキスト制御}%en{context control}
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"


/** %jp{実行コンテキストのリスタート} */
void _kernel_rst_ctx(_KERNEL_T_CTXCB *ctxcb)
{
	longjmp(ctxcb->jmpenv, 0);
}


/* end of file */

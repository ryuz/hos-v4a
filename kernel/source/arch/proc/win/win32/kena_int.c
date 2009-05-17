/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  kena_int.c
 * @brief %jp{コンテキスト制御}%en{context control}
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"


/** %jp{割込み許可} */
void _kernel_ena_int(void)
{
	if ( _kernel_ictxcb.blIntCtx )
	{
		return;
	}

	/* 既に割込み禁止ならセマフォを返す */
	if ( _kernel_ictxcb.blDisInt )
	{
		_kernel_ictxcb.blDisInt = FALSE;
		ReleaseSemaphore(_kernel_ictxcb.hSemIntLock, 1, NULL);
	}
}



/* end of file */

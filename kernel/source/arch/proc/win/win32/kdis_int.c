/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  kdis_int.c
 * @brief %jp{コンテキスト制御}%en{context control}
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"



/** %jp{割込み禁止} */
void _kernel_dis_int(void)
{
	if ( _kernel_ictxcb.blIntCtx )
	{
		return;
	}

	/* 既に割込み禁止で無ければセマフォを取る */
	if ( !_kernel_ictxcb.blDisInt )
	{
		WaitForSingleObject(_kernel_ictxcb.hSemIntLock, INFINITE);
		_kernel_ictxcb.blDisInt = TRUE;
	}
}



/* end of file */

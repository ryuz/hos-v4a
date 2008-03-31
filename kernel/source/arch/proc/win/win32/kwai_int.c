/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  kwai_int.c
 * @brief %jp{コンテキスト制御}%en{context control}
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"


/** %jp{アイドル時の処理} */
void _kernel_wai_int(void)
{
	Sleep(1);
}


/* end of file */

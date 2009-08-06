/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  assoc.c
 * @brief %jp{連想配列クラス}
 *
 * Copyright (C) 2006-2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include <stdio.h>
#include <string.h>
#include "hosaplfw.h"
#include "assoc_local.h"


/* 連想バッファの生成 */
C_ASSOC *Assoc_Create(void)
{
	return Assoc_CreateEx(Memory_GetMemHeap());
}


/* end of file */

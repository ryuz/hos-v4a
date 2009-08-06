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
C_ASSOC *Assoc_CreateEx(C_MEMHEAP *pMemHeap)
{
	C_ASSOC *self;
	
	/* メモリ確保 */
	if ( (self = (C_ASSOC *)MemHeap_Alloc(pMemHeap, sizeof(*self))) == NULL )
	{
		return NULL;
	}
	
	/* 初期化 */
	Assoc_Constructor(self, pMemHeap);
	
	return self;
}



/* end of file */

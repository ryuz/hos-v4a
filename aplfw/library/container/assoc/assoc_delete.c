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


/* 連想バッファの削除 */
void Assoc_Delete(C_ASSOC *self)
{
	C_MEMHEAP *pMemHeap;
	
	pMemHeap = self->pMemHeap;
	Assoc_Destructor(self);
	MemHeap_Free(pMemHeap, self);
}



/* end of file */

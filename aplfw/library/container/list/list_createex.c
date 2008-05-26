/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  listbuf.h
 * @brief %jp{リストクラス}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include "list_local.h"


/* コンストラクタ */
void List_CreateEx(C_LIST *self, C_MEMHEAP *pMemHeap)
{
	self->pMemHeap = pMemHeap;
	self->pHead    = NULL;
}


/* end of file */

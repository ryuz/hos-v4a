/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  list_create.c
 * @brief %jp{リストクラス}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include "hosaplfw.h"
#include "list_local.h"


/* コンストラクタ */
void List_Create(C_LIST *self)
{
	self->pMemHeap = Memory_GetMemHeap();
	self->pHead    = NULL;
}


/* end of file */

/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  list_getat.c
 * @brief %jp{リストクラス}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include "list_local.h"


/* データの参照 */
void *List_GetAt(C_LIST *self, LIST_POS Pos)
{
	T_LIST_OBJ *pListObj;
	long       lObjSize;

	pListObj = (T_LIST_OBJ *)Pos;
	lObjSize = MemHeap_AlignSize(self->pMemHeap, sizeof(T_LIST_OBJ));

	return (void *)((char *)pListObj + lObjSize);
}


/* end of file */

/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  list_getnextpos.c
 * @brief %jp{リストクラス}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include "list_local.h"


LIST_POS List_GetNextPos(C_LIST *self, LIST_POS Pos)
{
	T_LIST_OBJ *pListObj;

	pListObj = (T_LIST_OBJ *)Pos;

	pListObj = pListObj->pNext;
	if ( pListObj == self->pHead )
	{
		return LIST_POS_NULL;
	}

	return (LIST_POS)pListObj;
}

/* end of file */

/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  list_getprevpos.c
 * @brief %jp{リストクラス}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include "list_local.h"



LIST_POS List_GetPrevPos(C_LIST *self, LIST_POS Pos)
{
	T_LIST_OBJ *pListObj;

	pListObj = (T_LIST_OBJ *)Pos;

	if ( pListObj == self->pHead )
	{
		return LIST_POS_NULL;
	}
	pListObj = pListObj->pPrev;

	return (LIST_POS)pListObj;
}


/* end of file */

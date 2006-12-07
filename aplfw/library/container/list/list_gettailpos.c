/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  list_gettailpos.c
 * @brief %jp{リストクラス}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include "list_local.h"


LIST_POS List_GetTailPos(C_LIST *self)
{
	T_LIST_OBJ *pHeadObj;

	pHeadObj = (T_LIST_OBJ *)self->pHead;
	if ( pHeadObj == NULL )
	{
		return NULL;
	}

	return pHeadObj->pPrev;
}

/* end of file */

/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  list_getheadpos.c
 * @brief %jp{リストクラス}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include "list_local.h"



LIST_POS List_GetHeadPos(C_LIST *self)
{
	return self->pHead;
}


/* end of file */

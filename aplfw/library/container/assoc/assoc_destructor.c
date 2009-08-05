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


/* 連想バッファのデストラクタ */
void Assoc_Destructor(C_ASSOC *self)
{
	while ( self->pRoot != NULL )
	{
		Assoc_RemoveNode(self, Assoc_GetMinNode(self->pRoot));
	}
}



/* end of file */

/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  handle.h
 * @brief %jp{ハンドルオブジェクト}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include "handleobj.h"
#include "system/process/process_local.h"


/* デストラクタ */
void HandleObj_Destructor(C_HANDLEOBJ *self)
{
	/* プロセスの紐付け解除 */
	if ( self->pNext == self )
	{
		self->pParent->pHandle = NULL;
	}
	else
	{
		if ( self->pParent->pHandle  == self )
		{
			self->pParent->pHandle = self->pNext;
		}
		self->pNext->pPrev = self->pPrev;
		self->pPrev->pNext = self->pNext;
	}
}


/* end of file */

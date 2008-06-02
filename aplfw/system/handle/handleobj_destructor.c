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


/* デストラクタ */
void HandleObj_Destructor(C_HANDLEOBJ *self)
{
	/* 子オブジェクトがあればすべて閉じる */
	while ( self->pChild != NULL )
	{
		Handle_Close((HANDLE)self->pChild);
	}
	
	/* プロセスの紐付け解除 */
	if ( self->pNext == self )
	{
		self->pParent->pChild = NULL;
	}
	else
	{
		if ( self->pParent->pChild  == self )
		{
			self->pParent->pChild = self->pNext;
		}
		self->pNext->pPrev = self->pPrev;
		self->pPrev->pNext = self->pNext;
	}
}


/* end of file */

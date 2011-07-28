/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  handle.h
 * @brief %jp{ハンドルオブジェクト}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "handle_local.h"
#include "system/system/system_local.h"
#include "system/process/process_local.h"



/* 親の設定 */
void Object_SetParent(C_OBJECT *self, C_OWNEROBJ *pParent)
{
	/* 現在の紐付け解除 */
	if ( self->pParent != NULL )
	{
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
	
	/* 親オブジェクトに紐付け */
	self->pParent = pParent;
	if ( pParent == NULL )
	{
		/* 親無し */
		self->pParent = NULL;
		self->pNext   = self;
		self->pPrev   = self;
	}
	else
	{
		/* 親プロセスにリンクする */
		if ( pParent->pChild == NULL )
		{
			pParent->pChild = self;
			self->pNext     = self;
			self->pPrev     = self;
		}
		else
		{
			self->pNext = pParent->pChild;
			self->pPrev = self->pNext->pPrev;
			self->pNext->pPrev = self;
			self->pPrev->pNext = self;
		}
	}
}


/* end of file */

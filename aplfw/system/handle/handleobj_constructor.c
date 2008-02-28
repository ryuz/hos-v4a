/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  handle.h
 * @brief %jp{ハンドルオブジェクト}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "handleobj_local.h"
#include "system/process/process_local.h"


/* コンストラクタ */
void HandleObj_Constructor(C_HANDLEOBJ *self, const T_HANDLEOBJ_METHODS *pMethods)
{
	C_HANDLEOBJ *pParent;

	/* 仮想関数テーブルの登録 */
	self->pMethods = pMethods;
	
	/* システムモードでなければプロセスに紐付け */
	pParent = (C_HANDLEOBJ *)Process_GetCurrentHandle();
	if ( Process_IsSystemMode() || pParent == NULL )
	{
		/* システムプロセスなら親無しで作る */
		self->pParent = NULL;
		self->pChild  = NULL;
		self->pNext   = self;
		self->pPrev   = self;
	}
	else
	{
		/* 親プロセスにリンクする */
		self->pParent = pParent;
		self->pChild  = NULL;
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

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
	HandleObj_ConstructorEx(self, pMethods, Process_GetCurrentProcess());
}


/* コンストラクタ */
void HandleObj_ConstructorEx(C_HANDLEOBJ *self, const T_HANDLEOBJ_METHODS *pMethods, C_PROCESS *pParent)
{
	/* 仮想関数テーブルの登録 */
	self->pMethods = pMethods;
	
	/* システムモードでなければプロセスに紐付け */
	if ( Process_IsSystemMode() || pParent == NULL )
	{
		/* システムプロセスなら親無しで作る */
		self->pParent = NULL;
		self->pNext   = self;
		self->pPrev   = self;
	}
	else
	{
		/* 親プロセスにリンクする */
		self->pParent = pParent;
		if ( pParent->pHandle == NULL )
		{
			pParent->pHandle = self;
			self->pNext      = self;
			self->pPrev      = self;
		}
		else
		{
			self->pNext = pParent->pHandle;
			self->pPrev = self->pNext->pPrev;
			self->pNext->pPrev = self;
			self->pPrev->pNext = self;
		}
	}
}


/* end of file */

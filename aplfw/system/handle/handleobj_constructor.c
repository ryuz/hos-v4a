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
#include "system/system/system_local.h"
#include "system/process/process_local.h"


/* コンストラクタ */
void Object_Constructor(C_OBJECT *self, const T_OBJECT_METHODS *pMethods, C_OWNEROBJ *pParent)
{
	/* 仮想関数テーブルの登録 */
	self->pMethods = pMethods;
	self->pParent  = NULL;
	Object_SetParent(self, pParent);
}

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


/** コンストラクタ */
void TargetObj_Constructor(C_TARGETOBJ *self, const T_OBJECT_METHODS *pMethods)
{
	/* 親クラスのコンストラクタ (デフォルトで現在のプロセスに紐付け) */
	Object_Constructor(&self->Object, pMethods, &System_GetSystemProcess()->OwnerObj);
	self->iRefCounter = 0;
	self->iRemove     = 0;
}


void HandleObj_Constructor(C_HANDLEOBJ *self, const T_OBJECT_METHODS *pMethods, C_TARGETOBJ *pTargetObj)
{
	/* 親クラスのコンストラクタ (デフォルトで現在のプロセスに紐付け) */
	Object_Constructor(&self->Object, pMethods, &Process_GetCurrentProcess()->OwnerObj);
	
	/* ターゲットオブジェクト登録 */
	self->pTargetObj = pTargetObj;
	pTargetObj->iRefCounter++;
}


/** コンストラクタ */
void OwnerObj_Constructor(C_OWNEROBJ *self, const T_OBJECT_METHODS *pMethods)
{
	TargetObj_Constructor(&self->TargetObj, pMethods);
	self->pChild = NULL;
}


/* end of file */

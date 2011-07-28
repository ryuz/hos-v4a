/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  handle.h
 * @brief %jp{ハンドルオブジェクト}
 *
 * Copyright (C) 2006-2011 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include "handle_local.h"
#include "system/process/process_local.h"


/** デストラクタ */
void Object_Destructor(C_OBJECT *self)
{
	/* 紐付け解除 */
	Object_SetParent(self, NULL);
}


/* デストラクタ */
void PointerObj_Destructor(C_POINTEROBJ *self)
{
	/* ターゲットからデタッチ */
	self->pTargetObj->iRefCounter--;
	if ( self->pTargetObj->iRefCounter <= 0 && self->pTargetObj->iRemove )
	{
		/* 削除指定ありで参照0なら閉じる */
		Handle_Close((HANDLE)self->pTargetObj);
	}

	/* 親クラスデストラクタ */
	Object_Destructor(&self->Object);
}


/* デストラクタ */
void TargetObj_Destructor(C_TARGETOBJ *self)
{
	SYS_ASSERT(self->iRefCounter == 0);

	/* 親クラスデストラクタ */
	Object_Destructor(&self->Object);	
}


/* デストラクタ */
void OwnerObj_Destructor(C_OWNEROBJ *self)
{
	/* 子オブジェクト全クローズ */
	while ( self->pChild != NULL )
	{
		Handle_Close((HANDLE)self->pChild);
	}

	/* 親クラスデストラクタ */
	TargetObj_Destructor(&self->TargetObj);
}


/* end of file */

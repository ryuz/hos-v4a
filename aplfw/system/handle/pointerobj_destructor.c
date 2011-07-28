/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  handle.h
 * @brief %jp{ハンドルオブジェクト}
 *
 * Copyright (C) 2006-2011 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "handle_local.h"


/* デストラクタ */
void PointerObj_Destructor(C_POINTEROBJ *self)
{
	/* ターゲットからデタッチ */
	self->pTargetObj->iRefCounter--;
	if ( TargetObj_GetRefCounter(&self->pTargetObj) <= 0 && TargetObj_GetDeleteFlag(self->pTargetObj) )
	{
		/* 削除指定ありで参照0なら閉じる */
		Handle_Close((HANDLE)self->pTargetObj);
	}

	/* 親クラスデストラクタ */
	Object_Destructor(&self->Object);
}



/* end of file */

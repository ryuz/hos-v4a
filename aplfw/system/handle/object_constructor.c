/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  object_constructor.c
 * @brief %jp{ブジェクトクラス コンストラクタ}
 *
 * Copyright (C) 2006-2011 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "handle_local.h"


/* コンストラクタ */
void Object_Constructor(C_OBJECT *self, const T_OBJECT_METHODS *pMethods, C_OWNEROBJ *pParent)
{
	/* 仮想関数テーブルの登録 */
	self->pMethods = pMethods;
	self->pParent  = NULL;
	Object_SetParent(self, pParent);
}


/* end of file */

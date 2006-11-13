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
#include "hdlobj.h"


/* コンストラクタ */
void HandleObj_Create(C_HANDLEOBJ *self, const T_HANDLEOBJ_METHODS *pMethods)
{
	self->pMethods = pMethods;
}

/* デストラクタ */
void HandleObj_Delete(C_HANDLEOBJ *self)
{
	/* デストラクタが登録されていれば呼ぶ */
	if ( self->pMethods->pfncDelete != NULL )
	{
		self->pMethods->pfncDelete((HANDLE)self);
	}
}




/* end of file */
/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  handle.h
 * @brief %jp{ハンドルオブジェクト}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "handleobj.h"


/* コンストラクタ */
void HandleObj_Create(C_HANDLEOBJ *self, const T_HANDLEOBJ_METHODS *pMethods)
{
	self->pMethods = pMethods;
}



/* end of file */

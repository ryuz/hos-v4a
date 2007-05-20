/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  drvobj.h
 * @brief %jp{デバイスドライバオブジェクトの基本クラス}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "drvobj_local.h"


/**< コンストラクタ */
void DrvObj_Create(C_DRVOBJ *self, const T_DRVOBJ_METHODS *pMethods)
{
	self->pMethods = pMethods;
}


/* end of file */

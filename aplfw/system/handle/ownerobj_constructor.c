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
#include "system/system/system_local.h"
#include "system/process/process_local.h"


/** コンストラクタ */
void OwnerObj_Constructor(C_OWNEROBJ *self, const T_OBJECT_METHODS *pMethods)
{
	TargetObj_Constructor(&self->TargetObj, pMethods);
	self->pChild = NULL;
}


/* end of file */

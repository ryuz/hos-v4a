/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  handle.h
 * @brief %jp{ハンドルオブジェクト}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "handle_local.h"
#include "system/system/system_local.h"
#include "system/process/process_local.h"



/** コンストラクタ */
void TargetObj_Constructor(C_TARGETOBJ *self, const T_OBJECT_METHODS *pMethods)
{
	/* 親クラスのコンストラクタ (デフォルトで現在のプロセスに紐付け) */
	Object_Constructor(&self->Object, pMethods, &System_GetSystemProcessObj()->OwnerObj);
	self->iRefCounter = 0;
	self->iDeleteFlag = 0;
}



/* end of file */

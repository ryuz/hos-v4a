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


void PointerObj_Constructor(C_POINTEROBJ *self, const T_OBJECT_METHODS *pMethods, C_TARGETOBJ *pTargetObj)
{
	/* 親クラスのコンストラクタ (デフォルトで現在のプロセスに紐付け) */
	Object_Constructor(&self->Object, pMethods, &Process_GetCurrentProcess()->OwnerObj);
	
	/* ターゲットオブジェクト登録 */
	self->pTargetObj = pTargetObj;
	pTargetObj->iRefCounter++;
}


/* end of file */

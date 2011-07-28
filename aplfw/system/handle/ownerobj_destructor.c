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

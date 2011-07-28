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
#include "handle.h"
#include "handle_local.h"
#include "system/sysapi/sysapi.h"


/* ハンドルを閉じる */
void Handle_Close(HANDLE handle)
{
	C_OBJECT *self;
	
	/* 有効チェック */
	if ( handle == HANDLE_NULL )
	{
		SYS_ASSERT(0);
		return;
	}
	
	/* ハンドル変換 */
	self = (C_OBJECT *)handle;

	/* クローズ処理 */
	if ( self->pMethods != NULL && self->pMethods->pfncDelete != NULL )
	{
		self->pMethods->pfncDelete(handle);
	}
}

/* end of file */

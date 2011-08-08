/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  handle_duplicate.c
 * @brief %jp{ハンドル複製}
 *
 * Copyright (C) 2006-2011 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include "handle.h"
#include "handle_local.h"
#include "system/sysapi/sysapi.h"


/* ハンドルを複製する */
HANDLE Handle_Duplicate(HANDLE handle)
{
	C_OBJECT *self;
	
	/* 有効チェック */
	if ( handle == HANDLE_NULL )
	{
		SYS_ASSERT(0);
		return HANDLE_NULL;
	}
	
	/* ハンドル変換 */
	self = (C_OBJECT *)handle;

	/* 複製処理 */
	if ( self->pMethods == NULL || self->pMethods->pfncDuplicate == NULL )
	{
		return HANDLE_NULL;
	}

	return self->pMethods->pfncDuplicate(handle);	
}


/* end of file */

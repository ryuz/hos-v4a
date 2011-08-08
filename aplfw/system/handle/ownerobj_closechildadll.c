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


/* 子オブジェクト全クローズ */
void OwnerObj_CloseChildAdll(C_OWNEROBJ *self)
{
	/* 子オブジェクト全クローズ */
	while ( self->pChild != NULL )
	{
		Handle_Close((HANDLE)self->pChild);
	}
}


/* end of file */

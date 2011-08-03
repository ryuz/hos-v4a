/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  pointerobj_duplicate.c
 * @brief %jp{ハンドルオブジェクト}
 *
 * Copyright (C) 2006-2011 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "handle_local.h"
#include "system/system/system_local.h"
#include "system/process/process_local.h"


/* ハンドルを複製する */
HANDLE PointerObj_Duplicate(HANDLE handle)
{
	C_POINTEROBJ	*self;
	C_POINTEROBJ	*pNew;
	
	self =(C_POINTEROBJ *)handle;
	
	/* メモリ確保 */
	if ( (pNew = (C_POINTEROBJ *)SysMem_Alloc(sizeof(C_POINTEROBJ))) == NULL )
	{
		return NULL;
	}
	
	/* コンストラクタ */
	PointerObj_Constructor(self, self->Object.pMethods, self->pTargetObj);
	
	return self;
}


/* end of file */

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


C_POINTEROBJ *PointerObj_Create(const T_OBJECT_METHODS *pMethods, C_TARGETOBJ *pTargetObj)
{
	C_POINTEROBJ	*self;

	/* メモリ確保 */
	if ( (self = (C_POINTEROBJ *)SysMem_Alloc(sizeof(C_POINTEROBJ))) == NULL )
	{
		return NULL;
	}
	
	/* コンストラクタ */
	PointerObj_Constructor(self, pMethods, pTargetObj);
	
	return self;
}


/* end of file */

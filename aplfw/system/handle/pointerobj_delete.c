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


void PointerObj_Delete(HANDLE handle)
{
	C_POINTEROBJ	*self;
	
	self = (C_POINTEROBJ *)handle;
	
	/* デストラクタ */
	PointerObj_Destructor(self);
	
	/* メモリ開放 */
	SysMem_Free(self);
}


/* end of file */

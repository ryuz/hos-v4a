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


/** デストラクタ */
void Object_Destructor(C_OBJECT *self)
{
	/* 紐付け解除 */
	Object_SetParent(self, NULL);
}


/* end of file */

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
void TargetObj_Destructor(C_TARGETOBJ *self)
{
	SYS_ASSERT(self->iRefCounter == 0);
	
	/* 親クラスデストラクタ */
	Object_Destructor(&self->Object);	
}


/* end of file */

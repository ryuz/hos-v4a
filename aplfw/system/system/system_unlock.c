/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  system.h
 * @brief %jp{システム用API定義}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "hosaplfw.h"
#include "system/system/system_local.h"


void System_Unlock(void)
{
	C_SYSTEM	*self;
	
	self = &g_System;
	
	SysMtx_Unlock(self->hMtxSys);
}


/* end of file */

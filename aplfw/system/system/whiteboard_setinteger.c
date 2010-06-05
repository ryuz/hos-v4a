/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  whiteboard_setstring
 * @brief %jp{ホワイトボードに文字列を設定}
 *
 * Copyright (C) 2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <string.h>
#include "hosaplfw.h"
#include "system/system/system_local.h"


/* ホワイトボードに数値を設定 */
void Whiteboard_SetInteger(const char *pszKey, unsigned long ulValue)
{
	C_SYSTEM	*self;
	char		szBuf[16];
	
	self = &g_System;
	
	System_Lock();
	
	if ( self->paWhiteBoard == NULL )
	{
		self->paWhiteBoard = Assoc_CreateEx(SysMem_GetMemHeap());
	}
	
	StringFormat_FormatString(szBuf, sizeof(szBuf), "%lu", ulValue);
	Assoc_Set(self->paWhiteBoard, pszKey, szBuf, strlen(szBuf) + 1);
	
	System_Unlock();
}


/* end of file */

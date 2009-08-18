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


/* ホワイトボードに文字列を設定 */
void Whiteboard_SetString(const char *pszKey, const char *pszValue)
{
	C_SYSTEM	*self;

	self = &g_System;
	
	System_Lock();
	
	if ( self->paWhiteBoard == NULL )
	{
		self->paWhiteBoard = Assoc_CreateEx(SysMem_GetMemHeap());
	}

	if ( self->paWhiteBoard != NULL )
	{
		if ( pszValue == NULL )
		{
			Assoc_Remove(self->paWhiteBoard, pszKey);
		}
		else
		{
			Assoc_Set(self->paWhiteBoard, pszKey, pszValue, strlen(pszValue) + 1);
		}
	}
	
	System_Unlock();
}


/* end of file */

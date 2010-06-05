/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  whiteboard_getstring.c
 * @brief %jp{ホワイトボードから文字列を取得}
 *
 * Copyright (C) 2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include <stdlib.h>
#include <string.h>
#include "hosaplfw.h"
#include "system/system/system_local.h"


/* ホワイトボードから数値を取得 */
unsigned long Whiteboard_GetInteger(const char *pszKey, unsigned long ulDefault)
{
	C_SYSTEM		*self;
	const char		*pszValue = NULL;
	unsigned long	ulValue;
	
	self = &g_System;
	
	System_Lock();
	
	if ( self->paWhiteBoard != NULL )
	{
		pszValue = Assoc_Get(self->paWhiteBoard, pszKey);
	}
	
	if ( pszValue == NULL )
	{
		ulValue = ulDefault;
	}
	
	if ( pszValue != NULL )
	{
		ulValue = strtoul(pszValue, 0, 0);
	}
	
	System_Unlock();
	
	return ulValue;
}


/* end of file */

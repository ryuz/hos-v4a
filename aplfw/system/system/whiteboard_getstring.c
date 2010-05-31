/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  whiteboard_getstring.c
 * @brief %jp{ホワイトボードから文字列を取得}
 *
 * Copyright (C) 2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <string.h>
#include "hosaplfw.h"
#include "system/system/system_local.h"


/* ホワイトボードから文字列を取得 */
const char *Whiteboard_GetString(const char *pszKey, char *pszBuf, int iBufSize, const char *pszDefault)
{
	C_SYSTEM	*self;
	const char	*pszValue = NULL;
	
	self = &g_System;
	
	System_Lock();
	
	if ( self->paWhiteBoard != NULL )
	{
		pszValue = Assoc_Get(self->paWhiteBoard, pszKey);
	}
	
	if ( pszValue == NULL )
	{
		pszValue = pszDefault;
	}
	
	if ( pszValue != NULL )
	{
		strncpy(pszBuf, pszValue, iBufSize);
		pszBuf[iBufSize-1] = '\0';
	}
	
	System_Unlock();
	
	return pszBuf;
}


/* end of file */

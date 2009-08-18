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


/* ホワイトボードから次のキーを取得 */
const char *Whiteboard_GetNextKey(const char *pszKey, char *pszBuf, int iBufSize)
{
	C_SYSTEM	*self;
	ASSOC_POS	pos;
	const char	*pszNextKey;
	
	self = &g_System;
	
	System_Lock();
	
	if ( self->paWhiteBoard == NULL )
	{
		System_Unlock();
		return NULL;
	}

	if ( pszKey == NULL ||  pszKey[0] == '\0' )
	{
		pos = Assoc_GetFirst(self->paWhiteBoard);
	}
	else
	{
		pos = Assoc_GetPos(self->paWhiteBoard, pszKey);
		if ( pos != ASSOC_POS_NULL )
		{
			pos = Assoc_GetNext(self->paWhiteBoard, pos);
		}
	}
	
	if ( pos == ASSOC_POS_NULL )
	{
		System_Unlock();
		return NULL;
	}
	
	Assoc_GetAt(self->paWhiteBoard, pos, &pszNextKey);

	strncpy(pszBuf, pszNextKey, iBufSize);
	pszBuf[iBufSize-1] = '\0';
	
	System_Unlock();
	
	return pszBuf;
}


/* end of file */

/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  sysvol.h
 * @brief %jp{システムボリューム}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include <string.h>
#include "sysvol_local.h"


/* システムボリュームに登録されたデバイスを検索 */
HANDLE SysVol_GetDevice(HANDLE hSysVol, const char *pszName)
{
	C_SYSVOL	*self;
	int			i;
	
	self = (C_SYSVOL *)hSysVol;
	
	/* テーブルを検索 */
	for ( i = 0; i < DEVVOL_MAX_DEVICE; i++ )
	{
		if ( strcmp(self->DevTable[i].szName, pszName) == 0 )
		{
			return self->DevTable[i].hDriver;
		}
	}
	
	return HANDLE_NULL;	
}


/* end of file */

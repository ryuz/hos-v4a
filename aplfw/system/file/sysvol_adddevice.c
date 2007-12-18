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


/* システムボリュームにデバイスをぶら下げる */
FILE_ERR SysVol_AddDevice(HANDLE hSysVol, const char *pszName, HANDLE hDriver, int iAttr)
{
	C_SYSVOL	*self;
	int			i;
	
	self = (C_SYSVOL *)hSysVol;
	
	/* テーブルの空きを検索 */
	for ( i = 0; i < DEVVOL_MAX_DEVICE; i++ )
	{
		if ( self->DevTable[i].hDriver == HANDLE_NULL )
		{
			strcpy(self->DevTable[i].szName, pszName);
			self->DevTable[i].hDriver = hDriver;
			self->DevTable[i].iAttr   = iAttr;
			return FILE_ERR_OK;
		}
	}
	
	return FILE_ERR_NG;	
}


/* end of file */

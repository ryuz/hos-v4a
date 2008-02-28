/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  sysvol.h
 * @brief %jp{システムボリューム}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include <string.h>
#include "sysvol_local.h"
#include "system/sysapi/sysapi.h"
#include "system/file/drvobj.h"
#include "system/file/fileobj_local.h"

/* ファイルを開く */
HANDLE SysVol_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode)
{
	C_SYSVOL	*self;
	int			iLen;
	int			i;
	
	/* upper cast */
	self = (C_SYSVOL *)pDrvObj;
	
	/* 自分自身のディレクトリを開くなら */
	if ( *pszPath == '\0' )
	{
		HANDLE hDir;

		/* モードチェック */
		if ( !(iMode & (FILE_OPEN_DIR | FILE_OPEN_READ)) )
		{
			return HANDLE_NULL;
		}
		
		/* ディスクリプタ生成 */
		if ( (hDir = SysVolFile_Create(self, iMode)) == HANDLE_NULL )
		{
			return HANDLE_NULL;
		}
		
		return hDir;
	}
	
	/* 下位デバイスを検索 */
	for ( i = 0; i < DEVVOL_MAX_DEVICE; i++ )
	{
		/* 名前部分探索 */
		for ( iLen =0; pszPath[iLen] != '\0' && pszPath[iLen] != '/'; iLen++ )
			;
		
		if ( self->DevTable[i].hDriver != HANDLE_NULL && strncmp(pszPath, self->DevTable[i].szName, iLen) == 0 && self->DevTable[i].szName[iLen] == '\0' )
		{
			break;
		}
	}
	if ( i >= DEVVOL_MAX_DEVICE )
	{
		return HANDLE_NULL;
	}
	
	if ( pszPath[iLen] == '/' )
	{
		iLen++;
	}
	
	return DrvObj_vOpen((C_DRVOBJ *)self->DevTable[i].hDriver, &pszPath[iLen], iMode);
}


/* end of file */


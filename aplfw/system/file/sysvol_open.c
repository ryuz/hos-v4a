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
		C_SYSVOLDIR *pDir;

		/* モードチェック */
		if ( !(iMode & (FILE_OPEN_DIR | FILE_OPEN_READ)) )
		{
			return HANDLE_NULL;
		}
		
		/* ディスクリプタ生成 */
		if ( (pDir = (C_SYSVOLDIR *)SysMem_Alloc(sizeof(C_SYSVOLDIR))) == NULL )
		{
			return HANDLE_NULL;
		}
		FileObj_Create(&pDir->FileObj, (C_DRVOBJ *)self, NULL);
		pDir->iReadPtr = 0;
		
		return (HANDLE)pDir;
	}
	
	/* 下位デバイスを検索 */
	for ( i = 0; i < DEVVOL_MAX_DEVICE; i++ )
	{
		/* 名前部分探索 */
		for ( iLen =0; pszPath[iLen] != '\0' && pszPath[iLen] != '/'; iLen++ )
			;
		
		if ( strncmp(pszPath, self->DevTable[i].szName, iLen) == 0 )
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
	
	return DrvObj_vOpen(self->DevTable[i].pDrvObj, &pszPath[iLen], iMode);
}


/* end of file */


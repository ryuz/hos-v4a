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
#include "system/file/file_local.h"
#include "system/file/file_local.h"

/* ファイルを開く */
HANDLE SysVol_Open(C_FILEOBJ *pFileObj, const char *pszPath, int iMode)
{
	C_SYSVOL		*self;
	C_FILEOBJ		*pDriver;
	T_SYSVOL_DEVINF	*pDevInf;
	char			szName[DEVVOL_MAX_NAME];
	int				iLen;
	
	/* upper cast */
	self = (C_SYSVOL *)pFileObj;
	
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
	
	/* 名前部分探索 */
	for ( iLen =0; pszPath[iLen] != '\0' && pszPath[iLen] != '/'; iLen++ )
	{
		szName[iLen] = pszPath[iLen];
	}
	szName[iLen] = '\0';
	if ( (pDevInf = (T_SYSVOL_DEVINF *)Assoc_Get(&self->asDevice, szName)) == NULL )
	{
		return HANDLE_NULL;
	}
	
	if ( pszPath[iLen] == '/' )
	{
		iLen++;
	}
	
	/* 下位デバイスを検索 */
	pDriver = (C_FILEOBJ *)pDevInf->hDriver;
	return FileObj_GetMethods(pDriver)->pfncOpen(pDriver, &pszPath[iLen], iMode);
}


/* end of file */


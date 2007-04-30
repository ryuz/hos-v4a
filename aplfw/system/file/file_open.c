/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  file.c
 * @brief %jp{ファイルシステム}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include <stdio.h>
#include <string.h>
#include "file_local.h"
#include "volume.h"


/* ファイルのオープン */
HANDLE File_Open(const char *pszPatah, int iMode)
{
	C_FILE *self;
	int    iNameLen;
	int    i;
	
	self = &g_File;
	
	if ( *pszPatah == '/' )		/* 絶対パス */
	{

		pszPatah++;
	}
	else	/* 相対パスの処理(そのうち追加) */
	{
	}
	
	
	/* ボリュームを検索 */
	for ( i = 0; i < FILE_MAX_VOLUME; i++ )
	{
		iNameLen = strlen(self->VolumeTable[i].szName);
		if ( strncmp(pszPatah, self->VolumeTable[i].szName, iNameLen) == 0 )
		{
			pszPatah += iNameLen;
			return Volume_OpenFile(self->VolumeTable[i].hVolume, pszPatah, iMode);
		}
	}
	
	return HANDLE_NULL;
}

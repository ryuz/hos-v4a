/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  file.c
 * @brief %jp{ファイルシステム}
 *
 * Copyright (C) 2006-2007 by Project HOS
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
	
	self = &g_File;
	
	if ( *pszPatah == '/' )		/* 絶対パス */
	{
		pszPatah++;
	}
	else	/* 相対パスの処理(そのうち追加) */
	{
		
	}
	
	/* ルートディレクトリからオープンを掛ける */
	return DrvObj_vOpen((C_DRVOBJ *)&self->RootVol, pszPatah, iMode);
}

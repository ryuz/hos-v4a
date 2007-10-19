/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  fatvol.c
 * @brief %jp{FATボリューム用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include "fatvol_local.h"


HANDLE FatVol_FileCreate(C_FATVOL *self, FATVOL_UINT uiStartCluster, FATVOL_UINT uiDirCluster, FATVOL_UINT uiDirEntryPos, FILE_POS FileSize, int iMode)
{
	C_FATFILE *pFile;

	/* create file descriptor */
	if ( (pFile = SysMem_Alloc(sizeof(*pFile))) == NULL )
	{
		return HANDLE_NULL;
	}
	FileObj_Create(&pFile->FileObj, (C_DRVOBJ *)self, NULL);
	
	/* 初期化 */
	pFile->iMode          = iMode;
	pFile->uiStartCluster = uiStartCluster;
	pFile->uiDirCluster   = uiDirCluster;
	pFile->uiDirEntryPos  = uiDirEntryPos;
	pFile->FileSize       = FileSize;
	
	/* ファイルポインタ初期化 */
	pFile->FilePos          = 0;
	
	return (HANDLE)pFile;
}


/* end of file */

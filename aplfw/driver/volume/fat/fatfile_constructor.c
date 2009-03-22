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
#include "fatfile_local.h"


void FatFile_Constructor(C_FATFILE *self, const T_FILEOBJ_METHODS *pMethods, C_FATVOL *pFatVol, FATVOL_UINT uiStartCluster, FATVOL_UINT uiDirCluster, FATVOL_UINT uiDirEntryPos, FILE_POS FileSize, int iMode)
{
	/* 親クラスコンストラクタ */
	FileObj_Constructor(&self->FileObj, pMethods, &pFatVol->VolumeObj.DrvObj, iMode);
	
	/* メンバ変数初期化 */
	self->uiStartCluster = uiStartCluster;
	self->uiDirCluster   = uiDirCluster;
	self->uiDirEntryPos  = uiDirEntryPos;
	self->FileSize       = FileSize;
	self->FilePos        = 0;				/* ファイルポインタ初期化 */
	if ( iMode & FILE_OPEN_APPEND )
	{
		self->FilePos = self->FileSize;
	}
}


/* end of file */

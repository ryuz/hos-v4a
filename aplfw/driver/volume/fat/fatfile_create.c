/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  fatvol.c
 * @brief %jp{FATボリューム用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "fatfile_local.h"


static const T_FILEOBJ_METHODS FatFile_FileObjMethods =
	{
		{File_Close},	/* デストラクタ */
	};


HANDLE FatFile_Create(C_FATVOL *pFatVol, FATVOL_UINT uiStartCluster, FATVOL_UINT uiDirCluster, FATVOL_UINT uiDirEntryPos, FILE_POS FileSize, int iMode)
{
	C_FATFILE *self;

	/* create file descriptor */
	if ( (self = (C_FATFILE *)SysMem_Alloc(sizeof(C_FATFILE))) == NULL )
	{
		return HANDLE_NULL;
	}
	
	/* コンストラクタ呼び出し */
	FatFile_Constructor(self, &FatFile_FileObjMethods, pFatVol, uiStartCluster, uiDirCluster, uiDirEntryPos, FileSize, iMode);
	
	return (HANDLE)self;
}


/* end of file */

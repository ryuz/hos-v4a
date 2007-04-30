
#include <stdio.h>
#include "fatfile_local.h"


const T_FILEOBJ_METHODS FatFile_FileObjMethods =
{
/*	{ FatFile_Delete },	*/	/* デストラクタ */
	FatFile_IoControl,		/* IoControl */
	FatFile_Seek,			/* Seek */
	FatFile_Read,			/* Read */
	FatFile_Write,			/* Write */
};


FILE_ERR FatFile_Create(C_FATFILE *self, C_FATVOL *pFatVol, FATVOL_UINT uiCluster, HANDLE hDir, int iDirEntry, int iMode)
{
	/* 親クラスコンストラクタ呼び出し */
	FileObj_Create(&self->FileObj, &FatFile_FileObjMethods);
	
	/* 初期化 */
	self->iMode          = iMode;
	self->pFatVol        = pFatVol;
	self->uiStartCluster = uiCluster;
	self->hDir           = hDir;
	self->iDirEntry      = iDirEntry;
	
	/* サイズ取得 */
	if ( hDir == NULL )
	{
		
	}
	
	/* ファイルポインタ初期化 */
	self->FilePos          = 0;
	self->uiCurrentCluster = self->uiStartCluster;
	
	
	return FILE_ERR_OK;
}


/* end of file */

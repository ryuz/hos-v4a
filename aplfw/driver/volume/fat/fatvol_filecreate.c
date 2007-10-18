
#include <stdio.h>
#include "fatvol_local.h"


HANDLE FatVol_FileCreate(C_FATVOL *self, FATVOL_UINT uiCluster, HANDLE hDir, int iDirEntry, int iMode)
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
	pFile->uiStartCluster = uiCluster;
	pFile->hDir           = hDir;
	pFile->iDirEntry      = iDirEntry;
	
	/* サイズ取得 */
	if ( hDir != HANDLE_NULL )
	{
		pFile->FileSize = FatVol_GetFileSize(hDir, iDirEntry);
	}
	
	/* ファイルポインタ初期化 */
	pFile->FilePos          = 0;
	pFile->uiCurrentCluster = pFile->uiStartCluster;
	
	
	return (HANDLE)pFile;
}


/* end of file */

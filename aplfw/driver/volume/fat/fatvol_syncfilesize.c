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


/* サイズ同期 */
void FatVol_SyncFileSize(C_FATVOL *self, C_FATFILE *pFile)
{
	T_FATVOL_CLUSTERBUF *pClusterBuf;
	FILE_POS			Size;

	/* バッファ取得 */
	if ( (pClusterBuf = FatVol_GetClusterBuf(self, pFile->uiDirCluster, 1)) == NULL )
	{
		return;
	}
	
	/* サイズ取得 */
	Size = pClusterBuf->pubBuf[pFile->uiDirEntryPos + 28]
				+ (pClusterBuf->pubBuf[pFile->uiDirEntryPos + 29] << 8)
				+ (pClusterBuf->pubBuf[pFile->uiDirEntryPos + 30] << 16)
				+ (pClusterBuf->pubBuf[pFile->uiDirEntryPos + 31] << 24);
	
	/* サイズ拡張 */
	if ( pFile->FileSize > Size )
	{
		pClusterBuf->pubBuf[pFile->uiDirEntryPos + 28] = (pFile->FileSize >>  0) & 0xff;
		pClusterBuf->pubBuf[pFile->uiDirEntryPos + 29] = (pFile->FileSize >>  8) & 0xff;
		pClusterBuf->pubBuf[pFile->uiDirEntryPos + 30] = (pFile->FileSize >> 16) & 0xff;
		pClusterBuf->pubBuf[pFile->uiDirEntryPos + 31] = (pFile->FileSize >> 24) & 0xff;

		/* バッファ開放 */
		FatVol_RelClusterBuf(self, pClusterBuf, 1);
	}
	else
	{
		pFile->FileSize = Size;
	
		/* バッファ開放 */
		FatVol_RelClusterBuf(self, pClusterBuf, 0);
	}
}


/* end of file */

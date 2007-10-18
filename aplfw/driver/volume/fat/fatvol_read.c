/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  fatvol.c
 * @brief %jp{FATボリューム用デバイスドライバ}
 *
 * Copyright (C) 2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <string.h>
#include "fatvol_local.h"


/** %jp{読出し} */
FILE_SIZE FatVol_Read(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, void *pBuf, FILE_SIZE Size)
{
	C_FATVOL		*self;
	C_FATFILE		*pFile;
	unsigned char	*pubBuf;
	FILE_SIZE		ReqSize;
	FATVOL_UINT		uiCluster;
	
	/* upper cast */
	self  = (C_FATVOL *)pDrvObj;
	pFile = (C_FATFILE *)pFileObj;
	
	pubBuf = (unsigned char *)pBuf;
	
	/* サイズチェック */
	if ( !(pFile->iMode & FILE_OPEN_DIR) )
	{
		if ( Size > pFile->FileSize - pFile->FilePos )
		{
			/* サイズ更新されていないかディレクトリテーブルを参照するべき？ */

			/* サイズクリップ */
			Size = pFile->FileSize - pFile->FilePos;
		}
	}
	
	/* 要求読み出し量保存 */
	ReqSize = Size;
	
	/* 読み出し */
	uiCluster = pFile->uiCurrentCluster;
	while ( Size > 0 && (pFile->FilePos < pFile->FileSize || (pFile->iMode & FILE_OPEN_DIR)) )
	{
		FILE_POS 		ReadStart;
		FILE_SIZE		ReadSize;
		unsigned char	*pubClusterBuf;
		
		/* クラスタチェック */
		if ( uiCluster == FATVOL_CLUSTER_ENDMARKER )
		{
			break;
		}
		
		/* 転送位置計算 */
		ReadStart = pFile->FilePos % self->BytesPerSector;
		ReadSize  = self->BytesPerSector - ReadStart;
		if ( ReadSize > Size )
		{
			ReadSize = Size;
		}
		
		/* バッファ取得 */
		if ( FatVol_GetClusterBuf(self, uiCluster, (void **)&pubClusterBuf, 1) != FATVOL_ERR_OK )
		{
			break;
		}
		pFile->uiCurrentCluster = uiCluster;

		/* 転送 */
		memcpy(pubBuf, &pubClusterBuf[ReadStart], ReadSize);

		/* バッファ開放 */
		FatVol_RelClusterBuf(self, pubClusterBuf, 0);
		
		/* サイズ更新 */
		pFile->FilePos += ReadSize;
		pubBuf         += ReadSize;
		Size           -= ReadSize;
		
		/* 次のクラスタに進む */
		uiCluster = FatVol_GetNextCluster(self, uiCluster);
	}
	
	return ReqSize - Size;
}


/* end of file */

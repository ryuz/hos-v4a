/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  fatvol.c
 * @brief %jp{FATボリューム用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include <string.h>
#include "fatvol_local.h"


/** %jp{読出し} */
FILE_SIZE FatVol_Read(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, void *pBuf, FILE_SIZE Size)
{
	C_FATVOL		*self;
	C_FATFILE		*pFile;
	FILE_SIZE		ReqSize;
	unsigned char	*pubBuf;
	FATVOL_UINT		uiCluster;
	FATVOL_UINT		i;
	
	/* upper cast */
	self  = (C_FATVOL *)pDrvObj;
	pFile = (C_FATFILE *)pFileObj;
	
	pubBuf = (unsigned char *)pBuf;


	/* クリティカルセクションに入る */
	SysMtx_Lock(self->hMtx);
	
	/* サイズチェック */
	if ( !(FileObj_GetMode(&pFile->FileObj) & FILE_OPEN_DIR) )
	{
		if ( Size > pFile->FileSize - pFile->FilePos )
		{
			/* サイズ更新されていないかディレクトリテーブルを参照するべき？ */

			/* サイズクリップ */
			Size = (FILE_SIZE)(pFile->FileSize - pFile->FilePos);
		}
	}
	
	/* 要求読み出し量保存 */
	ReqSize = Size;
	
	/* クラスタを検索 */
	uiCluster = pFile->uiStartCluster;
	for ( i = 0; pFile->FilePos >= (FILE_POS)((i + 1) * self->BytesPerCluster); i++ )
	{
		uiCluster = FatVol_GetNextCluster(self, uiCluster);
	}
	
	/* 読み出し */
	while ( Size > 0 && (pFile->FilePos < pFile->FileSize || (FileObj_GetMode(&pFile->FileObj) & FILE_OPEN_DIR)) )
	{
		FILE_POS 			ReadStart;
		FILE_SIZE			ReadSize;
		T_FATVOL_CLUSTERBUF *pClusterBuf;
		
		/* クラスタチェック */
		if ( uiCluster == FATVOL_CLUSTER_ENDMARKER )
		{
			break;
		}
		
		/* 転送位置計算 */
		ReadStart = (pFile->FilePos & (self->BytesPerCluster) - 1);
		ReadSize  = (FILE_SIZE)(self->BytesPerCluster - ReadStart);
		if ( ReadSize > Size )
		{
			ReadSize     = Size;
		}
		
		/* バッファ取得 */
		if ( (pClusterBuf = FatVol_GetClusterBuf(self, uiCluster, 1)) == NULL )
		{
			break;
		}

		/* 転送 */
		memcpy(pubBuf, &pClusterBuf->pubBuf[ReadStart], ReadSize);

		/* バッファ開放 */
		FatVol_RelClusterBuf(self, pClusterBuf, 0);
		
		/* サイズ更新 */
		pFile->FilePos += ReadSize;
		pubBuf         += ReadSize;
		Size           -= ReadSize;
		
		/* 次のクラスタに進む */
		uiCluster = FatVol_GetNextCluster(self, uiCluster);
		
		/* 一旦ロックを放す */
		SysMtx_Unlock(self->hMtx);
		SysMtx_Lock(self->hMtx);
	}
	
	/* クリティカルセクションを出る */
	SysMtx_Unlock(self->hMtx);
	
	return ReqSize - Size;
}


/* end of file */

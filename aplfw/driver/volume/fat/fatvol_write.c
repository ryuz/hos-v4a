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


/** %jp{書き込み} */
FILE_SIZE FatVol_Write(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size)
{
	C_FATVOL			*self;
	C_FATFILE			*pFile;

	FILE_SIZE			ReqSize;
	const unsigned char	*pubData;
	FATVOL_UINT			uiNextCluster;
	FATVOL_UINT			uiCluster;
	FATVOL_UINT			i;
	int                 iResizeFlag = 0;

	
	/* upper cast */
	self  = (C_FATVOL *)pDrvObj;
	pFile = (C_FATFILE *)pFileObj;

	/* キャスト */
	pubData = (const unsigned char *)pData;

	/* サイズ0なら即時成功 */
	if ( Size <= 0 )
	{
		return 0;
	}

	/* クリティカルセクションに入る */
	SysMtx_Lock(self->hMtx);
	
	/* モードチェック */
	if ( !(FileObj_GetMode(&pFile->FileObj) & FILE_OPEN_WRITE) || (FileObj_GetMode(&pFile->FileObj) & FILE_OPEN_DIR) )
	{
		SysMtx_Unlock(self->hMtx);
		return 0;
	}
		
	/* 書き込み要求量保存 */
	ReqSize = Size;
	
	/* ファイルポインタ位置のクラスタを検索 */
	uiCluster = pFile->uiStartCluster;
	for ( i = 0; pFile->FilePos >= (FILE_POS)((i + 1) * self->BytesPerCluster); i++ )
	{
		/* 次のクラスタを探す */
		uiNextCluster = FatVol_GetNextCluster(self, uiCluster);
		if ( uiNextCluster == FATVOL_CLUSTER_ENDMARKER )
		{
			/* 次クラスタが無ければ作る */
			uiNextCluster = FatVol_AllocCluster(self);
			if ( uiNextCluster == FATVOL_CLUSTER_ENDMARKER )
			{
				return 0;	/* ディスクフル */
			}
			FatVol_SetNextCluster(self, uiCluster, uiNextCluster);
		}
		uiCluster = uiNextCluster;
	}
	
	
	/* 書き出し */
	while ( Size > 0 )
	{
		FILE_POS			WriteStart;
		FILE_SIZE			WriteSize;
		T_FATVOL_CLUSTERBUF	*pClusterBuf;
				
		/* 転送位置計算 */
		WriteStart = (pFile->FilePos & (self->BytesPerCluster - 1));
		WriteSize  = (FILE_SIZE)(self->BytesPerCluster - WriteStart);
		if ( WriteSize > Size )
		{
			WriteSize = Size;
		}

		/* バッファ取得 */
		if ( WriteStart == 0 && pFile->FilePos == pFile->FileSize )
		{
			pClusterBuf = FatVol_GetClusterBuf(self, uiCluster, 0);		/* 完全新規の場合 */
		}
		else
		{
			pClusterBuf = FatVol_GetClusterBuf(self, uiCluster, 1);		/* 部分更新の場合 */
		}
		if ( pClusterBuf == NULL )
		{
			break;
		}

		/* 転送 */
		memcpy(&pClusterBuf->pubBuf[WriteStart], pubData, WriteSize);
	
		/* バッファ開放 */
		FatVol_RelClusterBuf(self, pClusterBuf, 1);
		
		
		/* サイズ更新 */
		pFile->FilePos += WriteSize;
		pubData        += WriteSize;
		Size           -= WriteSize;
		
		/* ファイルサイズ更新 */
		if ( pFile->FileSize < pFile->FilePos )
		{
			pFile->FileSize = pFile->FilePos;
			iResizeFlag     = 1;
		}
		
		/* 完了チェック */
		if ( Size <= 0 )
		{
			break;
		}
		
		/* 次のクラスタを探す */
		uiNextCluster = FatVol_GetNextCluster(self, uiCluster);
		if ( uiNextCluster == FATVOL_CLUSTER_ENDMARKER )
		{
			/* 次クラスタが無ければ作る */
			uiNextCluster = FatVol_AllocCluster(self);
			if ( uiNextCluster == FATVOL_CLUSTER_ENDMARKER )
			{
				break;	/* ディスクフル */
			}
			FatVol_SetNextCluster(self, uiCluster, uiNextCluster);
		}
		uiCluster = uiNextCluster;
		
		/* 一旦ロックを放す */
		SysMtx_Unlock(self->hMtx);
		SysMtx_Lock(self->hMtx);		
	}
	
	/* ディレクトリテーブルのサイズ更新 */
	if ( iResizeFlag &&	!(FileObj_GetMode(&pFile->FileObj) & FILE_OPEN_DIR) )
	{
		FatVol_SyncFileSize(self, pFile);
	}

	/* クリティカルセクションを出る */
	SysMtx_Unlock(self->hMtx);
	
	return ReqSize - Size;	
}


/* end of file */

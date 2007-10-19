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


HANDLE FatVol_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode)
{
	C_FATVOL 			*self;
	FATVOL_UINT			uiCluster;
	HANDLE 				hFile;
	char   				szEntryName[8+1+3+1];
	int    				iEntryNameLen;
	char   				szName[8+1+3+1];
	int    				iNameLen;
	unsigned char		ubAttr;
	FILE_POS			FileSize;
	T_FATVOL_CLUSTERBUF *pClusterBuf;
	unsigned char		*pubBuf;
	FATVOL_UINT			uiDirCluster;	
	FATVOL_UINT			uiDirEntryPos;
	int					iEntryHit;
	int    				i;
	
	/* upper cast */
	self = (C_FATVOL *)pDrvObj;
	
	
	/* クリティカルセクションに入る */
	SysMtx_Lock(self->hMtx);
	
	/* ルートディレクトリを設定 */
	uiDirCluster  = self->RootDirCluster;
	uiDirEntryPos = 0;
	if ( (pClusterBuf = FatVol_GetClusterBuf(self, uiDirCluster, 1)) == NULL )
	{
		SysMtx_Unlock(self->hMtx);
		return HANDLE_NULL;
	}
	
	/* パス探索 */
	for ( ; ; )
	{
		/* 名前の部分を切り出し */
		for ( iNameLen = 0; iNameLen < sizeof(szName) && *pszPath != '\0'; pszPath++, iNameLen++ )
		{
			/* パス区切りなら抜ける */
			if ( *pszPath == '/' )
			{
				pszPath++;
				break;
			}
			szName[iNameLen] = *pszPath;
			
			/* 大文字に変換 */
			if ( szName[iNameLen] >= 'a' && szName[iNameLen] <= 'z' )
			{
				szName[iNameLen] -= ('a' - 'A');
			}
		}
		szName[iNameLen] = '\0';
		
				
		/* ディレクトリ自身を指す場合 */
		if ( iNameLen == 0 )
		{
			/* ディレクトリを閉じる */
			FatVol_RelClusterBuf(self, pClusterBuf, 0);

			/* ディレクトリ指定があれば開く */
			if ( iMode & FILE_OPEN_DIR )
			{
				if ( (hFile = FatVol_FileCreate(self, uiDirCluster, FATVOL_CLUSTER_ENDMARKER, 0, 0, iMode)) != HANDLE_NULL )
				{
					self->iOpenCount++;
					SysMtx_Unlock(self->hMtx);
					return hFile;
				}
			}
			
			/* エラー終了 */
			SysMtx_Unlock(self->hMtx);
			return HANDLE_NULL;				
		}
		
		
		/* ディレクトリエントリを検索 */
		iEntryHit = 0;
		for ( ; ; )
		{
			/* ディレクトリエントリ位置 */
			pubBuf = &pClusterBuf->pubBuf[uiDirEntryPos];
		
			/* 0なら打ち切り */
			if ( pubBuf[0] == 0x00 )
			{
				break;
			}
			
			/* 名前部分取り出し */
			iEntryNameLen = 0;
			for ( i = 0; i < 8; i++ )
			{
				if ( pubBuf[0+i] == ' ' || pubBuf[0+i] == '\0' )
				{
					break;
				}
				szEntryName[iEntryNameLen++] = (char)pubBuf[0+i];
			}
			szEntryName[iEntryNameLen++] = '.';
			for ( i = 0; i < 3; i++ )
			{
				if ( pubBuf[8+i] == ' ' || pubBuf[8+i] == '\0' )
				{
					break;
				}
				szEntryName[iEntryNameLen++] = (char)pubBuf[8+i];
			}
			szEntryName[iEntryNameLen] = '\0';
			if ( iEntryNameLen > 2 && szEntryName[iEntryNameLen-1] == '.' )
			{
				szEntryName[--iEntryNameLen] = '\0';
			}
			
			/* 名前比較 */
			if ( strcmp(szEntryName, szName) == 0 )
			{
				iEntryHit = 1;
				break;
			}
			
			/* シーク */
			uiDirEntryPos += 32;
			if ( uiDirEntryPos >= self->BytesPerCluster )
			{
				FatVol_RelClusterBuf(self, pClusterBuf, 0);
				uiDirCluster = FatVol_GetNextCluster(self, uiDirCluster);
				if ( uiDirCluster == FATVOL_CLUSTER_ENDMARKER
					|| (pClusterBuf = FatVol_GetClusterBuf(self, uiDirCluster, 1)) == NULL )
				{
					SysMtx_Unlock(self->hMtx);
					return HANDLE_NULL;
				}
				uiDirEntryPos = 0;
			}
		}
		
		/* 見つからなければエラー */
		if ( !iEntryHit )
		{
			FatVol_RelClusterBuf(self, pClusterBuf, 0);
			SysMtx_Unlock(self->hMtx);
			return HANDLE_NULL;
		}
		
		/* 開始クラスタ取得 */
		uiCluster = pubBuf[26] + (pubBuf[27] << 8);
		if ( self->iFatType == FATVOL_TYPE_FAT32 )
		{
			uiCluster += (pubBuf[20] << 16) + (pubBuf[21] << 24);
		}

		/* 属性取得 */ 
		ubAttr = pubBuf[11];
		
		/* サイズ取得 */
		FileSize = pubBuf[28] + (pubBuf[29] << 8) + (pubBuf[30] << 16) + (pubBuf[31] << 24);

		/* 親ディレクトリを閉じる */
		FatVol_RelClusterBuf(self, pClusterBuf, 0);

		
		/* パス部分の解析が終わっていればここで抜ける */
		if ( *pszPath == '\0' )
		{
			break;
		}
		
		/* サブディレクトリでなければエラー */
		if ( !(ubAttr & 0x10) )
		{
			SysMtx_Unlock(self->hMtx);
			return HANDLE_NULL;
		}
		
		/* サブディレクトリを開く */
		uiDirCluster = uiCluster;
		uiDirEntryPos = 0;
		if ( (pClusterBuf = FatVol_GetClusterBuf(self, uiDirCluster, 1)) == NULL )
		{
			SysMtx_Unlock(self->hMtx);
			return HANDLE_NULL;
		}
	}
	
	/* モードチェック */
	if ( iMode & FILE_OPEN_DIR )
	{
		SysMtx_Unlock(self->hMtx);
		return HANDLE_NULL;		
	}
	
	/* ファイルディスクリプタを作成 */
	hFile = FatVol_FileCreate(self, uiCluster, uiDirCluster, uiDirEntryPos, FileSize, iMode);
	if ( hFile != HANDLE_NULL )
	{
		self->iOpenCount++;
	}
	
	/* クリティカルセクションを出る */
	SysMtx_Unlock(self->hMtx);
	
	return hFile;
}



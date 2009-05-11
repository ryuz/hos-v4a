/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  fatvol.c
 * @brief %jp{FATボリューム用デバイスドライバ}
 *
 * Copyright (C) 2006-2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <string.h>
#include "hosaplfw.h"
#include "fatvol_local.h"


/* ファイルオープン */
HANDLE FatVol_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode)
{
	C_FATVOL 			*self;
	HANDLE 				hFile;
	FATVOL_UINT			uiDirStartCluster;	
	FATVOL_UINT			uiDirCluster;	
	FATVOL_UINT			uiDirEntryPos;
	char   				szName[8+3];
	int    				iNameLen;
	FATVOL_UINT			uiFileCluster;
	unsigned char		ubFileAttr;
	FILE_POS			FileSize;
	T_FATVOL_CLUSTERBUF *pClusterBuf;
	unsigned char		*pubBuf;
	int					iEntryHit;
	int    				i, j;
	
	
	/* upper cast */
	self = (C_FATVOL *)pDrvObj;
	
	
	/* クリティカルセクションに入る */
	SysMtx_Lock(self->hMtx);
	
	
	/* ルートディレクトリを設定 */
	uiDirStartCluster = FATVOL_CLUSTER_ENDMARKER;
	uiDirCluster      = FATVOL_CLUSTER_ENDMARKER;
	uiDirEntryPos     = 0;
	uiFileCluster     = self->RootDirCluster;
	ubFileAttr        = 0x10;
	FileSize          = 0;
	
	/* パス探索 */
	for ( ; ; )
	{
		/* 区切りを読み飛ばす */
		while ( pszPath[0] == '/' )
		{
			pszPath++;
		}

		/* 名前の部分を探索 */
		for ( i = 0; pszPath[i] != '\0'; i++ )
		{
			/* パス区切りなら抜ける */
			if ( pszPath[i] == '/' )
			{
				break;
			}
		}
		iNameLen = i;

		/* ディレクトリ自身を指す場合 */
		if ( iNameLen == 0 )
		{
			iEntryHit = 1;
			break;
		}
		
		/* ディレクトリエントリ名を作成 */
		for ( i = 0, j = 0; i < iNameLen && j < 8; i++, j++ )
		{
			if ( pszPath[i] == '.' )
			{
				break;
			}
			szName[j] = pszPath[i];
		}
		for ( ; j < 8; j++ )
		{
			szName[j] = 0x20;
		}
		if ( pszPath[i] != '.' && i < iNameLen )	/* ファイル名長すぎ */
		{
			SysMtx_Unlock(self->hMtx);
			return HANDLE_NULL;
		}
		
		/* 拡張子 */
		if ( pszPath[i] == '.' )
		{
			i++;
		}
		for ( j = 0; i < iNameLen && j < 3; i++, j++ )
		{
			szName[8+j] = pszPath[i];
		}
		for ( ; j < 3; j++ )
		{
			szName[8+j] = 0x20;
		}
		if ( i < iNameLen )		/* 拡張子長すぎ */
		{
			SysMtx_Unlock(self->hMtx);
			return HANDLE_NULL;
		}
		

		/* ポインタを進める */
		pszPath += iNameLen;

		
		/* 文字変換 */
		for ( i = 0; i < 8+3; i++ )
		{
			/* 大文字化 */
			if ( szName[i] >= 'a' && szName[i] <= 'z')
			{
				szName[i] -= ('a' - 'A');
			}
		}
		if ( szName[0] == 0xe5 )
		{
			szName[0] = 0x05;
		} 
				
		
		
		/* ディレクトリを開く */
		uiDirStartCluster = uiFileCluster;
		uiDirCluster      = uiDirStartCluster;
		uiDirEntryPos     = 0;
		if ( (pClusterBuf = FatVol_GetClusterBuf(self, uiDirCluster, 1)) == NULL )
		{
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
			
			/* 名前比較 */
			if ( memcmp(pubBuf, szName, 8+3) == 0 )
			{
				/* 開始クラスタ取得 */
				uiFileCluster = pubBuf[26] + (pubBuf[27] << 8);
				if ( self->iFatType == FATVOL_TYPE_FAT32 )
				{
					uiFileCluster += (pubBuf[20] << 16) + (pubBuf[21] << 24);
				}
				
				/* 属性取得 */ 
				ubFileAttr = pubBuf[11];
				
				/* サイズ取得 */
				FileSize = pubBuf[28] + (pubBuf[29] << 8) + (pubBuf[30] << 16) + (pubBuf[31] << 24);
				
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
		
		/* ディレクトリを閉じる */
		FatVol_RelClusterBuf(self, pClusterBuf, 0);
		
		
		/* これ以上開くサブディレクトリがなければ抜ける */
		if ( !(iEntryHit && (ubFileAttr & 0x10)) )
		{
			break;
		}
	}
	
	
	/* パスをすべて探索できていなければNG */
	if ( *pszPath != '\0' )
	{
		SysMtx_Unlock(self->hMtx);
		return HANDLE_NULL;
	}
	
	
	/* ディレクトリに存在しない場合 */
	if ( !iEntryHit )
	{
		/* 新規作成禁止ならばエラー */
		if ( iMode & FILE_OPEN_EXIST )
		{
			SysMtx_Unlock(self->hMtx);
			return HANDLE_NULL;			
		}
				
		/* ディレクトリを開く */
		uiDirCluster  = uiDirStartCluster;
		uiDirEntryPos = 0;
		if ( (pClusterBuf = FatVol_GetClusterBuf(self, uiDirCluster, 1)) == NULL )
		{
			SysMtx_Unlock(self->hMtx);
			return HANDLE_NULL;
		}
		
		/* 空き探索 */
		for ( ; ; )
		{
			/* ディレクトリエントリ位置 */
			pubBuf = &pClusterBuf->pubBuf[uiDirEntryPos];
			
			/* 空き発見 */
			if ( pubBuf[0] == 0xe5 || pubBuf[0] == 0x00 )
			{
				break;
			}
			
			/* シーク */
			uiDirEntryPos += 32;
			if ( uiDirEntryPos >= self->BytesPerCluster )	/* クラスタ越えなら */
			{
				FatVol_RelClusterBuf(self, pClusterBuf, 0);
				uiDirCluster = FatVol_GetNextCluster(self, uiDirCluster);
				if ( uiDirCluster == FATVOL_CLUSTER_ENDMARKER )
				{
					/* FAT32以外のルートディレクトリなら拡張不能 */
					if ( self->iFatType != FATVOL_TYPE_FAT32 && uiDirCluster >= 0x0f000000 )
					{
						SysMtx_Unlock(self->hMtx);
						return HANDLE_NULL;						
					}
					if ( (uiFileCluster = FatVol_AllocCluster(self)) == FATVOL_CLUSTER_ENDMARKER )
					{
						SysMtx_Unlock(self->hMtx);
						return HANDLE_NULL;						
					}
					FatVol_SetNextCluster(self, uiDirCluster, uiFileCluster);
					uiDirCluster = uiFileCluster;
				}
				if ( (pClusterBuf = FatVol_GetClusterBuf(self, uiDirCluster, 1)) == NULL )
				{
					SysMtx_Unlock(self->hMtx);
					return HANDLE_NULL;
				}
				uiDirEntryPos = 0;
			}
		}
		
		/* 新規クラスタ作成 */
		if ( (uiFileCluster = FatVol_AllocCluster(self)) == FATVOL_CLUSTER_ENDMARKER )
		{
			FatVol_RelClusterBuf(self, pClusterBuf, 0);
			SysMtx_Unlock(self->hMtx);
			return HANDLE_NULL;			
		}
		FatVol_SetNextCluster(self, uiFileCluster, FATVOL_CLUSTER_ENDMARKER);
		
		MemUtil_MemSetB(&pubBuf[0], 0, 32);						/* 初期化 */
		MemUtil_MemCopyB(&pubBuf[0], szName, 8+3);				/* ファイル名 */
		pubBuf[11] = (iMode & FILE_OPEN_DIR) ? 0x10 : 0x20;		/* 属性 */
		pubBuf[26] = ((uiFileCluster >>  0) & 0xff);			/* 開始クラスタ */
		pubBuf[27] = ((uiFileCluster >>  8) & 0xff);
		pubBuf[20] = ((uiFileCluster >> 16) & 0xff);
		pubBuf[21] = ((uiFileCluster >> 24) & 0xff);
		FileSize   = 0;
		ubFileAttr = pubBuf[11];
		
		/* ディレクトリを閉じる */
		FatVol_RelClusterBuf(self, pClusterBuf, 1);
	}
	else
	{
		/* 存在した場合 */
		if ( iMode & FILE_OPEN_CREATE )
		{
			FatVol_FreeCluster(self, uiFileCluster);
			FatVol_SetNextCluster(self, uiFileCluster, FATVOL_CLUSTER_ENDMARKER);
			FileSize = 0;
		}
	}
	
	/* モードチェック */
	if ( ((ubFileAttr & 0x10) && !(iMode & FILE_OPEN_DIR))
		|| (!(ubFileAttr & 0x10) && (iMode & FILE_OPEN_DIR)) )
	{
		SysMtx_Unlock(self->hMtx);
		return HANDLE_NULL;		
	}
	
	/* ファイルディスクリプタを作成 */
	hFile = FatFile_Create(self, uiFileCluster, uiDirCluster, uiDirEntryPos, FileSize, iMode);
	if ( hFile != HANDLE_NULL )
	{
		self->iOpenCount++;
	}
	
	/* クリティカルセクションを出る */
	SysMtx_Unlock(self->hMtx);
	
	return hFile;
}


/* end of file */


#include <string.h>
#include "fatvol_local.h"


HANDLE FatVol_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode)
{
	C_FATVOL 		*self;
	unsigned char	ubBuf[32];
	FATVOL_UINT		uiCluster;
	HANDLE 			hDir;
	HANDLE 			hFile;
	char   			szEntryName[8+3+1];
	int    			iEntryNameLen;
	char   			szName[8+3+1];
	int    			iNameLen;
	int    			iDirEntry;
	int    			i, j;
	
	/* upper cast */
	self = (C_FATVOL *)pDrvObj;
	
	/* ルートディレクトリを開く */
	hDir = FatVol_FileCreate(self, self->RootDirCluster, HANDLE_NULL, 0, FILE_OPEN_READ | FILE_OPEN_WRITE | FILE_OPEN_DIR);
	
	for ( ; ; )
	{
		if ( pszPath[iNameLen] == '\0' )
		{
			break;
		}
		
		/* 名前の部分を検索 */
		for ( iNameLen = 0; pszPath[iNameLen] != '\0'; iNameLen++ )
		{
			if ( pszPath[iNameLen] == '/' )
			{
				break;
			}
			
			/* 大文字に変換 */
			if ( pszPath[iNameLen] >= 'a' && pszPath[iNameLen] <= 'z' )
			{
				szName[iNameLen] = pszPath[iNameLen] - ('a' - 'A');
			}
			else
			{
				szName[iNameLen] = pszPath[iNameLen];
			}
		}
		szName[iNameLen] = '\0';
		
		/* ディレクトリエントリを検索 */
		iDirEntry = -1;
		for ( i = 0; File_Read(hDir, ubBuf, 32) == 32; i++ )
		{
			/* 0なら打ち切り */
			if ( ubBuf[0] == 0x00 )
			{
				break;
			}
			
			/* 名前部分取り出し */
			iEntryNameLen = 0;
			for ( j = 0; j < 8; j++ )
			{
				if ( ubBuf[0+j] == ' ' || ubBuf[0+j] == '\0' )
				{
					break;
				}
				szEntryName[iEntryNameLen++] = (char)ubBuf[0+j];
			}
			szEntryName[iEntryNameLen++] = '.';
			for ( j = 0; j < 3; j++ )
			{
				if ( ubBuf[8+j] == ' ' || ubBuf[8+j] == '\0' )
				{
					break;
				}
				szEntryName[iEntryNameLen++] = (char)ubBuf[8+j];
			}
			szEntryName[iEntryNameLen] = '\0';
			if ( iEntryNameLen > 2 && szEntryName[iEntryNameLen-1] == '.' )
			{
				szEntryName[--iEntryNameLen] = '\0';
			}
			
			/* 名前比較 */
			if ( strcmp(szEntryName, szName) == 0 )
			{
				iDirEntry = i;
				break;
			}
		}
		
		/* 開始クラスタ取得 */
		uiCluster = ubBuf[0x1a] + ubBuf[0x1b]*256;
		if ( self->iFatType == FATVOL_TYPE_FAT32 )
		{
			uiCluster += ubBuf[0x14]*256*256 + ubBuf[0x15]*256*256*256;
		}

		/* パス部分の解析が終わっていればここで抜ける */
		if ( pszPath[iNameLen] == '\0' )
		{
			break;
		}
		
		
		/* ディレクトリを閉じる */
		FatVol_FileDelete(self, hDir);
		
		/* サブディレクトリがなければエラー */
		if ( iDirEntry < 0 || !(ubBuf[0x0b] & 0x10) )
		{
			return HANDLE_NULL;
		}
		
		/* サブディレクトリを開く */
		hDir = FatVol_FileCreate(self, uiCluster, HANDLE_NULL, 0, FILE_OPEN_READ | FILE_OPEN_WRITE | FILE_OPEN_DIR);
		
		pszPath += iNameLen;
	}
	
	/* ディレクトリを開くなら */
	if ( iMode & FILE_OPEN_DIR )
	{
		return hDir;
	}
	
	
	/* 既存ファイルがあれば */
	if ( iDirEntry >= 0 )
	{
		hFile = FatVol_FileCreate(self, uiCluster, hDir, iDirEntry, iMode);
		if ( hFile == HANDLE_NULL )
		{
			FatVol_FileDelete(self, hDir);
		}
		return hFile;
	}
	
	return HANDLE_NULL;
}



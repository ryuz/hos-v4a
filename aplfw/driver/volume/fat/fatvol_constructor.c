/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  fatvol.h
 * @brief %jp{FATボリューム用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <string.h>
#include "fatvol_local.h"


/* 仮想関数テーブル */
const T_VOLUMEOBJ_METHODS FatVol_VolumeObjMethods =
{
	{
		{ FatVol_Delete },
		FatVol_Open,
		FatVol_Close,
		FatVol_IoControl,
		FatVol_Seek,
		FatVol_Read,
		FatVol_Write,
		FatVol_Flush,
	},
	FatVol_Shutdown,
	FatVol_MakeDir,
	FatVol_Remove,
};


/* コンストラクタ */
FATVOL_ERR FatVol_Constructor(C_FATVOL *self, const T_VOLUMEOBJ_METHODS *pMethods, const char *pszPath)
{
	unsigned char *pubBuf;
	int           i;
	
	/* 一時バッファ確保 */
	if ( (pubBuf = SysIo_AllocIoMem(512)) == NULL )
	{
		return FATVOL_ERR_NG;
	}
	
	/* 仮想関数テーブル */
	if ( pMethods == NULL )
	{
		pMethods = &FatVol_VolumeObjMethods;
	}
	
	/* メンバ変数初期化 */
	self->iShutdown  = 0;
	self->iOpenCount = 0;
	self->Offset     = 0;
	self->iFatType   = FATVOL_TYPE_UNKNOWN;
	
		
	/* ブロックデバイスのオープン */
	self->hBlockFile = File_Open(pszPath, FILE_OPEN_READ | FILE_OPEN_WRITE);
	if ( self->hBlockFile == HANDLE_NULL )
	{
		SysIo_FreeIoMem(pubBuf);
		return FATVOL_ERR_NG;
	}
			
	/* パーティーションテーブルチェック */
	File_Seek(self->hBlockFile, 0, FILE_SEEK_SET);
	File_Read(self->hBlockFile, pubBuf, 512);
	if ( pubBuf[0x1fe] == 0x55 && pubBuf[0x1ff] == 0xaa )	/* シグネチャコードチェック */
	{
		/* パーティーションテーブル０のみ確認 */
		if ( pubBuf[0x1be + 0x04] == 0x01			/* FAT12 */
				|| pubBuf[0x1be + 0x04] == 0x04		/* FAT16(32MB未満) */
				|| pubBuf[0x1be + 0x04] == 0x06		/* FAT16(32MB以上) */
				|| pubBuf[0x1be + 0x04] == 0x0b		/* FAT32 */
				|| pubBuf[0x1be + 0x04] == 0x0c 		/* FAT32X (LBA) */
				|| pubBuf[0x1be + 0x04] == 0x0e )	/* FAT16X (LBA) */
		{
			self->Offset = pubBuf[0x1be + 0x08]
							+ (pubBuf[0x1be + 0x09] << 8)
							+ (pubBuf[0x1be + 0x0a] << 16)
							+ (pubBuf[0x1be + 0x0b] << 24);
			self->Offset *= 512;
		}
	}
		
	/* サイズ取得 */
	self->DriveSize  = File_Seek(self->hBlockFile, 0, FILE_SEEK_END);

	
	/* BIOS Parameter Block */
	File_Seek(self->hBlockFile, self->Offset, FILE_SEEK_SET);
	File_Read(self->hBlockFile, pubBuf, 512);
	
	/* FAT12/16/32判定 */
	if ( pubBuf[0x36] == 'F' && pubBuf[0x37] == 'A' && pubBuf[0x38] == 'T' && pubBuf[0x39] == '1' )
	{
		if ( pubBuf[0x3a] == '2' )
		{
			self->iFatType = FATVOL_TYPE_FAT12;
		}
		else if ( pubBuf[0x3a] == '6' )
		{
			self->iFatType = FATVOL_TYPE_FAT16;
		}
	}
	else if ( pubBuf[0x52] == 'F' && pubBuf[0x53] == 'A' && pubBuf[0x54] == 'T' && pubBuf[0x55] == '3' && pubBuf[0x56] == '2')
	{
		self->iFatType = FATVOL_TYPE_FAT32;
	}
	
	
	/* フォーマット別情報解析 */
	switch ( self->iFatType )
	{
	case FATVOL_TYPE_FAT12:
	case FATVOL_TYPE_FAT16:
		self->BytesPerSector    = pubBuf[0x0b] + (pubBuf[0x0c] << 8);				/**< セクタサイズ */
		self->SectorsPerCluster = pubBuf[0x0d];										/**< 1クラスタのセクタ数 */
		self->FatStartSector    = pubBuf[0x0e] + (pubBuf[0x0f] << 8);				/**< FATの開始セクタ番号 */
		self->RootDirEntryNum   = pubBuf[0x11] + (pubBuf[0x12] << 8);				/**< ルートディレクトリ最大エントリ数 */
		self->SectorNum         = pubBuf[0x13] + (pubBuf[0x14] << 8);				/**< 総セクタ数 */
		self->SectorPerFat      = pubBuf[0x16] + (pubBuf[0x17] << 8);				/**< FATあたりのセクタ数 */
		self->FatNum            = pubBuf[0x10];										/**< FAT個数 */
		self->RootDirSector     = self->FatStartSector + (self->SectorPerFat * self->FatNum);
																					/**< ルートディレクトリ開始位置 */

		self->BytesPerCluster   = self->BytesPerSector * self->SectorsPerCluster;	/**< 1クラスタサイズ */
		self->Cluster0Sector    = self->RootDirSector
										+ (((self->RootDirEntryNum * 32) + self->BytesPerSector - 1) / self->BytesPerSector)
										- (2 * self->SectorsPerCluster);			/**< クラスタ0の開始セクタ */
		
		/* 総クラスタ数算出 */
		if ( self->iFatType == FATVOL_TYPE_FAT12 )
		{
			self->ClusterNum = (self->SectorPerFat * self->BytesPerSector) / 4 * 3;
		}
		else
		{
			self->ClusterNum = (self->SectorPerFat * self->BytesPerSector) / 2;
		}
		/* self->ClusterNum        = (self->SectorNum - self->Cluster0Sector) / self->SectorsPerCluster; */
		
		/* ルートディレクトリを仮想位置に設置 */
		self->RootDirCluster    = 0x0f000000;
		
		/* FATバッファ準備 */
		self->pubFatBuf   = (unsigned char *)SysIo_AllocIoMem((MEMSIZE)(self->SectorPerFat * self->BytesPerSector));
		self->pubFatDirty = (unsigned char *)SysMem_Alloc((MEMSIZE)self->SectorPerFat);
		if ( self->pubFatBuf == NULL || self->pubFatDirty == NULL )
		{
			SysIo_FreeIoMem(self->pubFatBuf);
			SysMem_Free(self->pubFatDirty);
			File_Close(self->hBlockFile);
			SysIo_FreeIoMem(pubBuf);
			return FATVOL_ERR_NG;
		}

		/* FAT読み出し */
		File_Seek(self->hBlockFile, self->FatStartSector * self->BytesPerSector  + self->Offset, FILE_SEEK_SET);
		File_Read(self->hBlockFile, self->pubFatBuf, (FILE_SIZE)(self->SectorPerFat * self->BytesPerSector));
		memset(self->pubFatDirty, 0, (size_t)self->SectorPerFat);
		
		break;


	case FATVOL_TYPE_FAT32:
		self->BytesPerSector    = pubBuf[0x0b] + (pubBuf[0x0c] << 8);				/**< セクタサイズ */
		self->SectorsPerCluster = pubBuf[0x0d];										/**< 1クラスタのセクタ数 */
		self->FatStartSector    = pubBuf[0x0e] + (pubBuf[0x0f] << 8);				/**< FATの開始セクタ番号 */
		self->RootDirEntryNum   = pubBuf[0x11] + (pubBuf[0x12] << 8);				/**< ルートディレクトリ最大エントリ数 */
		self->SectorNum         = pubBuf[0x20] + (pubBuf[0x21] << 8) + (pubBuf[0x22] << 16) + (pubBuf[0x23] << 24);
		self->SectorPerFat      = pubBuf[0x24] + (pubBuf[0x25] << 8) + (pubBuf[0x26] << 16) + (pubBuf[0x27] << 24);	/**< FATあたりのセクタ数 */
		self->FatNum            = pubBuf[0x10];										/**< FAT個数 */
		self->RootDirSector     = self->FatStartSector + (self->SectorPerFat * self->FatNum);
																					/**< ルートディレクトリ開始位置 */

		self->BytesPerCluster   = self->BytesPerSector * self->SectorsPerCluster;	/**< 1クラスタサイズ */
		self->Cluster0Sector    = self->RootDirSector
										+ (((self->RootDirEntryNum * 32) + self->BytesPerSector - 1) / self->BytesPerSector)
										- (2 * self->SectorsPerCluster);			/**< クラスタ0の開始セクタ */
		
	/*	self->ClusterNum        = (self->SectorNum - self->Cluster0Sector) / self->SectorsPerCluster;	*/
		self->ClusterNum        = (self->SectorPerFat * self->BytesPerSector) / 4;
																					/**< 総クラスタ数 */

		self->RootDirCluster    = pubBuf[0x2c] + (pubBuf[0x2d] << 8) + (pubBuf[0x2e] << 16) + (pubBuf[0x2f] << 24);
		
		/* FATバッファ準備 */
		self->pubFatBuf   = (unsigned char *)SysIo_AllocIoMem((MEMSIZE)(self->SectorPerFat * self->BytesPerSector));
		self->pubFatDirty = (unsigned char *)SysMem_Alloc((MEMSIZE)self->SectorPerFat);
		if ( self->pubFatBuf == NULL || self->pubFatDirty == NULL )
		{
			SysIo_FreeIoMem(self->pubFatBuf);
			SysMem_Free(self->pubFatDirty);
			File_Close(self->hBlockFile);
			SysIo_FreeIoMem(pubBuf);
			return FATVOL_ERR_NG;
		}
		
		/* FAT読み出し */
		File_Seek(self->hBlockFile, self->FatStartSector * self->BytesPerSector  + self->Offset, FILE_SEEK_SET);
		File_Read(self->hBlockFile, self->pubFatBuf, (FILE_SIZE)(self->SectorPerFat * self->BytesPerSector));
		memset(self->pubFatDirty, 0, (size_t)self->SectorPerFat);

		break;
	
	default:
		File_Close(self->hBlockFile);
		SysIo_FreeIoMem(pubBuf);
		return FATVOL_ERR_NG;
	}
	
	/* クラスタバッファ取得 */
	self->iClusterBufNum   = 8;
	self->pClusterBuf = (T_FATVOL_CLUSTERBUF *)SysMem_Alloc(sizeof(T_FATVOL_CLUSTERBUF) * self->iClusterBufNum);
	for ( i = 0; i < self->iClusterBufNum; i++ )
	{
		self->pClusterBuf[i].uiClusterNum = FATVOL_CLUSTER_ENDMARKER;
		self->pClusterBuf[i].iDirty       = 0;
		self->pClusterBuf[i].pubBuf       = SysIo_AllocIoMem((MEMSIZE)self->BytesPerCluster);
	}
	
	/* 親クラスコンストラクタ呼び出し */
	VolumeObj_Constructor(&self->VolumeObj, pMethods);	
	
	/* ミューテックス生成 */
	self->hMtx = SysMtx_Create(SYSMTX_ATTR_NORMAL);
	
	/* 一時バッファ開放 */
	SysIo_FreeIoMem(pubBuf);
	
	return FATVOL_ERR_OK;
}




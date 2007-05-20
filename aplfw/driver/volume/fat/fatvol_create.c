
#include <string.h>
#include "fatvol_local.h"


/* 仮想関数テーブル */
const T_VOLUMEOBJ_METHODS FatVol_VolumeObjMethods =
{
	{
		FatVol_Delete,
		FatVol_Open,
		FatVol_Close,
		FatVol_IoControl,
		FatVol_Seek,
		FatVol_Read,
		FatVol_Write,
		FatVol_Flush,
	},
	FatVol_MakeDir,
	FatVol_Remove,
};


/* コンストラクタ */
int FatVol_Create(C_FATVOL *self, HANDLE hBlockFile)
{
	unsigned char ubBuf[512];
	int           i;
	
	/* 親クラスコンストラクタ呼び出し */
	VolumeObj_Create(&self->VolumeObj, &FatVol_VolumeObjMethods);	
	
	
	/* ドライブの設定 */
	self->hBlockFile = hBlockFile;
	self->Offset   = 0x33*512;	/* 一時的に ちょいインチキ */
	
	
	/* サイズ取得 */
	self->DriveSize  = File_Seek(self->hBlockFile, FILE_SEEK_END, 0);
	self->iFatType   = FATVOL_TYPE_UNKNOWN;
	
	
	/* BIOS Parameter Block */
	File_Seek(self->hBlockFile, self->Offset, FILE_SEEK_SET);
	File_Read(self->hBlockFile, ubBuf, 512);
	
	/* FAT12/16/32判定 */
	if ( ubBuf[0x36] == 'F' && ubBuf[0x37] == 'A' && ubBuf[0x38] == 'T' && ubBuf[0x39] == '1' )
	{
		if ( ubBuf[0x3a] == '2' )
		{
			self->iFatType = FATVOL_TYPE_FAT12;
		}
		else if ( ubBuf[0x3a] == '6' )
		{
			self->iFatType = FATVOL_TYPE_FAT16;
		}
	}
	else if ( ubBuf[0x52] == 'F' && ubBuf[0x53] == 'A' && ubBuf[0x54] == 'T' && ubBuf[0x55] == '3' && ubBuf[0x56] == '2')
	{
		self->iFatType = FATVOL_TYPE_FAT32;
	}
	
	
	/* フォーマット別情報解析 */
	switch ( self->iFatType )
	{
	case FATVOL_TYPE_FAT12:
	case FATVOL_TYPE_FAT16:
		self->BytesPerSector    = ubBuf[0x0b] + ubBuf[0x0c] * 256;			/**< セクタサイズ */
		self->SectorsPerCluster = ubBuf[0x0d];								/**< 1クラスタのセクタ数 */
		self->RootDirEntryNum   = ubBuf[0x11] + ubBuf[0x12] * 256;			/**< ルートディレクトリ最大エントリ数 */
		self->FatStartSector    = ubBuf[0x0e] + ubBuf[0x0f] * 256;			/**< FATの開始セクタ番号 */
		self->SectorPerFat      = ubBuf[0x16] + ubBuf[0x17] * 256;			/**< FATあたりのセクタ数 */
		self->FatNum            = ubBuf[0x10];								/**< FAT個数 */
		self->RootDirSector     = self->FatStartSector + (self->SectorPerFat * self->FatNum);
																			/**< ルートディレクトリ開始位置 */
		self->Cluster0Sector    = self->RootDirSector
										+ (((self->RootDirEntryNum * 32) + self->BytesPerSector - 1) / self->BytesPerSector)
										- (2 * self->SectorsPerCluster);	/**< クラスタ0の開始セクタ */
				
		/* FATバッファ準備 */
		self->pubFatBuf   = (unsigned char *)SysMem_Alloc(self->SectorPerFat * self->BytesPerSector);
		self->pubFatDirty = (unsigned char *)SysMem_Alloc(self->SectorPerFat);

		/* FATバッファ準備 */
		File_Seek(self->hBlockFile, self->FatStartSector * self->BytesPerSector, FILE_SEEK_SET);
		File_Read(self->hBlockFile, self->pubFatBuf, self->SectorPerFat * self->BytesPerSector);
		memset(self->pubFatDirty, 0, self->SectorPerFat);

		break;

	case FATVOL_TYPE_FAT32:
		break;
	
	default:
		return FATVOL_ERR_NG;
	}
	
	/* 最大クラスタ番号算出 */
	switch ( self->iFatType )
	{
	case FATVOL_TYPE_FAT12:
		self->MaxClusterNum = (self->SectorPerFat * self->BytesPerSector) / 3 * 2;
		if ( self->MaxClusterNum >= 0x0ff7 )
		{
			self->MaxClusterNum = 0x0ff6;
		}
		break;

	case FATVOL_TYPE_FAT16:
		self->MaxClusterNum = (self->SectorPerFat * self->BytesPerSector) / 2;
		if ( self->MaxClusterNum >= 0xfff7 )
		{
			self->MaxClusterNum = 0xfff6;
		}
		break;

	case FATVOL_TYPE_FAT32:
		self->MaxClusterNum = (self->SectorPerFat * self->BytesPerSector) / 4;
		break;
	}
	
	/* クラスタバッファ取得 */
	self->iClusterBufIndex = 0;
	self->iClusterBufNum   = 32;
	self->pClusterBuf = (T_FATVOL_CLUSTERBUF *)SysMem_Alloc(sizeof(T_FATVOL_CLUSTERBUF) * self->iClusterBufNum);
	for ( i = 0; i < self->iClusterBufNum; i++ )
	{
		self->pClusterBuf[i].uiClusterNum = FATVOL_CLUSTER_ENDMARKER;
		self->pClusterBuf[i].iDirty       = 0;
		self->pClusterBuf[i].pubBuf       = SysMem_Alloc(self->SectorsPerCluster * self->BytesPerSector);
	}
	
	return FATVOL_ERR_OK;
}




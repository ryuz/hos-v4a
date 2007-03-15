
#include <string.h>
#include "fatvol_local.h"


int FatVol_Create(C_FATVOL *self, HANDLE hBlockFile)
{
	unsigned char ubBuf[512];
	int           i;
	
	/* ドライブの設定 */
	self->hBlockFile = hBlockFile;
	self->uiOffset   = 0x33*512;
	
	/* サイズ取得 */
	self->uiDriveSize = File_Seek(self->hBlockFile, FILE_SEEK_END, 0);
	self->iFatType    = FATVOL_TYPE_UNKNOWN;
	
	/* BIOS Parameter Block */
	File_Seek(self->hBlockFile, self->uiOffset, FILE_SEEK_SET);
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
		self->uiBytesPerSector    = ubBuf[0x0b] + ubBuf[0x0c] * 256;		/**< セクタサイズ */
		self->uiSectorsPerCluster = ubBuf[0x0d];							/**< 1クラスタのセクタ数 */
		self->uiRootDirEntryNum   = ubBuf[0x11] + ubBuf[0x12] * 256;		/**< ルートディレクトリ最大エントリ数 */
		self->uiFatStartSector    = ubBuf[0x0e] + ubBuf[0x0f] * 256;		/**< FATの開始セクタ番号 */
		self->uiSectorPerFat      = ubBuf[0x16] + ubBuf[0x17] * 256;		/**< FATあたりのセクタ数 */
		self->uiFatNum            = ubBuf[0x10];							/**< FAT個数 */
		self->uiRootDirSector     = self->uiFatStartSector + (self->uiSectorPerFat * self->uiFatNum);
																			/**< ルートディレクトリ開始位置 */
		self->uiCluster0Sector    = self->uiRootDirSector
										+ (((self->uiRootDirEntryNum * 32) + self->uiBytesPerSector - 1) / self->uiBytesPerSector)
										- (2 * self->uiSectorsPerCluster);	/**< クラスタ0の開始セクタ */
				
		/* FATバッファ準備 */
		self->pubFatBuf   = (unsigned char *)SysMem_Alloc(self->uiSectorPerFat * self->uiBytesPerSector);
		self->pubFatDirty = (unsigned char *)SysMem_Alloc(self->uiSectorPerFat);

		/* FATバッファ準備 */
		File_Seek(self->hBlockFile, self->uiFatStartSector * self->uiBytesPerSector, FILE_SEEK_SET);
		File_Read(self->hBlockFile, self->pubFatBuf, self->uiSectorPerFat * self->uiBytesPerSector);
		memset(self->pubFatDirty, 0, self->uiSectorPerFat);

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
		self->uiMaxClusterNum = (self->uiSectorPerFat * self->uiBytesPerSector) / 3 * 2;
		if ( self->uiMaxClusterNum >= 0x0ff7 )
		{
			self->uiMaxClusterNum = 0x0ff6;
		}
		break;

	case FATVOL_TYPE_FAT16:
		self->uiMaxClusterNum = (self->uiSectorPerFat * self->uiBytesPerSector) / 2;
		if ( self->uiMaxClusterNum >= 0xfff7 )
		{
			self->uiMaxClusterNum = 0xfff6;
		}
		break;

	case FATVOL_TYPE_FAT32:
		self->uiMaxClusterNum = (self->uiSectorPerFat * self->uiBytesPerSector) / 4;
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
		self->pClusterBuf[i].pubBuf       = SysMem_Alloc(self->uiSectorsPerCluster * self->uiBytesPerSector);
	}
	
	return FATVOL_ERR_OK;
}




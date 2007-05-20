#include "fatvol_local.h"


/** クラスタ読み込み */
int FatVol_ClusterRead(
		C_FATVOL    *self,
		FATVOL_UINT uiCluster,
		void        *pBuf)
{
	FATVOL_UINT uiPos;
	FATVOL_UINT uiSize;

	if ( uiCluster >= 0xffff0000 && (self->iFatType == FATVOL_TYPE_FAT12 || self->iFatType == FATVOL_TYPE_FAT16) )
	{
		/* FAT12/16 のルートディレクトリを 0xf0000000 にマップ */
		uiCluster -= 0xf0000000;
		
		/* 読み出し位置移動 */
		uiPos = (self->RootDirSector + (uiCluster * self->SectorsPerCluster)) * self->BytesPerSector;
		if ( File_Seek(self->hBlockFile, uiPos, FILE_SEEK_SET) != uiPos )
		{
			return FATVOL_ERR_NG;
		}
		
		/* 読み出し */
		uiSize = self->BytesPerSector * self->SectorsPerCluster;
		if ( File_Read(self->hBlockFile, pBuf, uiSize) != uiSize )
		{
			return FATVOL_ERR_NG;
		}
	}
	else
	{
		/* 読み出し位置移動 */
		uiPos = (self->Cluster0Sector + (uiCluster * self->SectorsPerCluster)) * self->BytesPerSector;
		if ( File_Seek(self->hBlockFile, uiPos, FILE_SEEK_SET) != uiPos )
		{
			return FATVOL_ERR_NG;
		}

		/* 読み出し */
		uiSize = self->BytesPerSector * self->SectorsPerCluster;
		if ( File_Read(self->hBlockFile, pBuf, uiSize) != uiSize )
		{
			return FATVOL_ERR_NG;
		}
	}
	
	return FATVOL_ERR_OK;
}


/* end of file */

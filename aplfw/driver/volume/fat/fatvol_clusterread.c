/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  fatvol.c
 * @brief %jp{FATボリューム用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "fatvol_local.h"


/** クラスタ読み込み */
int FatVol_ClusterRead(
		C_FATVOL    *self,
		FATVOL_UINT uiCluster,
		void        *pBuf)
{
	FATVOL_UINT uiPos;
	FILE_SIZE	uiSize;

	if ( uiCluster >= 0x0f000000 && (self->iFatType == FATVOL_TYPE_FAT12 || self->iFatType == FATVOL_TYPE_FAT16) )
	{
		/* FAT12/16 のルートディレクトリを 0xf0000000 にマップ */
		uiCluster -= 0x0f000000;
		
		/* 読み出し位置移動 */
		uiPos = (self->RootDirSector + (uiCluster * self->SectorsPerCluster)) * self->BytesPerSector + self->Offset;
		if ( File_Seek(self->hBlockFile, uiPos, FILE_SEEK_SET) != uiPos )
		{
			return FATVOL_ERR_NG;
		}
		
		/* 読み出し */
		uiSize = (FILE_SIZE)self->BytesPerCluster;
		if ( File_Read(self->hBlockFile, pBuf, uiSize) != uiSize )
		{
			return FATVOL_ERR_NG;
		}
	}
	else
	{
		/* 読み出し位置移動 */
		uiPos = (self->Cluster0Sector + (uiCluster * self->SectorsPerCluster)) * self->BytesPerSector + self->Offset;
		if ( File_Seek(self->hBlockFile, uiPos, FILE_SEEK_SET) != uiPos )
		{
			return FATVOL_ERR_NG;
		}

		/* 読み出し */
		uiSize = (FILE_SIZE)self->BytesPerCluster;
		if ( File_Read(self->hBlockFile, pBuf, uiSize) != uiSize )
		{
			return FATVOL_ERR_NG;
		}
	}
	
	return FATVOL_ERR_OK;
}


/* end of file */

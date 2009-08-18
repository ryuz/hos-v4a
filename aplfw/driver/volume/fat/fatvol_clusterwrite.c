/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  fatvol.c
 * @brief %jp{FATボリューム用デバイスドライバ}
 *
 * Copyright (C) 2006-2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "fatvol_local.h"


#include "hosaplfw.h"


/** クラスタ書き込み */
int FatVol_ClusterWrite(
		C_FATVOL    *self,
		FATVOL_UINT uiCluster,
		const void  *pBuf)
{
	FATVOL_UINT uiPos;
	FATVOL_UINT uiSize;
	
/*	StdIo_PrintFormat("[FatLol] write cluster %08x\n", uiCluster);	*/
	
	
	if ( uiCluster >= 0x0f000000 && (self->iFatType == FATVOL_TYPE_FAT12 || self->iFatType == FATVOL_TYPE_FAT16) )
	{
		/* FAT12/16 のルートディレクトリを 0x0f000000 にマップ */
		uiCluster -= 0x0f000000;
		
		/* 書き出し位置移動 */
		uiPos = (self->RootDirSector + (uiCluster * self->SectorsPerCluster)) * self->BytesPerSector + self->Offset;
		if ( File_Seek(self->hBlockFile, uiPos, FILE_SEEK_SET) != uiPos )
		{
			return FATVOL_ERR_NG;
		}
		
		/* 書き出し */
		uiSize = self->BytesPerSector * self->SectorsPerCluster;
		if ( File_Write(self->hBlockFile, pBuf, (FILE_SIZE)uiSize) != uiSize )
		{
			return FATVOL_ERR_NG;
		}
	}
	else
	{
		/* 書き出し位置移動 */
		uiPos = (self->Cluster0Sector + (uiCluster * self->SectorsPerCluster)) * self->BytesPerSector + self->Offset;
		if ( File_Seek(self->hBlockFile, uiPos, FILE_SEEK_SET) != uiPos )
		{
			return FATVOL_ERR_NG;
		}
		
		/* 書き出し */
		uiSize = self->BytesPerSector * self->SectorsPerCluster;
		if ( File_Write(self->hBlockFile, pBuf, (FILE_SIZE)uiSize) != uiSize )
		{
			return FATVOL_ERR_NG;
		}
	}
	
	return FATVOL_ERR_OK;
}


/* end of file */



#include "fatvol_local.h"


void FatVol_SetNextCluster(C_FATVOL *self, FATVOL_UINT uiCluster, FATVOL_UINT uiNextCluster)
{
	switch ( self->iFatType )
	{
	case FATVOL_TYPE_FAT12:
		/* FAT更新 */
		if ( uiCluster % 2 == 0 )
		{
			self->pubFatBuf[(uiCluster / 2) * 3 + 0] = uiNextCluster & 0xff;
			self->pubFatBuf[(uiCluster / 2) * 3 + 1] = ((uiNextCluster >> 8) & 0x0f) | (self->pubFatBuf[(uiCluster / 2) * 3 + 1] & 0xf0);
		}
		else
		{
			self->pubFatBuf[(uiCluster / 2) * 3 + 1] = ((uiNextCluster << 4) & 0xf0) | (self->pubFatBuf[(uiCluster / 2) * 3 + 1] & 0x0f);
			self->pubFatBuf[(uiCluster / 2) * 3 + 2] = ((uiNextCluster >> 4) & 0xff);
		}

		/* 更新フラグ設定 */
		self->pubFatDirty[((uiCluster / 2) * 3 + 0) / self->BytesPerSector] = 1;
		self->pubFatDirty[((uiCluster / 2) * 3 + 2) / self->BytesPerSector] = 1;
		break;
		
	case FATVOL_TYPE_FAT16:
		/* FAT更新 */
		self->pubFatBuf[uiCluster * 2 + 0] = uiNextCluster % 256;
		self->pubFatBuf[uiCluster * 2 + 1] = uiNextCluster / 256;

		/* 更新フラグ設定 */
		self->pubFatDirty[(uiCluster * 2) / self->BytesPerSector] = 1;
		break;

	case FATVOL_TYPE_FAT32:
		/* FAT更新 */
		self->pubFatBuf[uiCluster * 2 + 0] = uiNextCluster % 256;
		self->pubFatBuf[uiCluster * 2 + 1] = (uiNextCluster / 256) % 256;
		self->pubFatBuf[uiCluster * 2 + 2] = (uiNextCluster / 256 / 256) % 256;
		self->pubFatBuf[uiCluster * 2 + 3] = (uiNextCluster / 256 / 256 / 256) % 256;

		/* 更新フラグ設定 */
		self->pubFatDirty[(uiCluster * 4) / self->BytesPerSector] = 1;
	}
}


/* end of file */

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


FATVOL_UINT FatVol_GetNextCluster(C_FATVOL *self, FATVOL_UINT uiCluster)
{
	FATVOL_UINT uiNextCluster = FATVOL_CLUSTER_ENDMARKER;
	
	if ( uiCluster == FATVOL_CLUSTER_ENDMARKER )
	{
		return FATVOL_CLUSTER_ENDMARKER;
	}
	
	switch ( self->iFatType )
	{
	case FATVOL_TYPE_FAT12:
		/* 0x0f000000 からルートディレクトリをマップ */
		if ( uiCluster >= 0x0f000000 )
		{
			if ( uiCluster >= 0x0f00001f )
			{
				return FATVOL_CLUSTER_ENDMARKER;
			}
			return uiCluster + 1;
		}
		
		/* FAT検索 */
		if ( uiCluster % 2 == 0 )
		{
			uiNextCluster = self->pubFatBuf[(uiCluster / 2) * 3 + 0]
							+ ((self->pubFatBuf[(uiCluster / 2) * 3 + 1] & 0x0f) << 8);
		}
		else
		{
			uiNextCluster = ((self->pubFatBuf[(uiCluster / 2) * 3 + 1] >> 4) & 0xf)
							+ (self->pubFatBuf[(uiCluster / 2) * 3 + 2] << 4);
		}
		
		if ( uiNextCluster >= 0x0ff7 )
		{
			uiNextCluster = FATVOL_CLUSTER_ENDMARKER;
		}
		break;
	
	case FATVOL_TYPE_FAT16:
		/* 0x0f000000 からルートディレクトリをマップ */
		if ( uiCluster >= 0x0f000000 )
		{
			if ( uiCluster >= 0x0f00001f )
			{
				return FATVOL_CLUSTER_ENDMARKER;
			}
			return uiCluster + 1;
		}
		
		/* FAT検索 */
		uiNextCluster = self->pubFatBuf[uiCluster * 2] + (self->pubFatBuf[uiCluster * 2 + 1] << 8);
		if ( uiNextCluster >= 0xfff7 )
		{
			uiNextCluster = FATVOL_CLUSTER_ENDMARKER;
		}
		break;

	case FATVOL_TYPE_FAT32:
		uiNextCluster = self->pubFatBuf[uiCluster * 4]
				+ (self->pubFatBuf[uiCluster * 4 + 1] << 8)
				+ (self->pubFatBuf[uiCluster * 4 + 2] << 16)
				+ (self->pubFatBuf[uiCluster * 4 + 3] << 24);
		
		if ( uiCluster >= 0x0ffffff7 )
		{
			return FATVOL_CLUSTER_ENDMARKER;
		}

		break;
	}
	
	return uiNextCluster;
}


/* end of file */

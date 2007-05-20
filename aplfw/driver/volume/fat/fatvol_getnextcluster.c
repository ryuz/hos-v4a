
#include <string.h>
#include "fatvol_local.h"


FATVOL_UINT FatVol_GetNextCluster(C_FATVOL *self, FATVOL_UINT uiCluster)
{
	FATVOL_UINT uiNextCluster = FATVOL_CLUSTER_ENDMARKER;
	
	switch ( self->iFatType )
	{
	case FATVOL_TYPE_FAT12:
		/* 0xffff0000 からルートディレクトリをマップ */
		if ( uiCluster >= 0xffff0000 )
		{
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
		/* 0xffff0000 からルートディレクトリをマップ */
		if ( uiCluster >= 0xffff0000 )
		{
			return uiCluster + 1;
		}
		
		/* FAT検索 */
		uiNextCluster = self->pubFatBuf[uiCluster * 2] + self->pubFatBuf[uiCluster * 2 + 1] * 256;
		if ( uiNextCluster >= 0xfff7 )
		{
			uiNextCluster = FATVOL_CLUSTER_ENDMARKER;
		}
		break;

	case FATVOL_TYPE_FAT32:
		uiNextCluster = self->pubFatBuf[uiCluster * 4]
				+ self->pubFatBuf[uiCluster * 4 + 1] * 256
				+ self->pubFatBuf[uiCluster * 4 + 2] * 256 * 256
				+ self->pubFatBuf[uiCluster * 4 + 3] * 256 * 256 * 256;
		break;
	}
	
	return uiNextCluster;
}


/* end of file */

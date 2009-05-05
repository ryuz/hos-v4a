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


/* 空きクラスタの獲得 */
FATVOL_UINT  FatVol_AllocCluster(C_FATVOL *self)
{
	FATVOL_UINT	uiCluster;
	
	/* 空きクラスタ検索 */
	for ( uiCluster = 2; uiCluster < self->ClusterNum; uiCluster++ )
	{
		if ( FatVol_GetNextCluster(self, uiCluster) == FATVOL_CLUSTER_FREE )
		{
			FatVol_SetNextCluster(self, uiCluster, FATVOL_CLUSTER_ENDMARKER);
			return uiCluster;
		}
	}
	
	/* 空き無し */
	return FATVOL_CLUSTER_ENDMARKER;
}


/* end of file */

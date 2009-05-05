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


/* クラスタの開放 */
void FatVol_FreeCluster(C_FATVOL *self, FATVOL_UINT uiCluster)
{
	FATVOL_UINT	uiNextCluster;
	
	/* クラスタ開放 */
	do
	{
		uiNextCluster = FatVol_GetNextCluster(self, uiCluster);
		FatVol_SetNextCluster(self, uiCluster, FATVOL_CLUSTER_FREE);
		uiCluster = uiNextCluster;
	}
	while ( uiCluster != FATVOL_CLUSTER_ENDMARKER );
}


/* end of file */

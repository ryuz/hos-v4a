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


void FatVol_FlushClusterBuf(C_FATVOL *self)
{
	int i;
	
	for ( i = 0; i < self->iClusterBufNum; i++ )
	{
		if ( self->pClusterBuf[i].uiClusterNum != FATVOL_CLUSTER_ENDMARKER && self->pClusterBuf[i].iDirty )
		{
			FatVol_ClusterWrite(self, self->pClusterBuf[i].uiClusterNum, self->pClusterBuf[i].pubBuf);
			self->pClusterBuf[i].iDirty = 0;
		}
	}
}


/* end of file */

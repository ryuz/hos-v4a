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


static int FatVol_AlloctClusterBuf(C_FATVOL *self, FATVOL_UINT uiCluster, int iRead);


T_FATVOL_CLUSTERBUF *FatVol_GetClusterBuf(C_FATVOL *self, FATVOL_UINT uiCluster, int iRead)
{
	int iIndex;
	
	/* バッファを割り当てる */
	iIndex = FatVol_AlloctClusterBuf(self, uiCluster, iRead);
	if ( iIndex < 0 )
	{
		return NULL;
	}
	
	/* 並び替える */
	if ( iIndex != 0 )
	{
		T_FATVOL_CLUSTERBUF Tmp;
		Tmp = self->pClusterBuf[iIndex];
		memmove(&self->pClusterBuf[1], &self->pClusterBuf[0], iIndex * sizeof(T_FATVOL_CLUSTERBUF));
		self->pClusterBuf[0] = Tmp;
	}

	return 	&self->pClusterBuf[0];
}


int FatVol_AlloctClusterBuf(C_FATVOL *self, FATVOL_UINT uiCluster, int iRead)
{
	int iIndex;
	
	if ( uiCluster < 2 || uiCluster >= 0x0ffffff7 )
	{
		return -1;
	}
	
	/* 既にバッファに居ないか探索 */
	for ( iIndex = 0; iIndex < self->iClusterBufNum; iIndex++ )
	{
		/* 見つかれば既存バッファを返す */
		if ( self->pClusterBuf[iIndex].uiClusterNum == uiCluster )
		{
			return iIndex;
		}
	}
	
	
	/* 空のバッファを探す */
	for ( iIndex = 0; iIndex < self->iClusterBufNum; iIndex++ )
	{
		if ( self->pClusterBuf[iIndex].uiClusterNum == FATVOL_CLUSTER_ENDMARKER )
		{
			break;
		}
	}
	
	/* 空きが無ければ空ける */
	if ( iIndex >= self->iClusterBufNum )
	{
		/* 末尾を空ける */
		iIndex = self->iClusterBufNum - 1;

		/* dirtyなら吐き出す */
		if ( self->pClusterBuf[iIndex].iDirty )
		{
			if ( FatVol_ClusterWrite(self, self->pClusterBuf[iIndex].uiClusterNum, self->pClusterBuf[iIndex].pubBuf) != FATVOL_ERR_OK )
			{
				return -1;
			}
			self->pClusterBuf[iIndex].iDirty = 0;
		}
		self->pClusterBuf[iIndex].uiClusterNum = FATVOL_CLUSTER_ENDMARKER;
	}
	
	/* バッファに読み込み */
	if ( iRead )
	{
		if ( FatVol_ClusterRead(self, uiCluster, self->pClusterBuf[iIndex].pubBuf) != FATVOL_ERR_OK )
		{
			return -1;
		}
	}
	self->pClusterBuf[iIndex].iDirty       = 0;
	self->pClusterBuf[iIndex].uiClusterNum = uiCluster;
	
	return iIndex;	
}


/* end of file */

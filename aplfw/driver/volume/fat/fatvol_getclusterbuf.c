
#include "fatvol_local.h"


/**< クラスタ読み込み */
int FatVol_GetClusterBuf(
		C_FATVOL    *self,
		FATVOL_UINT uiCluster,
		void        **ppBuf,
		int         iRead)
{
	int i;
	
	/* 既にバッファに居ないか探索 */
	for ( i = 0; i < self->iClusterBufNum; i++ )
	{
		/* 見つかれば既存バッファを返す */
		if ( self->ppClusterBuf[i]->uiClusterNum == uiCluster )
		{
			*ppBuf = (char *)self->ppClusterBuf[i] + sizeof(T_FATVOL_CLUSTERBUF);
			return FATVOL_ERR_OK;
		}
	}
	
	/* 空のバッファを探す */
	for ( i = 0; i < self->iClusterBufNum; i++ )
	{
		if ( self->ppClusterBuf[i]->uiClusterNum == FATVOL_CLUSTER_ENDMARKER )
		{
			break;
		}
	}
	
	/* 空きが無ければ空ける */
	if ( i >= self->iClusterBufNum )
	{
		/* FIFO順でフラッシュ */
		i = self->iClusterBufIndex++;
		
		/* dirtyなら吐き出す */
		if ( self->ppClusterBuf[i]->iDirty )
		{
			if ( FatVol_ClusterWrite(self, self->ppClusterBuf[i]->uiClusterNum, (char *)self->ppClusterBuf[i] + sizeof(T_FATVOL_CLUSTERBUF)) != FATVOL_ERR_OK )
			{
				return FATVOL_ERR_NG;
			}
			self->ppClusterBuf[i]->iDirty = 0;
		}
		self->ppClusterBuf[i]->uiClusterNum = FATVOL_CLUSTER_ENDMARKER;
	}
	
	/* バッファに読み込み */
	if ( iRead )
	{
		if ( FatVol_ClusterRead(self, uiCluster, (char *)self->ppClusterBuf[i] + sizeof(T_FATVOL_CLUSTERBUF)) != FATVOL_ERR_OK )
		{
			return FATVOL_ERR_NG;
		}
	}
	self->ppClusterBuf[i]->iDirty       = 0;
	self->ppClusterBuf[i]->uiClusterNum = uiCluster;
	
	/* バッファ割り当て */
	*ppBuf = (char *)self->ppClusterBuf[i] + sizeof(T_FATVOL_CLUSTERBUF);
	
	
	return FATVOL_ERR_OK;	
}


/* end of file */

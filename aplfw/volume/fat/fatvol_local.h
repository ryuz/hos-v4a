

#ifndef __HOS__fatvol_local_h__
#define __HOS__fatvol_local_h__


#include "fatvol.h"


/* 最終クラスタマーカー */
#define FATVOL_CLUSTER_FREE				0x00000000
#define FATVOL_CLUSTER_ENDMARKER		0xffffffff


/* ファイルシステムのタイプ */
#define FATVOL_TYPE_UNKNOWN				0
#define FATVOL_TYPE_FAT12				1
#define FATVOL_TYPE_FAT16				2
#define FATVOL_TYPE_FAT32				3


#ifdef __cplusplus
extern "C" {
#endif

int FatVol_ClusterWrite(C_FATVOL *self, FATVOL_UINT uiCluster, const void *pBuf);			/**< クラスタ書き込み */
int FatVol_ClusterRead(C_FATVOL *self, FATVOL_UINT uiCluster, void *pBuf);					/**< クラスタ読み込み */
int FatVol_GetClusterBuf(C_FATVOL *self, FATVOL_UINT uiCluster, void **ppBuf, int iRead);
int FatVol_RelClusterBuf(C_FATVOL *self, void *ppBuf, int iDirty);							

FATVOL_UINT FatVol_GetNextCluster(C_FATVOL *self, FATVOL_UINT uiCluster);
void        FatVol_SetNextCluster(C_FATVOL *self, FATVOL_UINT uiCluster, FATVOL_UINT uiNextCluster);


#ifdef __cplusplus
}
#endif


#endif	/*  __HOS__fatvol_local_h__ */


/* end of file */

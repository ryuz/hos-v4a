

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

HANDLE      FatVol_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode);
void        FatVol_Close(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj);
FILE_ERR    FatVol_IoControl(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize);
FILE_POS    FatVol_Seek(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, FILE_POS Offset, int iOrign);
FILE_SIZE   FatVol_Read(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, void *pBuf, FILE_SIZE Size);
FILE_SIZE   FatVol_Write(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size);
FILE_ERR    FatVol_Flush(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj);

FILE_ERR    FatVol_MakeDir(C_VOLUMEOBJ *self, const char *pszPath);									/* サブディレクトリを作成 */
FILE_ERR    FatVol_Remove(C_VOLUMEOBJ *self, const char *pszPath);									/* ファイルを削除 */


int         FatVol_ClusterWrite(C_FATVOL *self, FATVOL_UINT uiCluster, const void *pBuf);			/**< クラスタ書き込み */
int         FatVol_ClusterRead(C_FATVOL *self, FATVOL_UINT uiCluster, void *pBuf);					/**< クラスタ読み込み */
int         FatVol_GetClusterBuf(C_FATVOL *self, FATVOL_UINT uiCluster, void **ppBuf, int iRead);
int         FatVol_RelClusterBuf(C_FATVOL *self, void *ppBuf, int iDirty);							

FATVOL_UINT FatVol_GetNextCluster(C_FATVOL *self, FATVOL_UINT uiCluster);
void        FatVol_SetNextCluster(C_FATVOL *self, FATVOL_UINT uiCluster, FATVOL_UINT uiNextCluster);


#ifdef __cplusplus
}
#endif


#endif	/*  __HOS__fatvol_local_h__ */


/* end of file */

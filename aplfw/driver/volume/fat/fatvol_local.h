/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  fatvol.h
 * @brief %jp{FATボリューム用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


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


/* クラスタバッファ */
typedef struct c_fatfile
{
	C_FILEOBJ	FileObj;			/* ボリュームオブジェクトを継承 */
		
	int			iMode;				/* ファイルのモード */
	FATVOL_UINT	uiStartCluster;		/* ファイルの先頭クラスタ */
	HANDLE		hDir;				/* 所属するディレクトリのハンドル */
	int			iDirEntry;			/* ディレクトリ内のエントリ位置 */
	
	FILE_POS	FilePos;			/* ファイルポインタ */
	FILE_POS	FileSize;			/* ファイルサイズ */
	
	FATVOL_UINT	uiCurrentCluster;	/* 現在のクラスタ */
} C_FATFILE;


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

FILE_ERR    FatVol_MakeDir(C_VOLUMEOBJ *pVolObj, const char *pszPath);									/* サブディレクトリを作成 */
FILE_ERR    FatVol_Remove(C_VOLUMEOBJ *pVolObj, const char *pszPath);									/* ファイルを削除 */

HANDLE      FatVol_FileCreate(C_FATVOL *self, FATVOL_UINT uiCluster, HANDLE hDir, int iDirEntry, int iMode);
void        FatVol_FileDelete(C_FATVOL *self, HANDLE hFile);

FILE_POS    FatVol_GetFileSize(HANDLE hDir, int iDirEntry);
void        FatVol_SetFileSize(HANDLE hDir, int iDirEntry, FILE_POS Size);

int         FatVol_ClusterWrite(C_FATVOL *self, FATVOL_UINT uiCluster, const void *pBuf);				/**< クラスタ書き込み */
int         FatVol_ClusterRead(C_FATVOL *self, FATVOL_UINT uiCluster, void *pBuf);						/**< クラスタ読み込み */
int         FatVol_GetClusterBuf(C_FATVOL *self, FATVOL_UINT uiCluster, void **ppBuf, int iRead);
int         FatVol_RelClusterBuf(C_FATVOL *self, void *ppBuf, int iDirty);							

FATVOL_UINT FatVol_GetNextCluster(C_FATVOL *self, FATVOL_UINT uiCluster);
void        FatVol_SetNextCluster(C_FATVOL *self, FATVOL_UINT uiCluster, FATVOL_UINT uiNextCluster);


#ifdef __cplusplus
}
#endif


#endif	/*  __HOS__fatvol_local_h__ */


/* end of file */

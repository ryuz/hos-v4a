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
#include "system/file/volumeobj_local.h"


/* 最終クラスタマーカー */
#define FATVOL_CLUSTER_FREE				0x00000000
#define FATVOL_CLUSTER_ENDMARKER		0x0fffffff


/* ファイルシステムのタイプ */
#define FATVOL_TYPE_UNKNOWN				0
#define FATVOL_TYPE_FAT12				1
#define FATVOL_TYPE_FAT16				2
#define FATVOL_TYPE_FAT32				3


/* クラスタバッファ */
typedef struct t_fatvol_clusterbuf
{
	FATVOL_UINT		uiClusterNum;
	int				iDirty;
	unsigned char	*pubBuf;
} T_FATVOL_CLUSTERBUF;


/* クラスタバッファ */
typedef struct c_fatvol
{
	C_VOLUMEOBJ			VolumeObj;					/* ボリュームオブジェクトを継承 */

	HANDLE				hBlockFile;					/**< ブロックデバイスドライバのハンドル */
	
	SYSMTX_HANDLE		hMtx;						/**< ロック用ミューテックス */
	
	int					iShutdown;					/**< シャットダウンフラグ */
	int					iOpenCount;					/**< オープンカウンタ */
	
	int					iFatType;					/**< FATのタイプ */
	FILE_POS			Offset;						/**< ディスクのオフセット */
	FILE_POS			DriveSize;					/**< ドライブの総サイズ */
	FATVOL_UINT			BytesPerSector;				/**< セクタサイズ */
	FATVOL_UINT			SectorsPerCluster;			/**< クラスタあたりのセクタ数 */
	FATVOL_UINT			BytesPerCluster;			/**< クラスタサイズ */
	FATVOL_UINT			FatStartSector;				/**< FATの開始セクタ番号 */
	FATVOL_UINT			SectorNum;					/**< 総セクタ数 */
	FATVOL_UINT			SectorPerFat;				/**< FATあたりのセクタ数 */
	FATVOL_UINT			FatNum;						/**< FATの個数 */
	FATVOL_UINT			RootDirEntryNum;			/**< ルートディレクトリのエントリ数 */
	FATVOL_UINT			RootDirSector;				/**< ルートディレクトリのセクタ */
	FATVOL_UINT			Cluster0Sector;				/**< クラスタ0のセクタ番号 */
	FATVOL_UINT			ClusterNum;					/**< 総クラスタ数 */
	FATVOL_UINT			RootDirCluster;				/**< ルートディレクトリのクラスタ番号 */
	
	unsigned char		*pubFatBuf;					/**< FATのバッファリングメモリ */
	unsigned char		*pubFatDirty;				/**< FATの更新フラグ */
	
	struct t_fatvol_clusterbuf	*pClusterBuf;
	int							iClusterBufNum;
} C_FATVOL;


#include "fatfile.h"


struct c_fatfile;

#ifdef __cplusplus
extern "C" {
#endif

FATVOL_ERR          FatVol_Constructor(C_FATVOL *self, const T_VOLUMEOBJ_METHODS *pMethods, const char *pszPath);
void                FatVol_Destructor(C_FATVOL *self);

HANDLE              FatVol_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode);
void                FatVol_Close(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj);
FILE_ERR            FatVol_IoControl(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize);
FILE_POS            FatVol_Seek(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, FILE_POS Offset, int iOrign);
FILE_SIZE           FatVol_Read(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, void *pBuf, FILE_SIZE Size);
FILE_SIZE           FatVol_Write(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size);
FILE_ERR            FatVol_Flush(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj);

FILE_ERR            FatVol_Shutdown(C_VOLUMEOBJ *pVolObj);														/**< シャットダウン */
FILE_ERR            FatVol_MakeDir(C_VOLUMEOBJ *pVolObj, const char *pszPath);									/**< サブディレクトリを作成 */
FILE_ERR            FatVol_Remove(C_VOLUMEOBJ *pVolObj, const char *pszPath);									/**< ファイルを削除 */

void                FatVol_SyncFileSize(C_FATVOL *self, struct c_fatfile *pFile);								/**< サイズ同期 */

int                 FatVol_ClusterWrite(C_FATVOL *self, FATVOL_UINT uiCluster, const void *pBuf);				/**< クラスタ書き込み */
int                 FatVol_ClusterRead(C_FATVOL *self, FATVOL_UINT uiCluster, void *pBuf);						/**< クラスタ読み込み */

T_FATVOL_CLUSTERBUF *FatVol_GetClusterBuf(C_FATVOL *self, FATVOL_UINT uiCluster, int iRead);
void                FatVol_RelClusterBuf(C_FATVOL *self, T_FATVOL_CLUSTERBUF *pClusterBuf, int iDirty);							
void                FatVol_FlushClusterBuf(C_FATVOL *self);

FATVOL_UINT         FatVol_AllocCluster(C_FATVOL *self);
void                FatVol_FreeCluster(C_FATVOL *self, FATVOL_UINT uiCluster);
FATVOL_UINT         FatVol_GetNextCluster(C_FATVOL *self, FATVOL_UINT uiCluster);
void                FatVol_SetNextCluster(C_FATVOL *self, FATVOL_UINT uiCluster, FATVOL_UINT uiNextCluster);


void        FatVol_FlushFat(C_FATVOL *self);


#ifdef __cplusplus
}
#endif


#endif	/*  __HOS__fatvol_local_h__ */


/* end of file */

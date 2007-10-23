/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  fatvol.h
 * @brief %jp{FATボリューム用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__fatvol_h__
#define __HOS__fatvol_h__


#include "system/sysapi/sysapi.h"
#include "system/file/volumeobj.h"


#define FATVOL_ERR_OK		0
#define FATVOL_ERR_NG		(-1)


/* 型定義 */
typedef	long			FATVOL_INT;
typedef unsigned long	FATVOL_UINT;

struct t_fatvol_clusterbuf;

/* クラスタバッファ */
typedef struct c_fatvol
{
	C_VOLUMEOBJ			VolumeObj;					/* ボリュームオブジェクトを継承 */

	HANDLE				hBlockFile;					/**< ブロックデバイスドライバのハンドル */
	
	SYSMTX_HANDLE		hMtx;						/**< ロック用ミューテックス */
	
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
//	int							iClusterBufIndex;
} C_FATVOL;


#ifdef __cplusplus
extern "C" {
#endif

int    FatVol_Create(C_FATVOL *self, const char *pszPath);
void   FatVol_Delete(C_DRVOBJ *self);

HANDLE FatVol_CreateFile(C_FATVOL *self, FATVOL_UINT uiCluster, HANDLE hDir, int iDirEntry, int iMode);

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__fatdrive_h__ */




#ifndef __HOS__fatvol_h__
#define __HOS__fatvol_h__


#include "system/sysapi/sysapi.h"
#include "system/file/volumeobj.h"


#define FATVOL_ERR_OK		0
#define FATVOL_ERR_NG		(-1)


/* 型定義 */
typedef unsigned long	FATVOL_UINT;


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

	int					iFatType;					/**< FATのタイプ */
	FILE_POS			Offset;						/**< ディスクのオフセット */
	FILE_POS			DriveSize;					/**< ドライブの総サイズ */
	FATVOL_UINT			BytesPerSector;				/**< セクタサイズ */
	FATVOL_UINT			SectorsPerCluster;			/**< クラスタサイズ */
	FATVOL_UINT			FatStartSector;				/**< FATの開始セクタ番号 */
	FATVOL_UINT			SectorPerFat;				/**< FATあたりのセクタ数 */
	FATVOL_UINT			FatNum;						/**< FATの個数 */
	FATVOL_UINT			RootDirEntryNum;			/**< ルートディレクトリのエントリ数 */
	FATVOL_UINT			RootDirSector;				/**< ルートディレクトリのセクタ */
	FATVOL_UINT			Cluster0Sector;				/**< クラスタ0のセクタ番号 */
	FATVOL_UINT			MaxClusterNum;				/**< 最大クラスタ番号 */
	FATVOL_UINT			RootDirCluster;				/**< ルートディレクトリのクラスタ番号 */
	
	unsigned char		*pubFatBuf;					/**< FATのバッファリングメモリ */
	unsigned char		*pubFatDirty;				/**< FATの更新フラグ */
	
	T_FATVOL_CLUSTERBUF	*pClusterBuf;
	int					iClusterBufNum;
	int					iClusterBufIndex;
} C_FATVOL;


#ifdef __cplusplus
extern "C" {
#endif

int    FatVol_Create(C_FATVOL *self, HANDLE hBlockFile);
void   FatVol_Delete(C_DRVOBJ *self);

HANDLE FatVol_CreateFile(C_FATVOL *self, FATVOL_UINT uiCluster, HANDLE hDir, int iDirEntry, int iMode);

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__fatdrive_h__ */



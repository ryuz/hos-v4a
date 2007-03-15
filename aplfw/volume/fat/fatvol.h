

#ifndef __HOS__fatvol_h__
#define __HOS__fatvol_h__


#include "system/sysapi/sysapi.h"
#include "system/file/file.h"


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
	HANDLE			hBlockFile;					/**< ブロックデバイスドライバのハンドル */

	int				iFatType;					/**< FATのタイプ */
	FATVOL_UINT		uiOffset;					/**< ディスクのオフセット */
	FATVOL_UINT		uiDriveSize;				/**< ドライブの総サイズ */
	FATVOL_UINT		uiBytesPerSector;			/**< セクタサイズ */
	FATVOL_UINT		uiSectorsPerCluster;		/**< クラスタサイズ */
	FATVOL_UINT		uiFatStartSector;			/**< FATの開始セクタ番号 */
	FATVOL_UINT		uiSectorPerFat;				/**< FATあたりのセクタ数 */
	FATVOL_UINT		uiFatNum;					/**< FATの個数 */
	FATVOL_UINT		uiRootDirEntryNum;			/**< ルートディレクトリのエントリ数 */
	FATVOL_UINT		uiRootDirSector;			/**< ルートディレクトリのセクタ */
	FATVOL_UINT		uiCluster0Sector;			/**< クラスタ0のセクタ番号 */
	FATVOL_UINT		uiMaxClusterNum;			
	FATVOL_UINT	    uiRootDirCluster;			
	
	unsigned char	*pubFatBuf;					/**< FATのバッファリングメモリ */
	unsigned char	*pubFatDirty;				/**< FATの更新フラグ */

	T_FATVOL_CLUSTERBUF	*pClusterBuf;
	int					iClusterBufNum;
	int					iClusterBufIndex;	
} C_FATVOL;


#ifdef __cplusplus
extern "C" {
#endif

int    FatVol_Create(C_FATVOL *self, HANDLE hBlockFile);
void   FatVol_Delete(C_FATVOL *self);
HANDLE FatVol_CreateFile(C_FATVOL *self, FATVOL_UINT uiCluster, HANDLE hDir, int iDirEntry, int iMode);

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__fatdrive_h__ */



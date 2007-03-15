/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  fatfile.h
 * @brief %jp{FATファイルシステム ファイルI/Fクラス}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__fatfile_h__
#define __HOS__fatfile_h__


#include "system/file/fileobj.h"
#include "fatvol.h"


typedef struct c_fatfile
{
	C_FILEOBJ	FileObj;			/* ファイルオブジェクトを継承 */

	int			iMode;				/* ファイルのモード */
	C_FATVOL	*pFatVol;			/* FatVolクラスの参照 */
	FATVOL_UINT	uiStartCluster;		/* ファイルの先頭クラスタ */
	HANDLE		hDir;				/* 所属するディレクトリのハンドル */
	int			iDirEntry;			/* ディレクトリ内のエントリ位置 */

	FILE_POS	FilePos;			/* ファイルポインタ */
	FILE_POS	FileSize;			/* ファイルサイズ */
	
	FATVOL_UINT	uiCurrentCluster;	/* 現在のクラスタ */
	FATVOL_UINT	uiClusterSize;		/* クラスタサイズ */
} C_FATFILE;


#ifdef __cplusplus
extern "C" {
#endif

FILE_ERR FatFile_Create(C_FATFILE *self, C_FATVOL *pFatVol, FATVOL_UINT uiCluster, HANDLE hDir, int iDirEntry, int iMode);		/**< コンストラクタ */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__pc16550file_h__ */


/* end of file */

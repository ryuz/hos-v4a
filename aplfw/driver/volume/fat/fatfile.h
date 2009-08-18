/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  fatvol.h
 * @brief %jp{FATボリューム用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__fatfile_h__
#define __HOS__fatfile_h__


#include "fatvol_local.h"
#include "system/file/fileobj_local.h"


/* ファイルディスクリプタ */
typedef struct c_fatfile
{
	C_FILEOBJ	FileObj;			/* ボリュームオブジェクトを継承 */
	
	FATVOL_UINT	uiStartCluster;		/* ファイルの先頭クラスタ */
	
	FATVOL_UINT	uiDirCluster;		/* 所属するディレクトリのクラスタ位置 */
	FATVOL_UINT	uiDirEntryPos;		/* ディレクトリ内のエントリ位置 */
	
	FILE_POS	FilePos;			/* ファイルポインタ */
	FILE_POS	FileSize;			/* ファイルサイズ */
} C_FATFILE;



#ifdef __cplusplus
extern "C" {
#endif

HANDLE FatFile_Create(C_FATVOL *pFatVol, FATVOL_UINT uiStartCluster, FATVOL_UINT uiDirCluster, FATVOL_UINT uiDirEntryPos, FILE_POS FileSize, int iMode);
void   FatFile_Delete(HANDLE hFile);

#ifdef __cplusplus
}
#endif


#endif	/*  __HOS__fatvol_local_h__ */


/* end of file */

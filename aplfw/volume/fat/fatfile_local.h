/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  fatfile.h
 * @brief %jp{FATファイルシステム ファイルI/Fクラス}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__fatfile_local_h__
#define __HOS__fatfile_local_h__


#include "fatfile.h"
#include "fatvol_local.h"

#ifdef __cplusplus
extern "C" {
#endif

void      FatFile_Delete(HANDLE hFile);
FILE_ERR  FatFile_IoControl(HANDLE hFile, int iFunc, const void *pInBuf, FILE_SIZE InSize, void *pOutBuf, FILE_SIZE OutSize);
FILE_POS  FatFile_Seek(HANDLE hFile, FILE_POS Offset, int iOrign);
FILE_SIZE FatFile_Read(HANDLE hFile, void *pBuf, FILE_SIZE Size);
FILE_SIZE FatFile_Write(HANDLE hFile, const void *pData, FILE_SIZE Size);

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__fatfile_local_h__ */


/* end of file */

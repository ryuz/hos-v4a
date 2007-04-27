/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  drvobj_local.h
 * @brief %jp{デバイスドライバファイルの基本クラス ローカルメンバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__drvfile_local_h__
#define __HOS__drvfile_local_h__


#include "system/file/drvfile.h"
#include "system/file/drvobj.h"


/* ハンドル変換 */
#define DRVFILE_HANDLE2OBJ(hFile)		((C_DRVFILE *)(hFile))


#ifdef __cplusplus
extern "C" {
#endif

void      DrvFile_Delete(HANDLE hFile);										/**< デストラクタ */
FILE_ERR  DrvFile_IoControl(HANDLE hFile, int iFunc, const void *pInBuf, FILE_SIZE InSize, void *pOutBuf, FILE_SIZE OutSize);
FILE_POS  DrvFile_Seek(HANDLE hFile, FILE_POS Offset, int iOrign);
FILE_SIZE DrvFile_Write(HANDLE hFile, const void *pData, FILE_SIZE Size);	/**< 書込み */
FILE_SIZE DrvFile_Read(HANDLE hFile, void *pBuf, FILE_SIZE Size);			/**< 読込み */
FILE_ERR  DrvFile_Flush(HANDLE hFile);

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__drvfile_local_h__ */


/* end of file */

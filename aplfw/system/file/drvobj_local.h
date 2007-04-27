/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  drvobj.h
 * @brief %jp{デバイスドライバオブジェクトの基本クラス ローカルメンバ}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__drvobj_local_h__
#define __HOS__drvobj_local_h__


#include "system/file/drvobj.h"


#ifdef __cplusplus
extern "C" {
#endif

FILE_ERR  DrvObj_Close(HANDLE hDrv, HANDLE hFile);
FILE_ERR  DrvObj_IoControl(HANDLE hDrv, HANDLE hFile, int iFunc, const void *pInBuf, FILE_SIZE InSize, void *pOutBuf, FILE_SIZE OutSize);
FILE_SIZE DrvObj_Read(HANDLE hDrv, HANDLE hFile, void *pBuf, FILE_POS Pos, FILE_SIZE Size);
FILE_SIZE DrvObj_Write(HANDLE hDrv, HANDLE hFile, const void *pData, FILE_POS Pos, FILE_SIZE Size);
FILE_ERR  DrvObj_Flush(HANDLE hDrv, HANDLE hFile);

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__drvobj_local_h__ */


/* end of file */

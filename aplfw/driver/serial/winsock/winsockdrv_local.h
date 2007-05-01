/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  winsockdrv.h
 * @brief %jp{WinSockでシリアルを擬似するドライバ}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__winsockdrv_local_h__
#define __HOS__winsockdrv_local_h__


#include "winsockdrv.h"


#ifdef __cplusplus
extern "C" {
#endif

HANDLE    WinSockDrv_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode);
FILE_ERR  WinSockDrv_Close(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj);
FILE_ERR  WinSockDrv_IoControl(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize);
FILE_POS  WinSockDrv_Seek(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, FILE_POS Offset, int iOrign);
FILE_SIZE WinSockDrv_Read(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, void *pBuf, FILE_SIZE Size);
FILE_SIZE WinSockDrv_Write(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size);
FILE_ERR  WinSockDrv_Flush(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj);

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__winsockdrv_local_h__ */


/* end of file */

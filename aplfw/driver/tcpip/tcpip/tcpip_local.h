/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  tcpip_local.h
 * @brief %jp{TCP/IP プロトコル}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__tcpip_local_h__
#define __HOS__tcpip_local_h__


#include "tcpip.h"


#ifdef __cplusplus
extern "C" {
#endif

HANDLE    Tcpip_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode);
void      Tcpip_Close(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj);
FILE_ERR  Tcpip_IoControl(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize);
FILE_POS  Tcpip_Seek(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, FILE_POS Offset, int iOrign);
FILE_SIZE Tcpip_Read(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, void *pBuf, FILE_SIZE Size);
FILE_SIZE Tcpip_Write(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size);
FILE_ERR  Tcpip_Flush(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj);

void      Tcpip_Recv(VPARAM Param);																			/* 受信プロセス */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__Tcpip_local_h__ */


/* endof file */

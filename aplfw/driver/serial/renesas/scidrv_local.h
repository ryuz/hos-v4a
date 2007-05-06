/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scidrv.h
 * @brief %jp{SCI用デバイスドライバ ローカルヘッダファイル}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__scidrv_local_h__
#define __HOS__scidrv_local_h__


#include "scidrv.h"


#ifdef __cplusplus
extern "C" {
#endif

void      SciDrv_Delete(C_DRVOBJ *pDrvObj);
HANDLE    SciDrv_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode);
FILE_ERR  SciDrv_Close(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj);
FILE_ERR  SciDrv_IoControl(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize);
FILE_POS  SciDrv_Seek(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, FILE_POS Offset, int iOrign);
FILE_SIZE SciDrv_Read(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, void *pBuf, FILE_SIZE Size);
FILE_SIZE SciDrv_Write(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size);
FILE_ERR  SciDrv_Flush(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj);

void      SciDrv_IsrRecvErr(VPARAM Param);	/* 受信エラー割込み */
void      SciDrv_IsrRecv(VPARAM Param);		/* 受信割込み */
void      SciDrv_IsrSendEnd(VPARAM Param);	/* 送信エンプティー割込み */
void      SciDrv_IsrSend(VPARAM Param);		/* 送信終了割込み */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__scidrv_local_h__ */


/* end of file */

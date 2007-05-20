/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  lan9000drv.h
 * @brief %jp{LAN9000ファミリー用デバイスドライバ ローカルヘッダファイル}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__lan9000drv_local_h__
#define __HOS__lan9000drv_local_h__


#include "lan9000drv.h"


#ifdef __cplusplus
extern "C" {
#endif

HANDLE    Lan9000Drv_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode);
void      Lan9000Drv_Close(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj);
FILE_ERR  Lan9000Drv_IoControl(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize);
FILE_POS  Lan9000Drv_Seek(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, FILE_POS Offset, int iOrign);
FILE_SIZE Lan9000Drv_Read(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, void *pBuf, FILE_SIZE Size);
FILE_SIZE Lan9000Drv_Write(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size);
FILE_ERR  Lan9000Drv_Flush(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj);

void      Lan9000Drv_Isr(VPARAM Param);			/* 割込み処理 */


#ifdef __cplusplus
}
#endif


#endif	/* __HOS__lan9000drv_local_h__ */


/* end of file */

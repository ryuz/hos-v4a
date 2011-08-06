/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  ne2000drv.c
 * @brief %jp{NE2000互換Ether用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__ne2000drv_local_h__
#define __HOS__ne2000drv_local_h__

#include "ne2000drv.h"


#ifdef __cplusplus
extern "C" {
#endif

HANDLE    Ne2000Drv_Open(C_FILEOBJ *pFileObj, const char *pszPath, int iMode);
void      Ne2000Drv_Close(C_FILEOBJ *pFileObj, C_FILEPTR *pFilePtr);
FILE_ERR  Ne2000Drv_IoControl(C_FILEOBJ *pFileObj, C_FILEPTR *pFilePtr, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize);
FILE_POS  Ne2000Drv_Seek(C_FILEOBJ *pFileObj, C_FILEPTR *pFilePtr, FILE_POS Offset, int iOrign);
FILE_SIZE Ne2000Drv_Read(C_FILEOBJ *pFileObj, C_FILEPTR *pFilePtr, void *pBuf, FILE_SIZE Size);
FILE_SIZE Ne2000Drv_Write(C_FILEOBJ *pFileObj, C_FILEPTR *pFilePtr, const void *pData, FILE_SIZE Size);
FILE_ERR  Ne2000Drv_Flush(C_FILEOBJ *pFileObj, C_FILEPTR *pFilePtr);

void      Ne2000Drv_Isr(VPARAM Param);			/* 割込み処理 */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__ne2000drv_local_h__ */


/* end of file */

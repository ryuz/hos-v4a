/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  ipether.h
 * @brief %jp{Ether上にIPプロトコルを実装(つまりMAC層近辺)}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__ipether_local_h__
#define __HOS__ipether_local_h__


#include "ipether.h"
#include "system/file/syncdrv_local.h"


#ifdef __cplusplus
extern "C" {
#endif

FILE_ERR  IpEther_Constructor(C_IPETHER *self, const T_FILEOBJ_METHODS *pMethods, const char *pszEther, const T_IPETHER_INF *pInf);	/**< コンストラクタ */
void      IpEther_Destructor(C_IPETHER *self);																						/**< デストラクタ */

HANDLE    IpEther_Open(C_FILEOBJ *pFileObj, const char *pszPath, int iMode);
void      IpEther_Close(C_FILEOBJ *pFileObj, C_FILEPTR *pFilePtr);
FILE_ERR  IpEther_IoControl(C_FILEOBJ *pFileObj, C_FILEPTR *pFilePtr, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize);
FILE_POS  IpEther_Seek(C_FILEOBJ *pFileObj, C_FILEPTR *pFilePtr, FILE_POS Offset, int iOrign);
FILE_SIZE IpEther_Read(C_FILEOBJ *pFileObj, C_FILEPTR *pFilePtr, void *pBuf, FILE_SIZE Size);
FILE_SIZE IpEther_Write(C_FILEOBJ *pFileObj, C_FILEPTR *pFilePtr, const void *pData, FILE_SIZE Size);
FILE_ERR  IpEther_Flush(C_FILEOBJ *pFileObj, C_FILEPTR *pFilePtr);

void      IpEther_Recv(void);																						/* 受信プロセス */

FILE_ERR  IpEther_GetMacAddr(C_IPETHER *self, unsigned char ubMacAddr[6], const unsigned char ubIpAddr[4]);			/* MACアドレス解決 */
void      IpEther_AddMacAddr(C_IPETHER *self, const unsigned char ubMacAddr[6], const unsigned char ubIpAddr[4]);	/* MACアドレス登録 */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__ipether_local_h__ */


/* endof file */

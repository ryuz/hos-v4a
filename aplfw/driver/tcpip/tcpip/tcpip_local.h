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
#include "tcpipfile.h"
#include "system/file/syncdrv_local.h"


#define TCP_FLAG_FIN			0x01
#define TCP_FLAG_SYN			0x02
#define TCP_FLAG_RST			0x04
#define TCP_FLAG_PSH			0x08
#define TCP_FLAG_ACK			0x10
#define TCP_FLAG_URG			0x20



#ifdef __cplusplus
extern "C" {
#endif

FILE_ERR  TcpIp_Constructor(C_TCPIP *self, const T_DRVOBJ_METHODS *pMethods, const char *pszIp);	/**< コンストラクタ */
void      TcpIp_Destructor(C_TCPIP *self);															/**< デストラクタ */

HANDLE    TcpIp_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode);
void      TcpIp_Close(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj);
FILE_ERR  TcpIp_IoControl(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize);
FILE_POS  TcpIp_Seek(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, FILE_POS Offset, int iOrign);
FILE_SIZE TcpIp_Read(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, void *pBuf, FILE_SIZE Size);
FILE_SIZE TcpIp_Write(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size);
FILE_ERR  TcpIp_Flush(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj);

int       TcpIp_GetSendBuf(C_TCPIP *self, void **ppBuf);		/* IPデータグラム送信バッファ取得 */
void      TcpIp_SendBuf(C_TCPIP *self, void **ppBuf);			/* IPデータグラムバッファ送信 */
void      TcpIp_Recv(void);								/* IPパケット受信プロセス */


#ifdef __cplusplus
}
#endif


#endif	/* __HOS__tcpip_local_h__ */


/* endof file */

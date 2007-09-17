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
#include "system/file/chrfile.h"
#include "library/container/stmbuf/stmbuf.h"


#define TCP_FLAG_FIN			0x01
#define TCP_FLAG_SYN			0x02
#define TCP_FLAG_RST			0x04
#define TCP_FLAG_PSH			0x08
#define TCP_FLAG_ACK			0x10
#define TCP_FLAG_URG			0x20


#define TCPIPFILE_TYPE_TCP		6
#define TCPIPFILE_TYPE_UDP		17

#define TCPIPFILE_RECV_BUFSIZE	2048


typedef struct c_tcpipfile
{
	C_CHRFILE			ChrFile;		/* キャラクタ型ファイルオブジェクトを継承 */

	char				iType;
	unsigned char		ubIpAddr[4];
	unsigned short		uhPortNum;
	SYSEVT_HANDLE		hEvtRecv;
	
	struct c_tcpipfile	*pNext;
	struct c_tcpipfile	*pPrev;
	
	C_STREAMBUF			RecvBuf;
	unsigned char		ubRecvBuf[TCPIPFILE_RECV_BUFSIZE];
	
} C_TCPIPFILE;



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

int       Tcpip_GetSendBuf(C_TCPIP *self, void **ppBuf);		/* IPデータグラム送信バッファ取得 */
void      Tcpip_SendBuf(C_TCPIP *self, void **ppBuf);			/* IPデータグラムバッファ送信 */
void      Tcpip_Recv(VPARAM Param);								/* IPパケット受信プロセス */


#ifdef __cplusplus
}
#endif


#endif	/* __HOS__Tcpip_local_h__ */


/* endof file */

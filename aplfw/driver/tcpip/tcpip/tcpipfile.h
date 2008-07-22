/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  tcpip.h
 * @brief %jp{TCP/IP プロトコル}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__tcpipfile_h__
#define __HOS__tcpipfile_h__


#include "tcpip.h"
#include "system/file/fileobj.h"
#include "library/container/streambuf/streambuf.h"


#define TCPIPFILE_TYPE_TCP		6
#define TCPIPFILE_TYPE_UDP		17

#define TCPIPFILE_RECV_BUFSIZE	2048


/* ファイルディスクリプタ */
typedef struct c_tcpipfile
{
	C_SYNCFILE			SyncFile;		/* 同期機能付きファイルオブジェクトを継承 */

	char				iType;
	unsigned char		ubIpAddr[4];
	unsigned short		uhPortNum;
	SYSEVT_HANDLE		hEvtRecv;
	
	struct c_tcpipfile	*pNext;
	struct c_tcpipfile	*pPrev;
	
	C_STREAMBUF			RecvBuf;
	unsigned char		ubRecvBuf[TCPIPFILE_RECV_BUFSIZE];
	unsigned char		ubSendBuf[TCPIPFILE_RECV_BUFSIZE];
	
} C_TCPIPFILE;



#ifdef __cplusplus
extern "C" {
#endif

HANDLE TcpIpFile_Create(C_TCPIP *pTcpIp, int iMode);
void   TcpIpFile_Delete(HANDLE hFile);


#ifdef __cplusplus
}
#endif


#endif	/* __HOS__tcpipfile_h__ */


/* end of file */

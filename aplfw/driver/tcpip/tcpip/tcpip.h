/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  tcpip.h
 * @brief %jp{TCP/IP プロトコル}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__tcpip_h__
#define __HOS__tcpip_h__


#include "system/sysapi/sysapi.h"
#include "system/file/syncdrv_local.h"



typedef struct t_tcpip_address
{
	unsigned char	ubAddress[4];
	unsigned short	uhPort;
} T_TCPIP_ADDRESS;



struct c_tcpipfile;

typedef struct c_tcpip
{
	C_SYNCDRV			SyncDrv;					/* キャラクタ型デバイスドライバを継承 */

	HANDLE				hIp;					/* IP層 */
	
	SYSMTX_HANDLE		hMtxLock;
	SYSMTX_HANDLE		hMtxSend;
	
	int					iOpenCount;				/* オープンカウンタ */

	SYSPRC_HANDLE		hPrcRecv;				/* 受信プロセス */
	
	struct c_tcpipfile	*pUdpHead;
	struct c_tcpipfile	*pTcpHead;
	
	unsigned short		uhPacketId;

	unsigned char		ubMyIpAddr[4];

/*	unsigned char		ubSendBuf[IPETHER_MAXPACKET_SIZE];	*/
	unsigned char		ubRecvBuf[2048];
	unsigned char		ubSendBuf[2048];
} C_TCPIP;




#ifdef __cplusplus
extern "C" {
#endif

HANDLE   TcpIp_Create(const char *pszIp);			/**< コンストラクタ */
void     TcpIp_Delete(HANDLE hDriver);				/**< デストラクタ */

FILE_ERR TcpIp_StringToAddr(T_TCPIP_ADDRESS *pAddr, const char *pszString);

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__ipether_h__ */


/* endof file */

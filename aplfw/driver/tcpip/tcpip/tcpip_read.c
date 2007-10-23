/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  tcpip.h
 * @brief %jp{TCP/IP プロトコル}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "tcpip_local.h"


/* IPパケット受信 */
FILE_SIZE TcpIp_Read(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, void *pBuf, FILE_SIZE Size)
{
	C_TCPIP		*self;
	C_TCPIPFILE	*pFile;
	int			iRecvSize;
	
	/* upper cast */
	self  = (C_TCPIP *)pDrvObj;
	pFile = (C_TCPIPFILE *)pFileObj;
	
	
	if ( pFile->iType == TCPIPFILE_TYPE_UDP )
	{
		unsigned short uhUdpSize;
		
		while ( StreamBuf_RefDataSize(&pFile->RecvBuf) < sizeof(uhUdpSize) + sizeof(T_TCPIP_ADDRESS) )
		{
			SysEvt_Wait(pFile->hEvtRecv);
		}
		
		StreamBuf_RecvData(&pFile->RecvBuf, &uhUdpSize, sizeof(uhUdpSize));
		StreamBuf_RecvData(&pFile->RecvBuf, pBuf, sizeof(T_TCPIP_ADDRESS) + (uhUdpSize - 8));
		
		iRecvSize = sizeof(T_TCPIP_ADDRESS) + (uhUdpSize - 8);
	}
	
	return iRecvSize;
}


/* endof file */

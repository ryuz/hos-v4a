/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  winsockdrv.h
 * @brief %jp{WinSockでシリアルを擬似するドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "winsockdrv_local.h"



DWORD WINAPI WinSockDrv_Recv(LPVOID Param)
{
	C_WINSOCKDRV		*self;
	WSADATA				wsaData;
	struct sockaddr_in	addr;
	struct sockaddr_in	client;
	int					len;
	unsigned char		ubBuf[128];
	int					iSize;

	self = (C_WINSOCKDRV *)Param;
	
	/* socket 準備 */
	WSAStartup(MAKEWORD(2,0), &wsaData);
	self->sock0 = socket(AF_INET, SOCK_STREAM, 0);
	addr.sin_family = AF_INET;
	addr.sin_port = htons((u_short)self->iPortNum);
	addr.sin_addr.S_un.S_addr = INADDR_ANY;
	bind(self->sock0, (struct sockaddr *)&addr, sizeof(addr));
	listen(self->sock0, 5);

	for ( ; ; )
	{
		/* 接続待ち */
		len = sizeof(client);
		self->sock = accept(self->sock0, (struct sockaddr *)&client, &len);
		if (self->sock == INVALID_SOCKET )
		{
			break;
		}
		
		/* 送信スレッド開始指示 */
		self->iConnection = TRUE;
		SetEvent(self->hConnectEvent);
		
		for ( ; ; )
		{
			/* 受信 */
			if ( (iSize = recv(self->sock, ubBuf, sizeof(ubBuf), 0)) == SOCKET_ERROR )
			{
				break;
			}
			
			/* 受信バッファに格納 */
			StreamBuf_SendData(&self->StmBufRecv, ubBuf, iSize);
			
			/* 擬似割込み生成 */
			vsig_int(self->iIntNum);
		}
		
		/* 送信スレッド停止指示 */
		self->iConnection = FALSE;
		SetEvent(self->hSendEvent);
		
		/* 送信スレッド停止待ち */
		WaitForSingleObject(self->hDisconnectEvent, INFINITE);

		/* 切断 */
		closesocket(self->sock);
	}
	
	WSACleanup();
	
	return 0;
}



/* end of file */




#include "winsockdrv.h"


/** コンストラクタ */
void WinSockDrv_Create(C_WINSOCKDRV *self, int iPortNum, int iIntNum, int iBufSize)
{
	WSADATA wsaData;
	struct sockaddr_in addr;

	WSAStartup(MAKEWORD(2,0), &wsaData);
	
	self->sock0 = socket(AF_INET, SOCK_STREAM, 0);
	
	addr.sin_family = AF_INET;
	addr.sin_port = htons((u_short)iPortNum);
	addr.sin_addr.S_un.S_addr = INADDR_ANY;
	
	bind(self->sock0, (struct sockaddr *)&addr, sizeof(addr));
	
	listen(self->sock0, 5);
}


/** デストラクタ */
void WinSockDrv_Delete(C_WINSOCKDRV *self)
{
	WSACleanup();
}


/** オープン */
void WinSockDrv_Open(C_WINSOCKDRV *self)
{
	struct sockaddr_in client;
	int len;

	if ( self->iOpenCount++ == 0 )
	{
		len = sizeof(client);
		self->sock = accept(self->sock0, (struct sockaddr *)&client, &len);
	}
}


/** クローズ */
void WinSockDrv_Close(C_WINSOCKDRV *self)
{
	closesocket(self->sock);
}


/** 読み出し */
int WinSockDrv_Read(C_WINSOCKDRV *self, void *pRecvBuf, int iSize)
{
	return recv(self->sock, pRecvBuf, iSize, 0);
}

/** 書き込み */
int WinSockDrv_Write(C_WINSOCKDRV *self, const void *pData, int iSize)
{
	return send(self->sock, pData, iSize, 0);
}



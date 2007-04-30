


#include "winsockdrv_local.h"


const T_DRVOBJ_METHODS  WinSockDrv_Methods = 
	{
		WinSockDrv_Open,
		WinSockDrv_Close,
		WinSockDrv_IoControl,
		WinSockDrv_Seek,
		WinSockDrv_Read,
		WinSockDrv_Write,
		WinSockDrv_Flush,
	};


/** コンストラクタ */
void WinSockDrv_Create(C_WINSOCKDRV *self, int iPortNum, int iIntNum, int iBufSize)
{
	WSADATA wsaData;
	struct sockaddr_in addr;
	
	/* 親クラス初期化 */
	DrvObj_Create(&self->DrvObj, &WinSockDrv_Methods);

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
HANDLE WinSockDrv_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode)
{
	C_WINSOCKDRV		*self;
	C_FILEOBJ			*pFileObj;
	struct sockaddr_in	client;
	int					len;

	/* upper cast */
	self = (C_WINSOCKDRV *)pDrvObj;

	/* create file descriptor */
	if ( (pFileObj = SysMem_Alloc(sizeof(*pFileObj))) == NULL )
	{
		return HANDLE_NULL;
	}
	FileObj_Create(pFileObj, pDrvObj, NULL);

	/* オープン処理 */
	if ( self->iOpenCount++ == 0 )
	{
		len = sizeof(client);
		self->sock = accept(self->sock0, (struct sockaddr *)&client, &len);
	}

	return (HANDLE)pFileObj;
}


/** クローズ */
FILE_ERR WinSockDrv_Close(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj)
{
	C_WINSOCKDRV *self;

	/* upper cast */
	self = (C_WINSOCKDRV *)pDrvObj;

	if ( --self->iOpenCount == 0 )
	{
		closesocket(self->sock);
	}

	return FILE_ERR_OK;
}


FILE_ERR  WinSockDrv_IoControl(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, int iFunc, const void *pInBuf, FILE_SIZE InSize, void *pOutBuf, FILE_SIZE OutSize)
{
	return FILE_ERR_NG;
}


FILE_POS  WinSockDrv_Seek(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, FILE_POS Offset, int iOrign)
{
	return FILE_ERR_NG;
}


/** 読み出し */
FILE_SIZE WinSockDrv_Read(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, void *pBuf, FILE_SIZE Size)
{
	C_WINSOCKDRV *self;

	/* upper cast */
	self = (C_WINSOCKDRV *)pDrvObj;

	return recv(self->sock, pBuf, Size, 0);
}


/** 書き込み */
FILE_SIZE WinSockDrv_Write(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size)
{
	C_WINSOCKDRV *self;

	/* upper cast */
	self = (C_WINSOCKDRV *)pDrvObj;

	return send(self->sock, pData, Size, 0);
}


FILE_ERR  WinSockDrv_Flush(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj)
{
	return FILE_ERR_OK;
}


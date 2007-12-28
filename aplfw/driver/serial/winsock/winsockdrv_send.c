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


/* 送信スレッド */
DWORD WINAPI WinSockDrv_Send(LPVOID Param)
{
	C_WINSOCKDRV	*self;
	unsigned char	ubBuf[128];
	int				iSize;

	self = (C_WINSOCKDRV *)Param;
	
	for ( ; ; )
	{
		/* 接続待ち */
		WaitForSingleObject(self->hConnectEvent, INFINITE);
		
		for ( ; ; )
		{
			/* 送信イベント待ち */
			WaitForSingleObject(self->hSendEvent, INFINITE);
			if ( self->iConnection != TRUE )
			{
				break;
			}

			/* 送信バッファから取り出し */
			while ( (iSize = StreamBuf_RecvData(&self->StmBufSend, ubBuf, sizeof(ubBuf))) > 0 )
			{
				/* 送信 */
				send(self->sock, ubBuf, iSize, 0);

				/* 擬似割込み生成 */
				vsig_int(self->iIntNum);
			}
		}
		
		/* 停止通知 */
		SetEvent(self->hDisconnectEvent);
	}
	
	return 0;
}



/* end of file */

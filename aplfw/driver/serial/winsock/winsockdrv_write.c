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


/** 書き込み */
FILE_SIZE WinSockDrv_Write(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size)
{
	C_WINSOCKDRV		*self;
	C_SYNCFILE			*pFile;
	const unsigned char	*pubData;
	FILE_ERR			ErrCode;
	FILE_SIZE			SendSize = 0;
	int					iLen;
	
	/* upper cast */
	self  = (C_WINSOCKDRV *)pDrvObj;
	pFile = (C_SYNCFILE *)pFileObj;
	
	pubData = (const unsigned char *)pData;
	
	/* 書込み処理開始 */
	if ( (ErrCode = SyncDrv_StartProcess(&self->SyncDrv, pFile, SYNCDRV_FACTOR_WRITE)) != FILE_ERR_OK )
	{
		return (FILE_SIZE)ErrCode;
	}

	/* 書込みシグナルを一旦クリア */
	SyncFile_ClearSignal(pFile, SYNCDRV_FACTOR_WRITE);
	
	while ( Size > 0 )
	{
		/* 送信可能かチェック */
		while ( (iLen = StreamBuf_SendData(&self->StmBufSend, pubData, Size)) <= 0 )
		{
			/* ブロッキングモードでなければ抜ける */
			if ( SyncFile_GetSyncMode(pFile, SYNCDRV_FACTOR_WRITE) != FILE_SYNCMODE_BLOCKING )
			{
				SyncDrv_EndProcess(&self->SyncDrv, SYNCDRV_FACTOR_WRITE, SendSize);
				return SendSize;
			}
			
			/* 書込みシグナルを待つ */
			SyncFile_WaitSignal(pFile, SYNCDRV_FACTOR_WRITE);
			
			/* 書込みシグナルをクリアしてリトライ */
			SyncFile_ClearSignal(pFile, SYNCDRV_FACTOR_WRITE);
		}

		/* 送信文字取り出し */
		pubData  += iLen;
		Size     -= iLen;
		SendSize += iLen;
		
		/* 送信 */
		SetEvent(self->hSendEvent);
	}
	
	/* 書込み処理完了 */
	SyncDrv_EndProcess(&self->SyncDrv, SYNCDRV_FACTOR_WRITE, (VPARAM)SendSize);
	
	return SendSize;
}


/* end of file */

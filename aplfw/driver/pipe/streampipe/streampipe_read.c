/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  streampipe.c
 * @brief %jp{ストリームパイプ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "streampipe_local.h"


/** %jp{読込み} */
FILE_SIZE StreamPipe_Read(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, void *pBuf, FILE_SIZE Size)
{
	C_STREAMPIPE	*self;
	C_SYNCFILE		*pFile;
	unsigned char	*pubBuf;
	FILE_ERR		ErrCode;
	FILE_SIZE		RecvSize;
	FILE_SIZE		ReadSize;
	
	/* upper cast */
	self  = (C_STREAMPIPE *)pDrvObj;
	pFile = (C_SYNCFILE *)pFileObj;
	
	pubBuf = (unsigned char *)pBuf;
	
	/* 読込み処理開始 */
	if ( (ErrCode = SyncDrv_StartProcess(&self->SyncDrv, pFile, SYNCDRV_FACTOR_READ)) != FILE_ERR_OK )
	{
		return (FILE_SIZE)ErrCode;
	}
	
	/* 読込みシグナルを一旦クリア */
	SyncFile_ClearSignal(pFile, SYNCDRV_FACTOR_READ);
	
	ReadSize = 0;
	while ( Size > 0 )
	{
		/* 読み出し */
		while ( (RecvSize = StreamBuf_RecvData(&self->StreamBuf, pubBuf, Size)) <= 0 )
		{
			/* ブロッキングモードでなければ抜ける */
			if ( SyncFile_GetSyncMode(pFile, SYNCDRV_FACTOR_READ) != FILE_SYNCMODE_BLOCKING )
			{
				SyncDrv_EndProcess(&self->SyncDrv, SYNCDRV_FACTOR_READ, (VPARAM)ReadSize);
				return ReadSize;
			}
			
			/* 受信を待つ */
			SyncFile_WaitSignal(pFile, SYNCDRV_FACTOR_READ);
			
			/* 読込みシグナルをクリアしてリトライ */
			SyncFile_ClearSignal(pFile, SYNCDRV_FACTOR_READ);
		}
		
		/* ポインタ更新 */
		pubBuf   += RecvSize;
		ReadSize += RecvSize;
		Size     -= RecvSize;
		
		/* 書読込みシグナル発行 */
		SyncDrv_SendSignal(&self->SyncDrv, SYNCDRV_FACTOR_WRITE);
	}
	
	/* 読み出し処理完了 */
	SyncDrv_EndProcess(&self->SyncDrv, SYNCDRV_FACTOR_READ, (VPARAM)ReadSize);
	
	return ReadSize;
}


/* end of file */

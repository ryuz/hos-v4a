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


/** %jp{書込み} */
FILE_SIZE StreamPipe_Write(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size)
{
	C_STREAMPIPE		*self;
	C_SYNCFILE			*pFile;
	const unsigned char	*pubData;
	FILE_ERR			ErrCode;
	FILE_SIZE			SendSize;
	FILE_SIZE			WriteSize;
		
	/* upper cast */
	self  = (C_STREAMPIPE *)pDrvObj;
	pFile = (C_SYNCFILE *)pFileObj;
	
	pubData = (const unsigned char *)pData;
	
	/* 書込み処理開始 */
	if ( (ErrCode = SyncDrv_StartProcess(&self->SyncDrv, pFile, SYNCDRV_FACTOR_WRITE)) != FILE_ERR_OK )
	{
		return (FILE_SIZE)ErrCode;
	}
	
	/* 書込みシグナルを一旦クリア */
	SyncFile_ClearSignal(pFile, SYNCDRV_FACTOR_WRITE);
	
	WriteSize = 0;
	while ( Size > 0 )
	{
		while ( (SendSize = StreamBuf_SendData(&self->StreamBuf, pubData, Size)) <= 0 )
		{
			/* ブロッキングモードでなければ抜ける */
			if ( SyncFile_GetSyncMode(pFile, SYNCDRV_FACTOR_WRITE) != FILE_SYNCMODE_BLOCKING )
			{
				SyncDrv_EndProcess(&self->SyncDrv, SYNCDRV_FACTOR_WRITE, (VPARAM)WriteSize);
				return WriteSize;
			}
			
			/* 書込みシグナルを待つ */
			SyncFile_WaitSignal(pFile, SYNCDRV_FACTOR_WRITE);
			
			/* 書込みシグナルをクリアしてリトライ */
			SyncFile_ClearSignal(pFile, SYNCDRV_FACTOR_WRITE);
		}
		
		/* ポインタ更新 */
		pubData   += SendSize;
		WriteSize += SendSize;
		Size      -= SendSize;
		
		/* 読込みシグナル発行 */
		SyncDrv_SendSignal(&self->SyncDrv, SYNCDRV_FACTOR_READ);
	}
	
	/* 書込み処理完了 */
	SyncDrv_EndProcess(&self->SyncDrv, SYNCDRV_FACTOR_WRITE, (VPARAM)WriteSize);
		
	return WriteSize;
}


/* end of file */

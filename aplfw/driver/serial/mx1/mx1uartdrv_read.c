/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  mx1uartdrv_read.c
 * @brief %jp{Freescale MX1 UART用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "mx1uartdrv_local.h"


/** %jp{受信} */
FILE_SIZE Mx1UartDrv_Read(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, void *pBuf, FILE_SIZE Size)
{
	C_MX1UARTDRV	*self;
	C_SYNCFILE		*pFile;
	unsigned char	*pubBuf;
	FILE_ERR		ErrCode;
	FILE_SIZE		i;
	int				c;
	
	/* upper cast */
	self  = (C_MX1UARTDRV *)pDrvObj;
	pFile = (C_SYNCFILE *)pFileObj;

	pubBuf = (unsigned char *)pBuf;

	/* 読込み処理開始 */
	if ( (ErrCode = SyncDrv_StartProcess(&self->SyncDrv, pFile, SYNCDRV_FACTOR_READ)) != FILE_ERR_OK )
	{
		return (FILE_SIZE)ErrCode;
	}
	
	/* 読込みシグナルを一旦クリア */
	SyncFile_ClearSignal(pFile, SYNCDRV_FACTOR_READ);
	
	for ( i = 0; i < Size; i++ )
	{
		/* 読み出し */
		while ( (c = StreamBuf_RecvChar(&self->StmBufRecv)) < 0 )
		{
			/* ブロッキングモードでなければ抜ける */
			if ( SyncFile_GetSyncMode(pFile, SYNCDRV_FACTOR_READ) != FILE_SYNCMODE_BLOCKING )
			{
				SyncDrv_EndProcess(&self->SyncDrv, SYNCDRV_FACTOR_READ, i);
				return i;
			}
			
			/* 受信を待つ */
			SyncFile_WaitSignal(pFile, SYNCDRV_FACTOR_READ);
			
			/* 読込みシグナルをクリアしてリトライ */
			SyncFile_ClearSignal(pFile, SYNCDRV_FACTOR_READ);
		}
		
		/* 読み出せた文字を格納 */	
		*pubBuf++ = (unsigned char)c;
	}
	
	/* 読み出し処理完了 */
	SyncDrv_EndProcess(&self->SyncDrv, SYNCDRV_FACTOR_READ, (VPARAM)i);
	
	return i;
}


/* end of file */

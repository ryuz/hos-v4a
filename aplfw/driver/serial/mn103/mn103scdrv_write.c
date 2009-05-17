/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  mn103scdrv_write.c
 * @brief %jp{MN103シリーズ シリアルインターフェース用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "mn103scdrv_local.h"


/** %jp{送信} */
FILE_SIZE Mn103ScDrv_Write(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size)
{
	C_MN103SCDRV		*self;
	C_SYNCFILE			*pFile;
	const unsigned char	*pubBuf;
	FILE_ERR			ErrCode;
	FILE_SIZE			i;
	int					c;
	
	/* upper cast */
	self  = (C_MN103SCDRV *)pDrvObj;
	pFile = (C_SYNCFILE *)pFileObj;
	
	pubBuf = (const unsigned char *)pData;
	
	/* 書込み処理開始 */
	if ( (ErrCode = SyncDrv_StartProcess(&self->SyncDrv, pFile, SYNCDRV_FACTOR_WRITE)) != FILE_ERR_OK )
	{
		return (FILE_SIZE)ErrCode;
	}

	/* 書込みシグナルを一旦クリア */
	SyncFile_ClearSignal(pFile, SYNCDRV_FACTOR_WRITE);
	
	for ( i = 0; i < Size; i++ )
	{
		/* 送信文字取り出し */
		c = *pubBuf++;
		
		/* 送信可能かチェック */
		while ( (MN103SC_READ_STR(self) & 0x80 ) )
		{
			/* 送信割込み許可 */
			SysInt_Enable(self->iIntNumTx);
			
			/* ブロッキングモードでなければ抜ける */
			if ( SyncFile_GetSyncMode(pFile, SYNCDRV_FACTOR_WRITE) != FILE_SYNCMODE_BLOCKING )
			{
				SyncDrv_EndProcess(&self->SyncDrv, SYNCDRV_FACTOR_WRITE, i);
				return i;
			}
			
			/* 書込みシグナルを待つ */
			SyncFile_WaitSignal(pFile, SYNCDRV_FACTOR_WRITE);
			
			/* 書込みシグナルをクリアしてリトライ */
			SyncFile_ClearSignal(pFile, SYNCDRV_FACTOR_WRITE);
		}
		
		/* 送信 */
		MN103SC_WRITE_TB(self, (unsigned char)c);
	}
	
	/* 書込み処理完了 */
	SyncDrv_EndProcess(&self->SyncDrv, SYNCDRV_FACTOR_WRITE, (VPARAM)i);
	
	return i;
}


/* end of file */

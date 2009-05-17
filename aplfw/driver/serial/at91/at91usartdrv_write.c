/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  at91usartdrv_write.c
 * @brief %jp{ATMEL AT91シリーズUSART用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "at91usartdrv_local.h"


/** %jp{送信} */
FILE_SIZE At91UsartDrv_Write(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size)
{
	C_AT91USARTDRV		*self;
	C_SYNCFILE			*pFile;
	const unsigned char	*pubData;
	FILE_ERR			ErrCode;
	FILE_SIZE			i;
	int					c;
	
	/* upper cast */
	self  = (C_AT91USARTDRV *)pDrvObj;
	pFile = (C_SYNCFILE *)pFileObj;
	
	pubData = (const unsigned char *)pData;
	
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
		c = *pubData++;
		
		/* 送信可能かチェック */
		while ( !(AT91USART_REG_READ(self, AT91USART_US_CSR) & 0x0002) )
		{
			/* 送信割込み許可 */
			AT91USART_REG_WRITE(self, AT91USART_US_IER, 0x00000002);
			
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
		AT91USART_REG_WRITE(self, AT91USART_US_THR, c);
	}
	
	/* 書込み処理完了 */
	SyncDrv_EndProcess(&self->SyncDrv, SYNCDRV_FACTOR_WRITE, (VPARAM)i);
	
	return i;
}


/* end of file */

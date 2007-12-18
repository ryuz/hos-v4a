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
	const unsigned char	*pubBuf;
	FILE_SIZE			i;
	int					c;
	
	/* upper cast */
	self  = (C_AT91USARTDRV *)pDrvObj;
	pFile = (C_SYNCFILE *)pFileObj;

	
	pubBuf = (const unsigned char *)pData;
	
	/* クリティカルセクションに入る */
	SysMtx_Lock(self->hMtxSend);


	/* 書込みシグナルを一旦クリア */
	SyncDrv_ClearWriteSignal(&self->SyncDrv);
	
	for ( i = 0; i < Size; i++ )
	{
		/* 送信文字取り出し */
		c = *pubBuf++;
		
		/* 送信可能かチェック */
		while ( !(AT91USART_REG_READ(self, AT91USART_US_CSR) & 0x0002) )
		{
			/* 送信割り込み許可 */
			AT91USART_REG_WRITE(self, AT91USART_US_IER, 0x00000002);
			
			/* 書込みシグナルを待つ */
			if ( SyncDrv_WaitWriteSignal(&self->SyncDrv, pFile) != FILE_ERR_OK )
			{
				SysMtx_Unlock(self->hMtxSend);	/* クリティカルセクションを出る */
				return i;
			}
			
			/* 書込みシグナルをクリアしてリトライ */
			SyncDrv_ClearWriteSignal(&self->SyncDrv);
		}
		
		/* 送信 */
		AT91USART_REG_WRITE(self, AT91USART_US_THR, c);
	}
	
	/* クリティカルセクションを出る */
	SysMtx_Unlock(self->hMtxSend);
	
	return i;
}


/* end of file */

/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  at91usartdrv_read.c
 * @brief %jp{ATMEL AT91シリーズUSART用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "at91usartdrv_local.h"


/** %jp{受信} */
FILE_SIZE At91UsartDrv_Read(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, void *pBuf, FILE_SIZE Size)
{
	C_AT91USARTDRV	*self;
	C_SYNCFILE		*pFile;
	unsigned char	*pubBuf;
	FILE_SIZE		i;
	int				c;
	
	/* upper cast */
	self  = (C_AT91USARTDRV *)pDrvObj;
	pFile = (C_SYNCFILE *)pFileObj;


	pubBuf = (unsigned char *)pBuf;

	/* クリティカルセクションに入る */
	SysMtx_Lock(self->hMtxRecv);

	/* 読込みシグナルを一旦クリア */
	SyncDrv_ClearReadSignal(&self->SyncDrv);
	
	for ( i = 0; i < Size; i++ )
	{
		/* 読み出し */
		while ( (c = StreamBuf_RecvChar(&self->StmBufRecv)) < 0 )
		{
			/* 受信を待つ */
			if ( SyncDrv_WaitReadSignal(&self->SyncDrv, pFile) != FILE_ERR_OK )
			{
				SysMtx_Unlock(self->hMtxRecv);	/* クリティカルセクションを出る */
				return i;
			}
			
			/* 読込みシグナルをクリアしてリトライ */
			SyncDrv_ClearReadSignal(&self->SyncDrv);
		}
		
		/* 読み出せた文字を格納 */	
		*pubBuf++ = (unsigned char)c;
	}
	
	/* クリティカルセクションを出る */
	SysMtx_Unlock(self->hMtxRecv);

	return i;
}


/* end of file */

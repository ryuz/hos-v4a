/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scidrv.c
 * @brief %jp{PC16550用デバイスドライバ}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "pc16550drv_local.h"


/** %jp{送信} */
FILE_SIZE Pc16550Drv_Write(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size)
{
	C_PC16550DRV		*self;
	C_SYNCFILE			*pFile;
	const unsigned char	*pubBuf;
	FILE_SIZE			i;
	int					c;
	
	/* upper cast */
	self  = (C_PC16550DRV *)pDrvObj;
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
		
		/* 送信 */
		while ( Pc16550Hal_SendChar(&self->Pc16550Hal, c) < 0 )
		{
			/* 送信割り込みを許可 */
			Pc16550Hal_EnableInterrupt(&self->Pc16550Hal, PC16550HAL_IER_ERBFI | PC16550HAL_IER_ETBEI);
			
			/* 書込みシグナルを待つ */
			if ( SyncDrv_WaitWriteSignal(&self->SyncDrv, pFile) != FILE_ERR_OK )
			{
				SysMtx_Unlock(self->hMtxSend);	/* クリティカルセクションを出る */
				return i;
			}
			
			/* 書込みシグナルをクリアしてリトライ */
			SyncDrv_ClearWriteSignal(&self->SyncDrv);
		}
	}
	
	/* クリティカルセクションを出る */
	SysMtx_Unlock(self->hMtxSend);

	return i;
}



/* end of file */

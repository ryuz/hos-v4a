/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scidrv.c
 * @brief %jp{LAN9000用デバイスドライバ}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "lan9000drv_local.h"


/** %jp{受信} */
FILE_SIZE Lan9000Drv_Read(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, void *pBuf, FILE_SIZE Size)
{
	C_LAN9000DRV	*self;
	C_SYNCFILE		*pFile;
	FILE_SIZE		RecvSize;
	FILE_ERR		ErrCode;
	unsigned short	uhStatus;
		
	/* upper cast */
	self  = (C_LAN9000DRV *)pDrvObj;
	pFile = (C_SYNCFILE *)pFileObj;
	
	/* 読込み処理開始 */
	if ( (ErrCode = SyncDrv_StartProcess(&self->SyncDrv, pFile, SYNCDRV_FACTOR_READ)) != FILE_ERR_OK )
	{
		return (FILE_SIZE)ErrCode;
	}
	
	/* 読込みシグナルを一旦クリア */
	SyncFile_ClearSignal(pFile, SYNCDRV_FACTOR_READ);
	
	for ( ; ; )
	{
		/* 受信 */
		SysMtx_Lock(self->hMtx);	/* クリティカルセクションに入る */
		RecvSize = Lan9000Hal_Recv(&self->Lan9000Hal, pBuf, Size);
		SysMtx_Unlock(self->hMtx);	/* クリティカルセクションを出る */
		
		/* 受信できれば抜ける */
		if ( RecvSize != 0 )
		{
			break;
		}

		/* 受信割込みを許可する */
		uhStatus = Lan9000Hal_GetInterruptStatus(&self->Lan9000Hal);
		Lan9000Hal_SetInterruptMask(&self->Lan9000Hal, (uhStatus | LAN9000HAL_IMASK_RCVINT));
		
		/* ブロッキングモードでなければ抜ける */
		if ( SyncFile_GetSyncMode(pFile, SYNCDRV_FACTOR_READ) != FILE_SYNCMODE_BLOCKING )
		{
			SyncDrv_EndProcess(&self->SyncDrv, SYNCDRV_FACTOR_READ, 0);
			return 0;
		}
				
		/* 受信を待つ */
		SyncFile_WaitSignal(pFile, SYNCDRV_FACTOR_READ);
			
		/* 読込みシグナルをクリアしてリトライ */
		SyncFile_ClearSignal(pFile, SYNCDRV_FACTOR_READ);
	}

	/* 読み出し処理完了 */
	SyncDrv_EndProcess(&self->SyncDrv, SYNCDRV_FACTOR_READ, (VPARAM)0);
	
	return RecvSize;
}


/* end of file */

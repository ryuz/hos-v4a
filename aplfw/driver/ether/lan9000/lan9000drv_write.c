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


/** %jp{送信} */
FILE_SIZE Lan9000Drv_Write(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size)
{
	C_LAN9000DRV	*self;
	C_SYNCFILE		*pFile;
	FILE_SIZE		SendSize;
	unsigned short	uhStatus;
	FILE_ERR		ErrCode;
	
	/* upper cast */
	self  = (C_LAN9000DRV *)pDrvObj;
	pFile = (C_SYNCFILE *)pFileObj;

	/* 書込み処理開始 */
	if ( (ErrCode = SyncDrv_StartProcess(&self->SyncDrv, pFile, SYNCDRV_FACTOR_WRITE)) != FILE_ERR_OK )
	{
		return (FILE_SIZE)ErrCode;
	}
	
	/* 書込みシグナルを一旦クリア */
	SyncFile_ClearSignal(pFile, SYNCDRV_FACTOR_WRITE);
	
	for ( ; ; )
	{
		/* 送信 */
		SysMtx_Lock(self->hMtx);		/* クリティカルセクションに入る */
		SendSize = Lan9000Hal_Send(&self->Lan9000Hal, pData, Size);
		SysMtx_Unlock(self->hMtx);		/* クリティカルセクションを出る */
		
		/* 成功なら抜ける */
		if ( SendSize != 0 )
		{
			break;
		}

		/* ブロッキングなら送信割込み許可 */
		uhStatus = Lan9000Hal_GetInterruptStatus(&self->Lan9000Hal);
		Lan9000Hal_SetInterruptMask(&self->Lan9000Hal, (uhStatus | LAN9000HAL_IMASK_ALLOCINT));

		/* ブロッキングモードでなければ抜ける */
		if ( SyncFile_GetSyncMode(pFile, SYNCDRV_FACTOR_WRITE) != FILE_SYNCMODE_BLOCKING )
		{
			SyncDrv_EndProcess(&self->SyncDrv, SYNCDRV_FACTOR_WRITE, 0);
			return 0;
		}
			
		/* 書込みシグナルを待つ */
		SyncFile_WaitSignal(pFile, SYNCDRV_FACTOR_WRITE);
			
		/* 書込みシグナルをクリアしてリトライ */
		SyncFile_ClearSignal(pFile, SYNCDRV_FACTOR_WRITE);
	}

	/* 書込み処理完了 */
	SyncDrv_EndProcess(&self->SyncDrv, SYNCDRV_FACTOR_WRITE, (VPARAM)0);

	return SendSize;
}



/* end of file */

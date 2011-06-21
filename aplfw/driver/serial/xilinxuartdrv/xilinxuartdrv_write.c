/** 
 * Hyper Operating System  Application Framework
 *
 * @file  xilinxuartdrv_write.c
 * @brief %jp{XILINX UART driver 書込み}%en{XILINX UART driver  write}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "xilinxuartdrv_local.h"


/** %jp{送信} */
FILE_SIZE XilinxUartDrv_Write(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size)
{
	C_XILINXUARTDRV		*self;
	C_SYNCFILE			*pFile;
	const unsigned char	*pubData;
	FILE_ERR			ErrCode;
	FILE_SIZE			i;
	int					c;
	
	/* upper cast */
	self  = (C_XILINXUARTDRV *)pDrvObj;
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
		while ( XILINXUARTDRV_REG_READ(self, XILINXUARTDRV_REG_STAT) & 0x08 )
		{
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
		
		/* 送信処理 */
		XILINXUARTDRV_REG_WRITE(self, XILINXUARTDRV_REG_TX, c);
	}
	
	/* 書込み処理完了 */
	SyncDrv_EndProcess(&self->SyncDrv, SYNCDRV_FACTOR_WRITE, (VPARAM)i);
	
	return i;
}


/* end of file */

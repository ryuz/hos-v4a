/** 
 * $PROJECT_NAME$
 *
 * @file  xxxxdrv_iocontrol.c
 * @brief %jp{$OBJNAME_JP$ I/O制御}%en{$OBJNAME_EN$  I/O control}
 *
 * $COPYRIGHT$
 */


#include "xxxxdrv_local.h"


FILE_ERR XxxxDrv_IoControl(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize)
{
	C_XXXXDRV		*self;
	C_XXXXFILE			*pFile;
	FILE_ERR			ErrCode;
	
	/* upper cast */
	self  = (C_XXXXDRV *)pDrvObj;
	pFile = (C_XXXXFILE *)pFileObj;

	switch ( iFunc )
	{
	case 1:
		{
			/* I/O処理開始 */
			if ( (ErrCode = SyncDrv_StartProcess(&self->SyncDrv, &pFile->SyncFile, SYNCDRV_FACTOR_IOCTL)) != FILE_ERR_OK )
			{
				return (FILE_SIZE)ErrCode;
			}

			/* シグナルを一旦クリア */
			SyncFile_ClearSignal(&pFile->SyncFile, SYNCDRV_FACTOR_IOCTL);
			
			/* 開始処理を書く */
			
			
			/* ブロッキングモードでなければ抜ける */
			if ( SyncFile_GetSyncMode(&pFile->SyncFile, SYNCDRV_FACTOR_IOCTL) != FILE_SYNCMODE_BLOCKING )
			{
				return FILE_ERR_BACKGROUND;		/* バックグラウンド継続 */
			}
			
			/* 完了シグナルを待つ */
			SyncFile_WaitSignal(&pFile->SyncFile, SYNCDRV_FACTOR_IOCTL);
			
			return SyncFile_GetErrCode(&pFile->SyncFile, SYNCDRV_FACTOR_IOCTL);
		}
	}
	
	
	return SyncDrv_IoControl(pDrvObj, pFileObj, iFunc, pInBuf, InSize, pOutBuf, OutSize);
}


/* end of file */

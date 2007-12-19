/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  syncfile.h
 * @brief %jp{同期機能付きデバイスドライバ用ファイルディスクリプタ}
 *
 * %jp{ファイルディスクリプタとして機能するクラス}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "syncdrv_local.h"


/* I/O制御 */
FILE_ERR SyncDrv_IoControl(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize)
{
	C_SYNCDRV	*self;
	C_SYNCFILE	*pFile;
	
	/* upper cast */
	self  = (C_SYNCDRV *)pDrvObj;
	pFile = (C_SYNCFILE *)pFileObj;

	switch ( iFunc )
	{
	case FILE_IOCTL_SET_WRITE_SYNCMODE:		/* 書込みの同期モードを設定 */
		if ( SyncDrv_GetSyncFactorNum(self) > SYNCDRV_FACTOR_WRITE )
		{
			SyncFile_SetSyncMode(pFile, SYNCDRV_FACTOR_WRITE, *(int *)pOutBuf);
			return FILE_ERR_OK;
		}
		break;

	case FILE_IOCTL_SET_READ_SYNCMODE:		/* 読込みの同期モードを設定 */
		if ( SyncDrv_GetSyncFactorNum(self) > SYNCDRV_FACTOR_READ )
		{
			SyncFile_SetSyncMode(pFile, SYNCDRV_FACTOR_READ, *(int *)pOutBuf);
			return FILE_ERR_OK;
		}
		break;

	case FILE_IOCTL_SET_IOCTL_SYNCMODE:		/* I/O制御の同期モードを設定 */
		if ( SyncDrv_GetSyncFactorNum(self) > SYNCDRV_FACTOR_IOCTL )
		{
			SyncFile_SetSyncMode(pFile, SYNCDRV_FACTOR_IOCTL, *(int *)pOutBuf);
			return FILE_ERR_OK;
		}
		break;


	case FILE_IOCTL_SET_WRITE_SYNCINF:		/* 書込みの同期情報を設定 */
		if ( SyncDrv_GetSyncFactorNum(self) > SYNCDRV_FACTOR_WRITE )
		{
			SyncFile_SetSyncInf(pFile, SYNCDRV_FACTOR_WRITE, *(T_FILE_SYNCINF *)pOutBuf);
			return FILE_ERR_OK;
		}
		break;

	case FILE_IOCTL_SET_READ_SYNCINF:		/* 読込みの同期情報を設定 */
		if ( SyncDrv_GetSyncFactorNum(self) > SYNCDRV_FACTOR_READ )
		{
			SyncFile_SetSyncInf(pFile, SYNCDRV_FACTOR_READ, *(T_FILE_SYNCINF *)pOutBuf);
			return FILE_ERR_OK;
		}
		break;

	case FILE_IOCTL_SET_IOCTL_SYNCINF:		/* I/O制御の同期情報を設定 */
		if ( SyncDrv_GetSyncFactorNum(self) > SYNCDRV_FACTOR_IOCTL )
		{
			SyncFile_SetSyncInf(pFile, SYNCDRV_FACTOR_IOCTL, *(T_FILE_SYNCINF *)pOutBuf);
			return FILE_ERR_OK;
		}
		break;
	}
	
	
	return FILE_ERR_NG;
}


/* end of file */

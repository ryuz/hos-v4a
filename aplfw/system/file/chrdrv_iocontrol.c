/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  chrfile.h
 * @brief %jp{キャラクタ型デバイスドライバ用ファイルディスクリプタ}
 *
 * %jp{ファイルディスクリプタとして機能するクラス}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "chrdrv.h"


/* I/O制御 */
FILE_ERR ChrDrv_IoControl(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize)
{
	C_CHRDRV	*self;
	C_CHRFILE	*pFile;
	
	/* upper cast */
	self  = (C_CHRDRV *)pDrvObj;
	pFile = (C_CHRFILE *)pFileObj;
	
	switch ( iFunc )
	{
	case FILE_IOCTL_SETWRITEMODE:		/* 書込みモードを設定 */
		pFile->cWriteMode = (char)(*(int *)pOutBuf);
		return FILE_ERR_OK;
		
	case FILE_IOCTL_SETREADEMODE:		/* 読込みモードを設定 */
		pFile->cReadMode = (char)(*(int *)pOutBuf);
		return FILE_ERR_OK;
		
	case FILE_IOCTL_SETWRITEVENT:		/* 書込みイベントを設定 */
		pFile->hEventWrite = (*(HANDLE *)pOutBuf);
		return FILE_ERR_OK;
		
	case FILE_IOCTL_SETREADEVENT:		/* 読込みイベントを設定 */	
		pFile->hEventRead = (*(HANDLE *)pOutBuf);
		return FILE_ERR_OK;
		
	}
	
	return FILE_ERR_NG;
}


/* end of file */

/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  ne2000drv.c
 * @brief %jp{NE2000互換Ether用デバイスドライバ}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "ne2000drv_local.h"



/* 仮想関数テーブル */
const T_DRVOBJ_METHODS Ne2000Drv_Methods = 
	{
		Ne2000Drv_Delete,
		Ne2000Drv_Open,
		Ne2000Drv_Close,
		Ne2000Drv_IoControl,
		Ne2000Drv_Seek,
		Ne2000Drv_Read,
		Ne2000Drv_Write,
		Ne2000Drv_Flush,
	};


/** コンストラクタ */
void Ne2000Drv_Create(C_NE2000DRV *self, void *pRegAddr, int iIntNum)
{
	/* 親クラスコンストラクタ呼び出し */
	SyncDrv_Create(&self->SyncDrv, &Ne2000Drv_Methods);

	/* メンバ変数初期化 */
	self->iOpenCount = 0;

	/* Ne2000Hal 初期化 */
	Ne2000Hal_Create(&self->Ne2000Hal, pRegAddr);

	/* イベント生成 */
	self->hEvtRecv = SysEvt_Create(SYSEVT_ATTR_AUTOCLEAR);
	self->hEvtSend = SysEvt_Create(SYSEVT_ATTR_AUTOCLEAR);

	/* ミューテックス生成 */
	self->hMtx = SysMtx_Create(SYSMTX_ATTR_NORMAL);

	/* 割込み処理登録 */
	SysIsr_Create(iIntNum, Ne2000Drv_Isr, (VPARAM)self);
}


/** デストラクタ */
void Ne2000Drv_Delete(C_DRVOBJ *pDrvObj)
{
	C_NE2000DRV *self;
	
	/* upper cast */
	self = (C_NE2000DRV *)pDrvObj;

	/* オブジェクト削除 */
	SysEvt_Delete(self->hEvtRecv);
	SysEvt_Delete(self->hEvtSend);
	SysMtx_Delete(self->hMtx);
	
	/* 親クラスデストラクタ */
	SyncDrv_Delete(&self->SyncDrv);
}


/** オープン */
HANDLE Ne2000Drv_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode)
{
	C_NE2000DRV *self;
	C_SYNCFILE	*pFile;
	
	/* upper cast */
	self = (C_NE2000DRV *)pDrvObj;

	/* create file descriptor */
	if ( (pFile = SysMem_Alloc(sizeof(C_SYNCFILE))) == NULL )
	{
		return HANDLE_NULL;
	}
	SyncFile_Create(pFile, &self->SyncDrv, NULL);
	
	
	/* オープン処理 */
	SysMtx_Lock(self->hMtx);
	if ( self->iOpenCount++ == 0 )
	{
		Ne2000Hal_Setup(&self->Ne2000Hal);
	}
	SysMtx_Unlock(self->hMtx);


	return (HANDLE)pFile;
}


/** クローズ */
void Ne2000Drv_Close(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj)
{
	C_NE2000DRV *self;
	C_SYNCFILE	*pFile;

	/* upper cast */
	self  = (C_NE2000DRV *)pDrvObj;
	pFile = (C_SYNCFILE *)pFileObj;
	
	SysMtx_Lock(self->hMtx);
	if ( --self->iOpenCount == 0 )
	{
		Ne2000Hal_Stop(&self->Ne2000Hal);
	}
	SysMtx_Unlock(self->hMtx);


	/* ディスクリプタ削除 */
	SyncFile_Delete((C_SYNCFILE *)pFile);	
	SysMem_Free(pFile);
}


/** %jp{受信} */
FILE_SIZE Ne2000Drv_Read(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, void *pBuf, FILE_SIZE Size)
{
	C_NE2000DRV 	*self;
	C_SYNCFILE		*pFile;
	unsigned char	*pubBuf;
	int				iRecvSize = 0;
	
	/* upper cast */
	self  = (C_NE2000DRV *)pDrvObj;
	pFile = (C_SYNCFILE *)pFileObj;

	/* バッファ */
	pubBuf = (unsigned char *)pBuf;

	for ( ; ; )
	{
		SysMtx_Lock(self->hMtx);
		iRecvSize = Ne2000Hal_Recv(&self->Ne2000Hal, pubBuf, Size);
		SysMtx_Unlock(self->hMtx);

		if ( iRecvSize > 0 )
		{
			break;
		}
		
		/* ブロッキングでなければ抜ける */
		if ( pFile->cReadMode != FILE_RMODE_BLOCKING )
		{
			break;
		}

		/* 受信イベントを待つ */
		SysEvt_Wait(self->hEvtRecv);
		SysEvt_Clear(self->hEvtRecv);
	}
	
	return iRecvSize;
}


/** %jp{送信} */
FILE_SIZE Ne2000Drv_Write(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size)
{
	C_NE2000DRV 	*self;
	C_SYNCFILE		*pFile;
	
	/* upper cast */
	self  = (C_NE2000DRV *)pDrvObj;
	pFile = (C_SYNCFILE *)pFileObj;

	SysMtx_Lock(self->hMtx);
	Size = Ne2000Hal_Send(&self->Ne2000Hal, pData, Size);
	SysMtx_Unlock(self->hMtx);
	
	return Size;
}


/* 割込み処理 */
void Ne2000Drv_Isr(VPARAM Param)
{
	C_NE2000DRV *self;

	self = (C_NE2000DRV *)Param;
}


/* end of file */

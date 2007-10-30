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


#include "hosaplfw.h"
#include "chrdrv.h"
#include "system/system/system.h"


static void ChrDrv_SetReadSignalProc(VPARAM Param);


/** 読込み可能になったことを通知 */
void ChrDrv_SetReadSignal(C_CHRDRV *self)
{
	if ( SysCtx_IsIsr() )
	{
		/* ISRからの呼び出しなら、システムプロセス経由で発動 */
		System_RequestProc(ChrDrv_SetReadSignalProc, (VPARAM)self);	
	}
	else
	{
		/* そうでなければ直接実行 */
		ChrDrv_SetReadSignalProc((VPARAM)self);
	}
}


/** 読込み可能になったことを通知 */
void ChrDrv_SetReadSignalProc(VPARAM Param)
{
	C_CHRDRV	*self;
	C_CHRFILE	*pFile;
	
	self = (C_CHRDRV *)Param;
	
	SysEvt_Set(self->hEvtRead);
		
	SysMtx_Lock(self->hMtx);
	
	pFile = self->pFileHead;
	if ( pFile != NULL )
	{
		do
		{
			/* イベントハンドルが登録されていたらセット */
			if ( pFile->hEventRead != HANDLE_NULL )
			{
				Event_Set(pFile->hEventRead);
			}
			
			/* 次に進む */
			pFile = pFile->pNext;
		} while ( pFile != self->pFileHead);
	}

	SysMtx_Unlock(self->hMtx);
}



/* end of file */

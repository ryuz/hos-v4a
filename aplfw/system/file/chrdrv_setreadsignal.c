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


/** 読込み可能になったことを通知 */
void ChrDrv_SetReadSignal(C_CHRDRV *self)
{
	C_CHRFILE *pFile;
	
	SysEvt_Set(self->hEvtRead);
	
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
}


/* end of file */

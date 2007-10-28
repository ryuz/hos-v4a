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
void ChrDrv_SetWriteSignal(C_CHRDRV *self)
{
	C_CHRFILE *pFile;
	
	SysEvt_Set(self->hEvtWrite);
	
	pFile = self->pFileHead;
	if ( pFile != NULL )
	{
		do
		{
			/* イベントハンドルが登録されていたらセット */
			if ( pFile->hEventWrite != HANDLE_NULL )
			{
				Event_Set(pFile->hEventWrite);
			}
			
			/* 次に進む */
			pFile = pFile->pNext;
		} while ( pFile != self->pFileHead);
	}
}


/* end of file */

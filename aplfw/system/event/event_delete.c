/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  event.h
 * @brief %jp{イベントオブジェクト}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "event_local.h"


/* デストラクタ */
void EventObj_Delete(HANDLE handle)
{
	C_EVENTOBJ *self;
	
	/* キャスト */
	self = (C_EVENTOBJ *)handle;
	
	/* 参照チェック */
	if ( TargetObj_GetRefCounter(&self->TargetObj) > 0 )
	{
		/* 参照者がいれば、削除フラグのみでリターン */
		TargetObj_SetDeleteFlag(&self->TargetObj);
		return;
	}

	/* イベント削除 */
	SysEvt_Delete(self->hSysEvt);
	
	/* 親クラスデストラクタ呼び出し */
	TargetObj_Destructor(&self->TargetObj);
	
	/* メモリ削除 */
	SysMem_Free(self);
}


/* end of file */

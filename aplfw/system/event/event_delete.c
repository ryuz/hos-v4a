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
void Event_Delete(HANDLE hEvent)
{
	C_EVENT *self;
	
	/* キャスト */
	self = (C_EVENT *)hEvent;
	
	/* イベント削除 */
	SysEvt_Delete(self->hSysEvt);
	
	/* 親クラスデストラクタ呼び出し */
	HandleObj_Destructor(&self->HandleObj);
	
	/* メモリ削除 */
	SysMem_Free(self);
}


/* end of file */

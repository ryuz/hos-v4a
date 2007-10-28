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


/* イベントセット */
EVENT_ERR Event_Set(HANDLE hEvent)
{
	C_EVENT *self;
	
	/* キャスト */
	self = (C_EVENT *)hEvent;
	
	/* イベントセット */
	SysEvt_Set(self->hSysEvt);
	
	return EVENT_ERR_OK;
}


/* end of file */

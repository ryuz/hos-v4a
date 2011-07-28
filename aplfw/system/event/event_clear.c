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


/* イベントクリア */
EVENT_ERR Event_Clear(HANDLE hEvent)
{
	C_EVENTOBJ	*pEventObj;
	
	/* オブジェクト取得 */
	pEventObj = EventPtr_GetEventObj(hEvent);
	
	/* イベント待ち */
	SysEvt_Clear(pEventObj->hSysEvt);
	
	return EVENT_ERR_OK;
}


/* end of file */

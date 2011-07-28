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


/* ハンドルの複製 */
HANDLE Event_DuplicateHandle(HANDLE hEvent)
{
	C_EVENTOBJ	*pEventObj;
	
	/* オブジェクト取得 */
	pEventObj = EventPtr_GetEventObj(hEvent);
	
	/* ポインタ生成 */
	return (HANDLE)PointerObj_Create(&EventPtr_Methods, (C_TARGETOBJ *)pEventObj);
}


/* end of file */

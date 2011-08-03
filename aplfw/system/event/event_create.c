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


/* イベント生成 */
HANDLE Event_Create(void)
{
	HANDLE	hEventObj;
	HANDLE	hEventPtr;
	
	/* 本体生成 */
	if ( (hEventObj = EventObj_Create()) == NULL )
	{
		return HANDLE_NULL;
	}
	
	/* ポインタ生成 */
	if ( (hEventPtr = PointerObj_Create(&EventPtr_Methods, (C_TARGETOBJ *)hEventObj)) == NULL )
	{
		EventObj_Delete(hEventObj);
		return HANDLE_NULL;
	}
	
	return (HANDLE)hEventPtr;
}


/* end of file */

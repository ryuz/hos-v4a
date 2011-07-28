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


/* 仮想関数テーブル */
const T_OBJECT_METHODS EventObj_Methods =
	{
		"EventObj",
		EventObj_Delete,
	};

const T_OBJECT_METHODS EventPtr_Methods =
	{
		"EventPtr",
		EventPtr_Delete,
	};


/* イベントオブジェクト生成 */
HANDLE EventObj_Create(void)
{
	C_EVENTOBJ *self;
	
	/* メモリ確保 */
	if ( (self = (C_EVENTOBJ *)SysMem_Alloc(sizeof(*self))) == NULL )
	{
		return NULL;
	}
	
	/* オブジェクト生成 */
	if ( (self->hSysEvt = SysEvt_Create(SYSEVT_ATTR_NORMAL)) == SYSEVT_HANDLE_NULL )
	{
		SysMem_Free(self);
	}
	
	/* 親クラスコンストラクタ呼び出し */
	TargetObj_Constructor(&self->TargetObj, &EventObj_Methods);
	
	return (HANDLE)self;
}


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

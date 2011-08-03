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
		NULL,
	};

const T_OBJECT_METHODS EventPtr_Methods =
	{
		"EventPtr",
		EventPtr_Delete,
		PointerObj_Duplicate,
	};


/* イベントオブジェクト生成 */
HANDLE EventObj_Create(void)
{
	C_EVENTOBJ *self;
	
	/* メモリ確保 */
	if ( (self = (C_EVENTOBJ *)SysMem_Alloc(sizeof(*self))) == NULL )
	{
		return HANDLE_NULL;
	}
	
	/* オブジェクト生成 */
	if ( (self->hSysEvt = SysEvt_Create(SYSEVT_ATTR_NORMAL)) == SYSEVT_HANDLE_NULL )
	{
		SysMem_Free(self);
		return HANDLE_NULL;
	}
	
	/* 親クラスコンストラクタ呼び出し */
	TargetObj_Constructor(&self->TargetObj, &EventObj_Methods);
	
	return (HANDLE)self;
}


/* end of file */

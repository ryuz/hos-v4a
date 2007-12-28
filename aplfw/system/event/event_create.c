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
static const T_HANDLEOBJ_METHODS Event_Methods =
	{
		Event_Delete
	};


HANDLE Event_Create(void)
{
	C_EVENT *self;

	/* メモリ確保 */
	if ( (self = SysMem_Alloc(sizeof(*self))) == NULL )
	{
		return HANDLE_NULL;
	}
	
	/* オブジェクト生成 */
	if ( (self->hSysEvt = SysEvt_Create(SYSEVT_ATTR_NORMAL)) == SYSEVT_HANDLE_NULL )
	{
		SysMem_Free(self);
	}
	
	/* 親クラスコンストラクタ呼び出し */
	HandleObj_Constructor(&self->HandleObj, &Event_Methods);
	
	return (HANDLE)self;
}



/* end of file */

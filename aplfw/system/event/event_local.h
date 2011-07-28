/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  event.h
 * @brief %jp{イベントオブジェクト}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#ifndef __HOS__event_local_h__
#define __HOS__event_local_h__


#include "event.h"
#include "system/handle/handle_local.h"
#include "system/sysapi/sysapi.h"


extern const T_OBJECT_METHODS EventObj_Methods;
extern const T_OBJECT_METHODS EventPtr_Methods;


/* イベントオブジェクトクラス定義 */
typedef struct c_eventobj
{
	C_TARGETOBJ		TargetObj;		/* 親クラスを継承 */

	SYSEVT_HANDLE	hSysEvt;		/* イベント */
} C_EVENTOBJ;



#ifdef __cplusplus
extern "C" {
#endif

/* イベントオブジェクト */
HANDLE  EventObj_Create(void);
void    EventObj_Delete(HANDLE handle);

/* イベントポインタクラス(PointerObjをそのまま継承) */
typedef C_POINTEROBJ					C_EVENTPTR;
#define EventPtr_Create(pEventObj)		PointerObj_Create(&EventObj_Methods, (C_TARGETOBJ *)(pEventObj));
#define EventPtr_Delete					PointerObj_Delete
#define EventPtr_GetEventObj(self)		((C_EVENTOBJ *)PointerObj_GetTargetObj(self))

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__event_local_h__ */


/* end of file */

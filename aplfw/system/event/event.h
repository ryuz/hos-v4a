/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  event.h
 * @brief %jp{イベントオブジェクト}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__event_h__
#define __HOS__event_h__


#include "system/handle/handle.h"


/* エラーコード定義 */
#define EVENT_ERR_OK			0
#define EVENT_ERR_NG			(-1)

/* エラー型 */
typedef int		EVENT_ERR;

#ifdef __cplusplus
extern "C" {
#endif

HANDLE    Event_Create(void);
void      Event_Delete(HANDLE hEvent);
EVENT_ERR Event_Set(HANDLE hEvent);
EVENT_ERR Event_Clear(HANDLE hEvent);
EVENT_ERR Event_Wait(HANDLE hEvent);
int       Event_RefStatus(HANDLE hEvent);

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__event_h__ */


/* end of file */

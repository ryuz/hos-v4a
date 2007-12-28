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
#include "system/handle/handleobj_local.h"
#include "system/sysapi/sysapi.h"


/* イベントオブジェクトクラス定義 */
typedef struct c_event
{
	C_HANDLEOBJ		HandleObj;		/* ハンドルオブジェクトを継承 */

	SYSEVT_HANDLE	hSysEvt;		/* イベント */
} C_EVENT;


#endif	/* __HOS__event_local_h__ */


/* end of file */

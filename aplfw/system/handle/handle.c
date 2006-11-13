/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  handle.h
 * @brief %jp{ハンドルオブジェクト}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include "handle.h"
#include "hdlobj.h"
#include "system/sysapi/sysapi.h"


/* ハンドルを閉じる */
void Handle_Close(HANDLE handle)
{
	if ( handle == HANDLE_NULL )
	{
		return;
	}

	/* デストラクタ呼び出し */
	HandleObj_Delete((C_HANDLEOBJ *)handle);
	
	/* メモリ開放 */
	SysMem_Free((void *)handle);
}



/* end of file */
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
#include "handleobj.h"
#include "system/sysapi/sysapi.h"


/* ハンドルを閉じる */
void Handle_Close(HANDLE handle)
{
	C_HANDLEOBJ *pHandleObj;
	
	/* 有効チェック */
	if ( handle == HANDLE_NULL )
	{
		return;
	}
	
	/* ハンドル変換 */
	pHandleObj = (C_HANDLEOBJ *)handle;

	/* クローズ処理 */
	if ( pHandleObj->pMethods->pfncClose != NULL )
	{
		pHandleObj->pMethods->pfncClose(handle);
	}
}


/* end of file */

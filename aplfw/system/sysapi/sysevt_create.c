/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  system.h
 * @brief %jp{システム用API定義}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "sysapi_local.h"



/* システム用イベント生成 */
SYSEVT_HANDLE SysEvt_Create(int iAttr)
{
	T_CFLG cflg;
	ER_ID  erid;

	/* ロック用セマフォ生成 */
	cflg.flgatr  = TA_TFIFO | ((iAttr & SYSEVT_ATTR_AUTOCLEAR) ? TA_CLR : 0);
	cflg.iflgptn = 0;
	erid = acre_flg(&cflg);
	if ( erid < 0 )
	{
		return SYSEVT_HANDLE_NULL;
	}

	return (SYSMTX_HANDLE)erid;
}



/* end of file */

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


/* システム用イベント待ち*/
void SysEvt_Wait(SYSEVT_HANDLE hEvt)
{
	wai_flg((ID)hEvt, 1, TWF_ANDW, NULL);
}


/* end of file */

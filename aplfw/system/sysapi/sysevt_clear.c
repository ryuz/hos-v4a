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
		
		
/* システム用イベントクリア */
void SysEvt_Clear(SYSEVT_HANDLE hEvt)
{
	clr_flg((ID)hEvt, 0);
}


/* end of file */

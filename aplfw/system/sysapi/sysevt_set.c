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


/* システム用イベントセット */
void SysEvt_Set(SYSEVT_HANDLE hEvt)
{
	if ( sns_ctx() )
	{
		iset_flg((ID)hEvt, 1);
	}
	else
	{
		set_flg((ID)hEvt, 1);
	}
}



/* end of file */

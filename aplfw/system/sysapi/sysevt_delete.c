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


/* システム用イベント削除 */
void SysEvt_Delete(SYSEVT_HANDLE hEvt)
{
	del_flg((ID)hEvt);
}


/* end of file */

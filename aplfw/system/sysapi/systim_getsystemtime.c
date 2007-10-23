/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  system.h
 * @brief %jp{・キ・ケ・ニ・猩ムAPIトチ}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "sysapi_local.h"


/* ・キ・ケ・ニ・狃込情*/
TIME SysTim_GetSystemTime(void)
{
	SYSTIM tim;
	get_tim(&tim);	
	return tim;
}


/* end of file */

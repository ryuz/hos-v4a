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


void SysInt_Clear(int iIntNum)
{
	vclr_int((INTNO)iIntNum);
}



/* end of file */

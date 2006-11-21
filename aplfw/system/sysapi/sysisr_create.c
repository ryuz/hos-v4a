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



SYSISR_HANDLE SysIsr_Create(int iIntNum, void (*pfncIsr)(VPARAM Param), VPARAM Param)
{
	T_CISR cisr;
	ER_ID  erid;

	cisr.isratr = TA_HLNG;
	cisr.exinf  = (VP_INT)Param;
	cisr.intno  = (INTNO)iIntNum;
	cisr.isr    = (FP)pfncIsr;
	erid = acre_isr(&cisr);
	if ( erid < 0 )
	{
		return SYSISR_HANDLE_NULL;
	}

	return (SYSISR_HANDLE)erid;
}


/* end of file */

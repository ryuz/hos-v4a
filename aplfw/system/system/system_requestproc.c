/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  system.h
 * @brief %jp{システム用API定義}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "hosaplfw.h"
#include "system/system/system_local.h"


/* システムプロセス */
int System_RequestProc(void (*pfncProc)(VPARAM Param), VPARAM Param)
{
	C_SYSTEM	*self;
	int			iTail;
	int			iNextTail;
	
	self = &g_System;
	
	iTail     = self->iProcTail;
	iNextTail = iTail + 1;
	if ( iNextTail >= SYSTEM_PROCQUE_SIZE )
	{
		iNextTail = 0;
	}
	
	/* バッファフルチェック */
	if ( iNextTail == self->iProcHead )
	{
		return 1;
	}
	
	/* キューに格納 */
	self->ProcQue[iTail].pfncProc = pfncProc;
	self->ProcQue[iTail].Param    = Param;
	
	self->iProcTail= iNextTail;
	
	/* イベント設定 */
	SysEvt_Set(self->hEvtProc);
	
	return 0;
}



/* end of file */

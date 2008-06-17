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
#include "system/sysapi/sysapi.h"


/* システムプロセス */
int System_RequestProc(void (*pfncProc)(VPARAM Param1, VPARAM Param2), VPARAM Param1, VPARAM Param2)
{
	C_SYSTEM	*self;
	int			iTail;
	int			iNextTail;
	
	self = &g_System;
	
	SysLoc_Lock();
	
	iTail     = self->iProcTail;
	iNextTail = iTail + 1;
	if ( iNextTail >= SYSTEM_PROCQUE_SIZE )
	{
		iNextTail = 0;
	}
	
	/* バッファフルチェック */
	if ( iNextTail == self->iProcHead )
	{
		SysLoc_Unlock();
		return 1;
	}
	
	/* キューに格納 */
	self->ProcQue[iTail].pfncProc = pfncProc;
	self->ProcQue[iTail].Param1   = Param1;
	self->ProcQue[iTail].Param2   = Param2;
	
	self->iProcTail= iNextTail;

	SysLoc_Unlock();
	
	/* イベント設定 */
	SysEvt_Set(self->hEvtProc);
	
	return 0;
}



/* end of file */

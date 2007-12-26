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
int System_Process(VPARAM Param)
{
	C_SYSTEM	*self;
	
	self = &g_System;
	
	for ( ; ; )
	{
		int	iHead;
		
		/* イベント待ち */
		SysEvt_Wait(self->hEvtProc);
		SysEvt_Clear(self->hEvtProc);
		
		/* プロシージャ実行 */
		for ( ; ; )
		{
			iHead = self->iProcHead;
			
			if ( iHead == self->iProcTail )
			{
				break;
			}
			
			self->ProcQue[iHead].pfncProc(self->ProcQue[iHead].Param1, self->ProcQue[iHead].Param2);
			
			iHead++;
			if ( iHead >= SYSTEM_PROCQUE_SIZE )
			{
				iHead = 0;
			}
			self->iProcHead = iHead;
		}
	}
}


/* end of file */

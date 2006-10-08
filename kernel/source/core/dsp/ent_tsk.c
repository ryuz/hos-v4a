/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  dsp_tsk.c
 * @brief %en{Task dispatch}%jp{タスクディスパッチ}
 *
 * @version $Id: ent_tsk.c,v 1.2 2006-10-08 05:30:35 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"



/** %jp{タスク起動時のエントリーポイント}%en{Task entry point}
 * @return void
 */
void _kernel_ent_tsk(VP_INT exinf1, VP_INT exinf2)
{
	_KERNEL_TSK_T_TASK task;

	task = (_KERNEL_TSK_T_TASK)exinf2;
	
	_KERNEL_LEAVE_SVC();

	task(exinf1);

	ext_tsk();
}


/* end of file */

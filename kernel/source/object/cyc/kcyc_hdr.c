/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  acre_cyc.c
 * @brief %en{Activate Task}%jp{タスクの起動}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/cycobj.h"


/** %jp{周期ハンドラ}%en{Cyclic Handler} */
void _kernel_cyc_hdr(_KERNEL_T_TIMOBJ *pk_timobj)
{
	_KERNEL_T_CYCCB_PTR cyccb;

	cyccb = (_KERNEL_T_CYCCB_PTR)pk_timobj;

}

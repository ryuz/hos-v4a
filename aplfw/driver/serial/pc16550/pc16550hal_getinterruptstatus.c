/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  pc16550hdl_create.c
 * @brief %jp{PC16550用ハードウェアアクセス層}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "pc16550hal_local.h"


/** %jp{割込み状態取得} */
int Pc16550Hal_GetInterruptStatus(C_PC16550HAL *self)
{
	return (PC16550HAL_READ_IIR(self) & 0x0f);
}



/* end of file */

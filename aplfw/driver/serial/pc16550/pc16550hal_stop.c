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


/* %jp{PC16550の停止} */
void Pc16550Hal_Stop(C_PC16550HAL *self)
{
	Pc16550Hal_EnableInterrupt(self, 0);
}


/* end of file */

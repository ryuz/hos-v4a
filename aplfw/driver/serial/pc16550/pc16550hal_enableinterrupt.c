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



/** %jp{割込み許可} */
void Pc16550Hal_EnableInterrupt(C_PC16550HAL *self, unsigned char flag)
{
	PC16550HAL_WRITE_IER(self, flag);
}



/* end of file */

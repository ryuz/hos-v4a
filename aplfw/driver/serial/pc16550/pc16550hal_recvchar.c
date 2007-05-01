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



/* %jp{1文字受信} */
int Pc16550Hal_RecvChar(C_PC16550HAL *self)
{
	if ( !(PC16550HAL_READ_LSR(self) & 0x01) )
	{
		return -1;
	}

	return PC16550HAL_READ_RBR(self);
}



/* end of file */

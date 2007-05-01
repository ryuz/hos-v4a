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


/* %jp{1文字送信} */
int Pc16550Hal_SendChar(C_PC16550HAL *self, int c)
{
	if ( PC16550HAL_READ_LSR(self) & 0x20  )	
	{
		self->iTxFree = PC16550HAL_TXFIFO_SIZE;
	}

	/* 送信可能かチェック */
	if ( self->iTxFree <= 0 )
	{
		return -1;
	}
	self->iTxFree--;
	
	PC16550HAL_WRITE_THR(self, c);

	return (unsigned char)c;
}


/* end of file */

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


/* %jp{BPS設定} */
void Pc16550Hal_SetSpeed(C_PC16550HAL *self, unsigned long ulSpeed)
{
	unsigned short uhDiv;

	uhDiv = (unsigned short)(((self->ulBaseClock / 16) + (ulSpeed / 2)) / ulSpeed);
	
	PC16550HAL_WRITE_LCR(self, PC16550HAL_READ_LCR(self) | 0x80);
	PC16550HAL_WRITE_DLL(self, uhDiv & 0xff);
	PC16550HAL_WRITE_DLM(self, uhDiv >> 8);
	PC16550HAL_WRITE_LCR(self, PC16550HAL_READ_LCR(self) & 0x7f);
}


/* end of file */

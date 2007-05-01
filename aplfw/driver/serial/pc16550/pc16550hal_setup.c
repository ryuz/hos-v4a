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


/** %jp{PC16550の初期化} */
void Pc16550Hal_Setup(C_PC16550HAL *self)
{
	self->iTxFree = PC16550HAL_TXFIFO_SIZE;
	PC16550HAL_WRITE_IER(self, 0x00);		/* 割込み全停止 */
	PC16550HAL_WRITE_LCR(self, 0x03);		/* 8bit,ノンパリ,ストップビット1bit*/
	PC16550HAL_WRITE_MCR(self, 0x03);		/* DTR/RTS ON */
	PC16550HAL_WRITE_FCR(self, 0xc1);		/* FIFO 有効化/トリガ14 */
	PC16550HAL_WRITE_FCR(self, 0xc7);		/* FIFO リセット */
}


/* end of file */

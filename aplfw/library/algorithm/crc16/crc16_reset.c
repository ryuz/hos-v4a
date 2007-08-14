/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  crc16.h
 * @brief %jp{16bit CRC 計算ライブラリ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "crc16_local.h"



void Crc16_Reset(C_CRC16 *self)
{
	self->uhCrc = 0;
}


/* end of file */

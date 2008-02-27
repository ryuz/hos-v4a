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


unsigned short Crc16_GetDigest(C_CRC16 *self)
{
	return self->uhCrc;
}


/* end of file */

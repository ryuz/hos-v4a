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


void Crc16_Update(C_CRC16 *self, const void *pData, unsigned int uiSize)
{
	const unsigned char	*pubData;
	unsigned int		i;
	
	pubData = (const unsigned char *)pData;
	
	for ( i = 0; i < uiSize; i++)
	{
		self->uhCrc = ((self->uhCrc << 8) ^ Crc16_uhTable[((self->uhCrc >> 8) ^ pubData[i]) & 0xff]);
	}
}


/* end of file */

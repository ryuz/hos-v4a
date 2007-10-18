/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  ipchecksum.h
 * @brief %jp{IPチェックサム計算ライブラリ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "ipchecksum_local.h"


void IpCheckSum_Update(C_IPCHECKSUM *self, const void *pData, unsigned int uiSize)
{
	unsigned char	*pubData;
	unsigned int	i;
	
	pubData = (unsigned char *)pData;
	for ( i = 0; i < uiSize / 2; i++ )
	{
		self->uwSum += (unsigned short)(pubData[i*2]*256 + pubData[i*2 + 1]);
	}
	
	if ( uiSize % 2 == 1 )
	{
		self->uwSum += (unsigned short)(pubData[i*2]*256 + 0);
	}
}


/* end of file */

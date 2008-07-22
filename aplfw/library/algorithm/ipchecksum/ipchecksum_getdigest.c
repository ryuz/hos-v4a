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


unsigned short IpCheckSum_GetDigest(C_IPCHECKSUM *self)
{
	unsigned long uwSum;
	
	uwSum = self->uwSum;

	uwSum  = (uwSum & 0xffff) + (uwSum >> 16);
	uwSum  = (uwSum & 0xffff) + (uwSum >> 16);
	
	return (unsigned short)~uwSum;
}


/* end of file */
